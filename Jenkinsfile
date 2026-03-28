pipeline {
    agent any
    stages {
        stage('Compile') {
            steps {
                // kompilacja z GCC, standardowe warningi
                sh '/usr/bin/gcc -Wall -Wextra -Wpedantic "sort.c" -o "sort"'
            }
        }

        stage('Static Analysis') {
            parallel {
                stage('Cppcheck') {
                    steps {
                        sh 'cppcheck --enable=all --inconclusive --std=c11 sort.c 2> cppcheck.log || true'
                    }
                }
                stage('Clang Analysis') {
                    steps {
                        sh 'clang --analyze sort.c -Xanalyzer -analyzer-output=text 2> clang.log || true'
                    }
                }
                stage('Splint') {
                    steps {
                        sh 'splint sort.c 2> splint.log || true'
                    }
                }
                stage('GCC Warnings') {
                    steps {
                        sh '/usr/bin/gcc -Wall -Wextra -Wpedantic -o sort sort.c 2> gcc_warnings.log || true'
                    }
                }
            }
        }

        stage('Run') {
            steps {
                sh './sort'
            }
        }
    }

    post {
        always {
            // zachowaj logi wszystkich linterów jako artefakty
            archiveArtifacts artifacts: '*.log', allowEmptyArchive: true
        }
    }
}
