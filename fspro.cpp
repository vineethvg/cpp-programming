#include <iostream>
#include <fstream>
#include <string>
using namespace std;
int ID;
struct Student
{
    int id;
    string name;
    int course;
    string phno;
    string loc;
};

void addStudent()
{
    Student student;
    cout << "\n";
    cout << "\n\tEnter student name : ";
    cin.get();
    getline(cin, student.name);
    cout << "\n\tEnter student course : ";
    cin >> student.course;
    cout << "\n\tEnter student Ph. No : ";
    cin >> student.phno;
    cout << "\n\tEnter student location : ";
    cin >> student.loc;
    cout << "\n";
    ID++;

    ofstream write;
    write.open("student.txt", ios::app);
    write << "\n"
          << ID;
    write << "\n"
          << student.name;
    write << "\n"
          << student.course;

    write << "\n"
          << student.phno;
    write << "\n"
          << student.loc;
    write.close();
    write.open("id.txt");
    write << ID;
    write.close();
    cout << "\n";
    cout << "\n\tData save to file";
    cout << "\n";
}

void print(Student s)
{
    cout << "\n";
    cout << "\n\t---Student Data---";
    cout << "\n\tID is : " << s.id;
    cout << "\n\tName is : " << s.name;
    cout << "\n\tCourse is : " << s.course;
    cout << "\n\tPh. No. is : " << s.phno;
    cout << "\n\tLocation is : " << s.loc;
    cout << "\n";
}

void readData()
{
    Student student;
    ifstream read;
    read.open("student.txt");
    while (!read.eof())
    {
        read >> student.id;
        read.ignore();
        getline(read, student.name);
        read >> student.course;
        read >> student.phno;
        read >> student.loc;
        print(student);
    }
    read.close();
}

int searchData()
{
    int id;
    cout << "\n";
    cout << "\n\tEnter student id want to search : ";
    cin >> id;
    cout << "\n";
    Student student;
    ifstream read;
    read.open("student.txt");
    while (!read.eof())
    {
        read >> student.id;
        read.ignore();
        getline(read, student.name);
        read >> student.course;
        read >> student.phno;
        read >> student.loc;
        if (student.id == id)
        {
            print(student);
            return id;
        }
    }
}

void deleteData()
{
    int id = searchData();
    cout << "\n";
    cout << "\n\tYou want to delete record (y/n) : ";
    char choice;
    cin >> choice;
    if (choice == 'y')
    {
        Student student;
        ofstream tempFile;
        tempFile.open("temp.txt");
        ifstream read;
        read.open("student.txt");
        while (!read.eof())
        {
            read >> student.id;
            read.ignore();
            getline(read, student.name);
            read >> student.course;
            read >> student.phno;
            read >> student.loc;
            cout << "\n";
            if (student.id != id)
            {
                tempFile << "\n"
                         << student.id;
                tempFile << "\n"
                         << student.name;
                tempFile << "\n"
                         << student.course;
                tempFile << "\n"
                         << student.phno;
                tempFile << "\n"
                         << student.loc;
            }
        }
        read.close();
        tempFile.close();
        remove("student.txt");
        rename("temp.txt", "student.txt");
        cout << "\n";
        cout << "\n\tData deleted successfuly";
        cout << "\n";
    }
    else
    {
        cout << "\n";
        cout << "\n\tRecord not deleted";
        cout << "\n";
    }
}

void updateData()
{
    int id = searchData();
    cout << "\n";
    cout << "\n\tYou want to update record (y/n) : ";
    char choice;
    cin >> choice;
    if (choice == 'y')
    {
        Student newData;
        cout << "\n";
        cout << "\n\tEnter student name : ";
        cin.get();
        getline(cin, newData.name);
        cout << "\n\tEnter student course : ";
        cin >> newData.course;
        cout << "\n\tEnter student Ph. No. : ";
        cin >> newData.phno;
        cout << "\n\tEnter student location : ";
        cin >> newData.loc;
        cout << "\n";
        Student student;
        ofstream tempFile;
        tempFile.open("temp.txt");
        ifstream read;
        read.open("student.txt");
        while (!read.eof())
        {
            read >> student.id;
            read.ignore();
            getline(read, student.name);
            read >> student.course;
            read >> student.phno;
            read >> student.loc;
            if (student.id != id)
            {
                tempFile << "\n"
                         << student.id;
                tempFile << "\n"
                         << student.name;
                tempFile << "\n"
                         << student.course;
                tempFile << "\n"
                         << student.phno;
                tempFile << "\n"
                         << student.loc;
            }
            else
            {
                tempFile << "\n"
                         << student.id;
                tempFile << "\n"
                         << newData.name;
                tempFile << "\n"
                         << newData.course;
                tempFile << "\n"
                         << newData.phno;
                tempFile << "\n"
                         << newData.loc;
            }
        }
        read.close();
        tempFile.close();
        remove("student.txt");
        rename("temp.txt", "student.txt");
        cout << "\n";
        cout << "\n\tData updated successfuly";
        cout << "\n";
    }
    else
    {
        cout << "\n";
        cout << "\n\tRecord not deleted";
        cout << "\n";
    }
}

int main()
{
    ifstream read;
    read.open("id.txt");
    if (!read.fail())
    {
        read >> ID;
    }
    else
    {
        ID = 0;
    }
    read.close();
    cout << "\n\n\n";
    cout << "\n   DRIVING SCHOOL MANAGEMENT SYSTEM";
    while (true)
    {
        cout << "\n";
        cout << "\n   ===============================";
        cout << "\n   ===============================";
        cout << "\n\t1.Add student data";
        cout << "\n\t2.See student data";
        cout << "\n\t3.Search student data";
        cout << "\n\t4.Delete student data";
        cout << "\n\t5.Update student data";
        cout << "\n\t6.Exit";
        cout << "\n   ===============================";
        cout << "\n   ===============================";
        cout << "\n";

        int choice;
        cout << "\n\tEnter choice : ";
        cin >> choice;
        switch (choice)
        {
        case 1:
            addStudent();
            break;
        case 2:
            readData();
            break;
        case 3:
            searchData();
            break;
        case 4:
            deleteData();
            break;
        case 5:
            updateData();
            break;
        default:
            exit(0);
        }
    }
}