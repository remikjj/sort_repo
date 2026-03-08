pipeline {
    agent any
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
