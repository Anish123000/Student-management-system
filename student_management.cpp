#include <iostream>
#include <string>
using namespace std;

struct Student
{
    int id;
    string name;
    string dept;
    float marks;
};

int main()
{
    Student students[100];
    int count = 0;
    int choice;

    students[0].id = 101;
    students[0].name = "Anish Kalwar";
    students[0].dept = "CSE";
    students[0].marks = 85;

    students[1].id = 102;
    students[1].name = "Rahul Kumar";
    students[1].dept = "IT";
    students[1].marks = 78;
    count = 2;

    do
    {
        cout << "\n===== Student Management System =====\n";
        cout << "1. Add Student\n";
        cout << "2. Display All Students\n";
        cout << "3. Search Student by ID\n";
        cout << "4. Update Marks\n";
        cout << "5. Delete Student\n";
        cout << "6. Show Topper\n";
        cout << "7. Average Marks\n";
        cout << "8. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        if (choice == 1)
        {
            if (count == 100)
            {
                cout << " Storage full!\n";
                continue;
            }

            cout << "Enter ID: ";
            cin >> students[count].id;

            //  Duplicate ID Check
            bool exists = false;
            for (int i = 0; i < count; i++)
            {
                if (students[i].id == students[count].id)
                {
                    exists = true;
                    break;
                }
            }

            if (exists)
            {
                cout << " ID already exists!\n";
                continue;
            }

            cin.ignore();

            cout << "Enter Name: ";
            getline(cin, students[count].name);

            cout << "Enter Department: ";
            getline(cin, students[count].dept);

            cout << "Enter Marks: ";
            cin >> students[count].marks;

            count++;
            cout << " Student Added Successfully!\n";
        }

        else if (choice == 2)
        {
            if (count == 0)
            {
                cout << " No students available!\n";
            }
            else
            {
                cout << "\nID\tName\t\tDept\tMarks\n";
                for (int i = 0; i < count; i++)
                {
                    cout << students[i].id << "\t"
                         << students[i].name << "\t"
                         << students[i].dept << "\t"
                         << students[i].marks << endl;
                }
            }
        }

        else if (choice == 3)
        {
            int id;
            cout << "Enter ID to search: ";
            cin >> id;

            bool found = false;
            for (int i = 0; i < count; i++)
            {
                if (students[i].id == id)
                {
                    cout << " Found: "
                         << students[i].name << " | "
                         << students[i].dept << " | "
                         << students[i].marks << endl;
                    found = true;
                    break;
                }
            }
            if (!found)
                cout << " Student not found\n";
        }

        else if (choice == 4)
        {
            int id;
            cout << "Enter ID to update marks: ";
            cin >> id;

            bool found = false;
            for (int i = 0; i < count; i++)
            {
                if (students[i].id == id)
                {
                    cout << "Current Marks: " << students[i].marks << endl;
                    cout << "Enter New Marks: ";
                    cin >> students[i].marks;
                    cout << " Updated!\n";
                    found = true;
                    break;
                }
            }
            if (!found)
                cout << " Student not found\n";
        }

        else if (choice == 5)
        {
            int id;
            cout << "Enter ID to delete: ";
            cin >> id;

            bool found = false;
            for (int i = 0; i < count; i++)
            {
                if (students[i].id == id)
                {
                    for (int j = i; j < count - 1; j++)
                    {
                        students[j] = students[j + 1];
                    }
                    count--;
                    cout << "🗑 Student Deleted!\n";
                    found = true;
                    break;
                }
            }
            if (!found)
                cout << " Student not found\n";
        }

        else if (choice == 6)
        {
            if (count == 0)
            {
                cout << " No students available!\n";
            }
            else
            {
                int topperIndex = 0;
                for (int i = 1; i < count; i++)
                {
                    if (students[i].marks > students[topperIndex].marks)
                    {
                        topperIndex = i;
                    }
                }

                cout << " Topper: "
                     << students[topperIndex].name
                     << " | " << students[topperIndex].marks << endl;
            }
        }

        else if (choice == 7)
        {
            if (count == 0)
            {
                cout << " No students available!\n";
            }
            else
            {
                float sum = 0;
                for (int i = 0; i < count; i++)
                {
                    sum += students[i].marks;
                }
                cout << " Average Marks: " << (sum / count) << endl;
            }
        }

        else if (choice == 8)
        {
            cout << " Program Exiting...\n";
        }

        else
        {
            cout << " Invalid choice!\n";
        }

    } while (choice != 8);

    return 0;
}
