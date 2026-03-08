pipeline {
    agent any
    stages {
        stage('Compile') {
        sh 'gcc "sort.c" -o "sort"'
    }
        stage('Run') {
        sh '"./sort"'
        }
    }
}
