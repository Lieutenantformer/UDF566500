#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

const int NUM_STUDENTS = 20;

//struct definition
struct studentType {
    string studentFName;
    string studentLName;
    int testScore;
    char grade;
    };

//membaca data siswa
void readData(studentType students[], int size){
    for (int j=0; j < size; j++) {
        cout << "Masukkan nama depan, nama belakang, dan nilai siswa ke-" << j + 1 << ": ";
        cin >> students[j].studentFName >> students[j].studentLName >> students[j].testScore;
    }
}

// memberikan grade berdasarkan nilai
void assignGrades(studentType students[], int size) {
    for (int j = 0; j < size; j++){
        int scores = students[j].testScore;
        if (scores >= 90)
            students[j].grade = 'A';
        else if (scores >= 80)
            students[j].grade = 'B';
        else if (scores >= 70)
            students[j].grade = 'c';
        else if (scores >= 60)
            students[j].grade = 'D';
        else
            students[j].grade = 'F';
    }
}

//menemukan nilai tertinggi
int highestScore(studentType students[], int size){
    int maxScore = students[0].testScore;
    for (int j = 1; j < size; j++) {
        if (students[j].testScore > maxScore)
            maxScore = students[j].testScore;
    }
    return maxScore;
}

//menampilkan siswa dengan nilai tertinggi

void printHighestScorers(studentType students[], int size, int maxScore){
    cout << "\nSiswa dengan nilai tertinggi (" << maxScore << "):" << endl;
    for (int j = 0; j < size; j++){
        if (students[j].testScore == maxScore) {
            cout << students[j].studentLName << ", " << students[j].studentFName << endl;
        }
    }
}

//menampilkasn semua data

void printAll(studentType students[], int size) {
    cout << left << setw(15) << "Nama Belakang"
        << setw(15) << "Nama Depan"
        << setw(10) << "Nilai"
        << "Grade" << endl;
    cout << "----------------------------------------------" << endl;

    for (int j = 0; j < size; j++) {
        cout << left << setw(15) << students[j].studentLName
            << setw(15) << students[j].studentFName
            << setw(10) << students[j].testScore
            << students[j].grade << endl;
    }
}

int main(){
    studentType students[NUM_STUDENTS];
    int maxScore;

    cout << "=== INPUT DATA SISWA ===" << endl;
    readData(students, NUM_STUDENTS);

    assignGrades(students, NUM_STUDENTS);

    maxScore = highestScore(students, NUM_STUDENTS);

    cout << "\n=== DAFTAR NILAI SISWA ===" << endl;
    printAll(students, NUM_STUDENTS);

    printHighestScorers(students, NUM_STUDENTS, maxScore);

    return 0;

    }
