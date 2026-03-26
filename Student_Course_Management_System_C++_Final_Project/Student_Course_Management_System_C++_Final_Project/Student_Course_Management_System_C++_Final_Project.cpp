#include <iostream>

#include "Student.h"

#include <vector>
#include <algorithm>

using namespace std;

// General Variables

vector<Student> students;

// General functions

void welcomeMessage()
{
	cout << "|===============================================================|" << endl;
    cout << "|\tWelcome to the Student Course Management System!\t|" << endl;
    cout << "|===============================================================|" << endl;
}

void displayMenu()
{
    cout << "Student Course Management System" << endl;
    cout << "1. Add Student." << endl;
    cout << "2. Remove Student." << endl;
    cout << "3. Search Student." << endl;
    cout << "4. Display All Students." << endl;
    cout << "5. Enroll Student in Course." << endl;
    cout << "6. Show Student Courses." << endl;
    cout << "7. Sort Students by GPA." << endl;
    cout << "8. Exit" << endl;
}

void addStudent() {
    int id;
	string name;
    double gpa;

	cout << "Enter Student ID: ";
	cin >> id;

    for (Student& student : students) {
        if (student.getID() == id) {
			cout << "Student with this ID already exists. Please try again." << endl;
            return;
        }
    }

    cin.ignore();

	cout << "Enter Student Name: ";
    getline(cin, name);

	cout << "Enter Student GPA: ";
	cin >> gpa;

	students.push_back(Student(id, name, gpa));
}

void removeStudent() {
    int id;
    cout << "Enter Student ID to remove: ";
    cin >> id;
    for (auto it = students.begin(); it != students.end(); it++) {
        if(it->getID() == id) {
            students.erase(it);
            cout << "Student removed successfully." << endl;
            return;
        }
    }

    cout << "Student not found." << endl;
}

void searchStudent() {
    int id;
    cout << "Enter Student ID to search: ";
    cin >> id;

    if (students.empty()) {
        cout << "No students in the system." << endl;
        return;
    }

    for (Student& student : students) {
        if (student.getID() == id) {
            cout << "ID: " << student.getID() << "\tName: " << student.getName() << "\tGPA: " << student.getGPA() << endl;

            if (student.getCourses().empty()) {
                cout << "No courses enrolled." << endl;
            }
            else {
                cout << "Enrolled Courses:" << endl;
                for (Course& course : student.getCourses()) {
                    cout << "Course ID: " << course.getID() << "\tCourse Name: " << course.getName()
                        << "\tCredits: " << course.getCredits() << "\tGrade: " << course.getGrade() << endl;
                }
            }
            return;
        }
    }

    cout << "Student with ID " << id << " not found." << endl;
}

void displayAllStudents() {
    if (students.empty()) {
        cout << "No students to display." << endl;
        return;
    }

    for (Student& student : students) {
        cout << "ID: " << student.getID() << "\tName: " << student.getName() << "\tGPA: " << student.getGPA() << endl;

		if (student.getCourses().empty()) {
            cout << "No courses enrolled." << endl;
        } else {
            cout << "Enrolled Courses:" << endl;
            for (Course& course : student.getCourses()) {
                cout << "Course ID: " << course.getID() << "\tCourse Name: " << course.getName() << "\tCredits: " << course.getCredits() << "\tGrade: " << course.getGrade() << endl;
            }
        }
    }
}

void enrollStudentInCourse() {
    int id;
	cout << "Enter Student ID to enroll in course: ";
	cin >> id;

    for (Student& student : students) {
        if (student.getID() == id) {
			int courseId;
			string courseName;
			int credits;
			double grade;

			cout << "Enter Course ID: ";
			cin >> courseId;

			cin.ignore();

			cout << "Enter Course Name: ";
			getline(cin, courseName);
			cout << "Enter Course Credits: ";
			cin >> credits;
			cout << "Enter Course Grade: ";
			cin >> grade;

			student.enrollInCourse(Course(courseId, courseName, credits, grade));
            return;
        }
    }
    
	cout << "Student withthis ID not found." << endl;
}

void showStudentCourses() {
    if (students.empty()) {
        cout << "No students in the system." << endl;
        return;
    }
    else {
        int id;
        cout << "Enter Student ID to show courses: ";
        cin >> id;

		for (Student& student : students) {
            if(student.getID() == id) {
                if (student.getCourses().empty()) {
                    cout << "No courses enrolled." << endl;
                }
                else {
                    cout << "Enrolled Courses:" << endl;
                    for (Course& course : student.getCourses()) {
                        cout << "Course ID: " << course.getID() << "\tCourse Name: " << course.getName() << "\tCredits: " << course.getCredits() << "\tGrade: " << course.getGrade() << endl;
                    }
                }
                return;
            }
        }
    }

    cout << "Student with this ID not found." << endl;
}

void sortStudentsByGPA() {
    if (students.empty()) {
        cout << "No students to sort." << endl;
        return;
    }

    sort(students.begin(), students.end(), [/* By value */](Student& a, Student& b) {
            return a.getGPA() > b.getGPA();
        }
    );

    for (Student& student : students) {
        cout << "ID: " << student.getID() << "\tName: " << student.getName() << "\tGPA: " << student.getGPA() << endl;

		if (student.getCourses().empty()) {
            cout << "No courses enrolled." << endl;
        }
        else {
            cout << "Enrolled Courses:" << endl;
            for (Course& course : student.getCourses()) {
                cout << "Course ID: " << course.getID() << "\tCourse Name: " << course.getName() << "\tCredits: " << course.getCredits() << "\tGrade: " << course.getGrade() << endl;
            }
        }
    }
}

void swichCase()
{
    int choice;
    cout << "Enter your choice: ";
    cin >> choice;
    switch (choice)
    {
        case 1:
            // Add Student
			addStudent();

            break;
        case 2:
            // Remove Student
			removeStudent();

            break;
        case 3:
            // Search Student
			searchStudent();

            break;
        case 4:
            // Display All Students
			displayAllStudents();

            break;
        case 5:
            // Enroll Student in Course
			enrollStudentInCourse();

            break;
        case 6:
            // Show Student Courses
			showStudentCourses();

            break;
        case 7:
            // Sort Students by GPA
			sortStudentsByGPA();

            break;
        case 8:
            cout << "Exiting the program. Goodbye!" << endl;
            exit(0);
        default:
            cout << "Invalid choice. Please try again." << endl;
    }
}

void loopMenu()
{
    while (true) {
        displayMenu();
        swichCase();
    }
}

int main()
{
	welcomeMessage();

	loopMenu();

    return 0;
}