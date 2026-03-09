pipeline {
    agent any
    stages {
        stage('Compile') {
            steps {
                sh '/usr/bin/gcc "sort.c" -o "sort"'
            }
            
    }
        stage('Run') {
            steps {
                sh '"./sort"'
            }
        }
    }
}
