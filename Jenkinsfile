pipeline {
    agent any
    environment {
        PATH = "/usr/bin:/bin:${env.PATH}"
    }
    stages {
        stage('Compile') {
            steps {
                sh 'gcc "sort.c" -o "sort"'
            }
            
    }
        stage('Run') {
            steps {
                sh '"./sort"'
            }
        }
    }
}
