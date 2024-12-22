#include <iostream>
#include <string>
using namespace std;

class Assessment {
protected:
    float labAssessments[5] = {0}, labReports[5] = {0}, midterm = 0, cep = 0, finalTerm = 0;
public:
    virtual void inputMarks() = 0; // Pure virtual function
    virtual float calculateTotal() = 0;
};

class Student : public Assessment {
protected:
    string name, rollNumber;
    float totalMarks = 0, percentage = 0;
    char grade;
    float gpa;
public:
    void inputDetails() {
        cout << "Enter Name: ";
        cin >> name;
        cout << "Enter Roll Number: ";
        cin >> rollNumber;
    }

    void inputMarks() override {
        cout << "Enter marks out of 15 for Lab Assessments:" << endl;
        for (int i = 0; i < 5; ++i) {
            cout << "  Lab Assessment " << i + 1 << ": ";
            cin >> labAssessments[i];
            if (labAssessments[i] > 15) labAssessments[i] = 15; // Cap at 15
        }

        cout << "Enter marks out of 15 for Lab Reports:" << endl;
        for (int i = 0; i < 5; ++i) {
            cout << "  Lab Report " << i + 1 << ": ";
            cin >> labReports[i];
            if (labReports[i] > 15) labReports[i] = 15; // Cap at 15
        }

        cout << "Enter marks out of 10 for CEP: ";
        cin >> cep;
        if (cep > 10) cep = 10; // Cap at 10

        cout << "Enter marks out of 20 for Midterm: ";
        cin >> midterm;
        if (midterm > 20) midterm = 20; // Cap at 20

        cout << "Enter marks out of 20 for Final Term: ";
        cin >> finalTerm;
        if (finalTerm > 20) finalTerm = 20; // Cap at 20
    }

    float calculateTotal() override {
        float weights[] = {30, 25, 10, 15, 20}; // Total 100%
        float labAssessmentTotal = 0, labReportTotal = 0;

        for (int i = 0; i < 5; ++i) {
            labAssessmentTotal += labAssessments[i];
            labReportTotal += labReports[i];
        }

        totalMarks = (labAssessmentTotal / 75) * weights[0] +
                     (labReportTotal / 75) * weights[1] +
                     (cep / 10) * weights[2] +
                     (midterm / 20) * weights[3] +
                     (finalTerm / 20) * weights[4];

        percentage = totalMarks;
        grade = calculateLetterGrade();
        gpa = calculateGPA();
        return totalMarks;
    }

    char calculateLetterGrade() {
        if (percentage >= 90) return 'A';
        else if (percentage >= 80) return 'B';
        else if (percentage >= 70) return 'C';
        else if (percentage >= 60) return 'D';
        return 'F';
    }

    float calculateGPA() {
        if (percentage >= 90) return 4.0;
        else if (percentage >= 80) return 3.5;
        else if (percentage >= 70) return 3.0;
        else if (percentage >= 60) return 2.5;
        else if (percentage >= 50) return 2.0;
        return 0.0;
    }

    friend ostream& operator<<(ostream& out, const Student& student) {
        out << "Name: " << student.name
            << ", Roll Number: " << student.rollNumber
            << ", Total Marks: " << student.totalMarks
            << ", Percentage: " << student.percentage
            << "%, Grade: " << student.grade
            << ", GPA: " << student.gpa << endl;
        return out;
    }
};

class Class : public Student {
private:
    string className;
    Student students[5];
    int studentCount;
public:
    void inputClassDetails() {
        cout << "Enter Class Name: ";
        cin.ignore();
        getline(cin, className);
    }

    void inputStudentDetails() {
        cout << "Enter number of students (max 5): ";
        cin >> studentCount;
        if (studentCount < 1 || studentCount > 5) {
            cout << "Invalid number of students!" << endl;
            return;
        }

        for (int i = 0; i < studentCount; ++i) {
            cout << "\nEntering details for student " << i + 1 << ":" << endl;
            students[i].inputDetails();
            students[i].inputMarks();
            students[i].calculateTotal();
        }
    }

    void displayResults() {
        cout << "\nClass: " << className << "\nResults:\n";
        for (int i = 0; i < studentCount; ++i) {
            cout << students[i];
        }
    }
};

int main() {
    Class selectedClass;
    selectedClass.inputClassDetails();
    selectedClass.inputStudentDetails();
    selectedClass.displayResults();
    return 0;
}

