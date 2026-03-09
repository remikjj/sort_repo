pipeline {
    agent any
    environment {
        PATH = "/usr/bin:/bin:/usr/local/bin:${env.PATH}"
    }
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
