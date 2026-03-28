pipeline {
    agent any

    stages {
        stage('Compile') {
            steps {
                sh '/usr/bin/gcc -Wall -Wextra -Wpedantic -o sort sort.c'
            }
        }

        stage('Static Analysis') {
            stages {   
                stage('Cppcheck') {
                    steps {
                        sh 'cppcheck --enable=all --inconclusive --std=c11 sort.c 2> cppcheck.log'
                    }
                }

                stage('Clang Analysis') {
                    steps {
                        sh 'clang --analyze sort.c -Xanalyzer -analyzer-output=text 2> clang.log'
                    }
                }

                stage('Splint') {
                    steps {
                        sh 'splint sort.c 2> splint.log'
                    }
                }

                stage('Cppcheck MISRA') {
                    steps {
                        sh 'cppcheck --addon=misra.json --enable=style sort.c 2> misra.log'
                    }
                }

                stage('GCC Warnings') {
                    steps {
                        sh '/usr/bin/gcc -Wall -Wextra -Wpedantic -o sort sort.c 2> gcc.log'
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