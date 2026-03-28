pipeline {
    agent any

    stages {
        // Nowy etap: Czyszczenie przestrzeni roboczej przed rozpoczęciem pracy
        stage('Clean Workspace') {
            steps {
                cleanWs() 
                // UWAGA: Jeśli wyskoczy błąd, że nie znaleziono polecenia 'cleanWs', 
                // użyj wbudowanego polecenia Jenkinsa: deleteDir()
            }
        }

        stage('Compile') {
            steps {
                sh '/usr/bin/gcc -Wall -Wextra -Wpedantic -o sort sort.c'
            }
        }

        stage('Static Analysis') {
            stages {   
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
                        sh 'cppcheck --addon=misra.json --enable=style sort.c 2> cppcheck_misra.log || true'
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
            archiveArtifacts artifacts: '*.log', allowEmptyArchive: true
        }
    }
}