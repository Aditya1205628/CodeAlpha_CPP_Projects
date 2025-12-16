#include <iostream>
#include <iomanip>
#include "cgpa.h"

using namespace std;

void cgpaCalculator() {
    int courses;
    float grade, credit;
    float totalCredits = 0.0;
    float totalGradePoints = 0.0;

    cout << "\n=== CGPA Calculator ===\n";
    cout << "Enter number of courses taken: ";
    cin >> courses;

    cout << "\n--- Enter Course Details ---\n";

    for (int i = 1; i <= courses; i++) {
        cout << "\nCourse " << i << endl;
        cout << "Grade Point (out of 10): ";
        cin >> grade;
        cout << "Credit Hours: ";
        cin >> credit;

        totalCredits += credit;
        totalGradePoints += grade * credit;

        cout << "Grade Points for Course " << i << ": "
             << grade * credit << endl;
    }

    if (totalCredits == 0) {
        cout << "\nError: Total credits cannot be zero.\n";
        return;
    }

    float semesterGPA = totalGradePoints / totalCredits;
    float cgpa = semesterGPA;   // Single semester → CGPA

    cout << fixed << setprecision(2);
    cout << "\n============================\n";
    cout << "Total Credits       : " << totalCredits << endl;
    cout << "Total Grade Points  : " << totalGradePoints << endl;
    cout << "Semester GPA        : " << semesterGPA << endl;
    cout << "Overall CGPA        : " << cgpa << endl;
    cout << "============================\n";
}
