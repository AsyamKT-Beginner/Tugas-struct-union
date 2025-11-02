#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

const int CLASS_SIZE = 20;

struct studentType {
    string studentFName;
    string studentLName;
    int testScore;
    char grade;
};

void readData(studentType arr[], int n) {
    for (int i = 0; i < n; ++i) {
        cout << "Enter student " << (i+1) << " first_name last_name testScore: ";
        cin >> arr[i].studentFName >> arr[i].studentLName >> arr[i].testScore;
    }
}

void assignGrades(studentType arr[], int n) {
    for (int i = 0; i < n; ++i) {
        int s = arr[i].testScore;
        if (s >= 90) arr[i].grade = 'A';
        else if (s >= 80) arr[i].grade = 'B';
        else if (s >= 70) arr[i].grade = 'C';
        else if (s >= 60) arr[i].grade = 'D';
        else arr[i].grade = 'F';
    }
}

int findHighestScore(studentType arr[], int n) {
    int hi = -1;
    for (int i = 0; i < n; ++i) {
        if (arr[i].testScore > hi) hi = arr[i].testScore;
    }
    return hi;
}

void printHighestNames(studentType arr[], int n, int highest) {
    cout << "========================================\n";
    cout << "Student(s) with the highest score (" << highest << "):" << '\n';
    for (int i = 0; i < n; ++i) {
        if (arr[i].testScore == highest) {
            cout << left << setw(20) << (arr[i].studentLName + ", " + arr[i].studentFName) << '\n';
        }
    }
}

void printAllStudents(studentType arr[], int n) {
    cout << "\nAll students (Last, First)    Score  Grade\n";
    cout << "========================================\n";
    for (int i = 0; i < n; ++i) {
        string name = arr[i].studentLName + ", " + arr[i].studentFName;
        cout << left << setw(28) << name 
             << right << setw(5) << arr[i].testScore 
             << setw(8) << arr[i].grade << '\n';
    }
}

int main() {
    studentType classList[CLASS_SIZE];
    readData(classList, CLASS_SIZE);
    assignGrades(classList, CLASS_SIZE);
    printAllStudents(classList, CLASS_SIZE);
    int highest = findHighestScore(classList, CLASS_SIZE);
    printHighestNames(classList, CLASS_SIZE, highest);
    return 0;
}

