pipeline {
    agent any

    stages {
        stage('Compile') {
            steps {
                sh '/usr/bin/gcc -Wall -Wextra -Wpedantic -o sort sort.c'
            }
        }

        stage('Static Analysis') {
            stages {   // używamy stages w środku, żeby zachować kolejność
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

                stage('Cppcheck MISRA') {
                    steps {
                        sh 'cppcheck --addon=misra.json --enable=style sort.c 2> misra.log || true'
                    }
                }

                stage('GCC Warnings') {
                    steps {
                        sh '/usr/bin/gcc -Wall -Wextra -Wpedantic -o sort sort.c 2> gcc.log || true'
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

    post {   // <-- post zawsze na poziomie pipeline
        always {
            archiveArtifacts artifacts: '*.log', allowEmptyArchive: true

            cleanWs()
        }
    }
}