#include <iostream>
#include <string>
#include <vector> 

using namespace std;

class Date
{

private:
    int day;
    int month;
    int year;

public:
    Date(int d, int m, int y)
    {
        day = d;
        month = m;
        year = y;
    }

    Date()
    {
        day = 0;
        month = 0;
        year = 0;
    }

    ~Date()
    {
    }


    int getDay() const
    {
        return day;
    }

    int getMonth() const
    {
        return month;
    }

    int getYear() const
    {
        return year;
    }



    void setDay(int sD)
    {
        day = sD;
    }

    void setMonth(int sM)
    {
        month = sM;
    }

    void setYear(int sY)
    {
        year = sY;
    }


    bool isLeapYear() const
    {
        if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0))
        {
            return true;
        }
        return false;
    }


    bool isValidDate() const
    {
        if (month >= 1 && month <= 12)
        {
            if (day >= 1)
            {
                if (month == 4 || month == 6 || month == 9 || month == 11)
                {
                    return (day <= 30);
                }
                else if (month == 2)
                {
                    if (isLeapYear())
                    {
                        return (day <= 29);
                    }
                    else
                    {
                        return (day <= 28);
                    }
                }
                else
                {
                    return (day <= 31);
                }
            }
        }
        return false;
    }

    string format1() const
    {
        return to_string(day) + "." + to_string(month) + "." + to_string(year % 100);
    }

    string format2() const
    {
        return to_string(day) + "/" + to_string(month) + "/" + to_string(year);
    }

    string format3() const
    {
        string monthNames[12] = { "Jan", "Feb", "Mar", "Apr", "May", "Jun", "Jul", "Aug", "Sep", "Oct", "Nov", "Dec" };
        return monthNames[month - 1] + "-" + to_string(day) + "-" + to_string(year);
    }
};

class Student;

class PrivateStudent
{
private:
    int age;
    string gender;
    int scholarship;

public:
    /////////////////////////
    int getAge() const
    {
        return age;
    }

    void setAge(int studentAge)
    {
        age = studentAge;
    }
    /////////////////////////
    string getGender() const
    {
        return gender;
    }

    void setGender(const string &studentGender) {
        gender = studentGender;
    }
    /////////////////////////
    int getScholarship() const
    {
        return scholarship;
    }

    void setScholarship(int studentScholarship)
    {
        scholarship = studentScholarship;
    }
    /////////////////////////

private:
    static vector<Student> students;
};


class Student
{

public:
    int age;
    string gender;
    int scholarship;


    // Конструктор класу з параметрами
    Student(int studentAge, const string &studentGender, int studentScholarship)
    {
        age = studentAge;
        gender = studentGender;
        scholarship = studentScholarship;
    }

    // Конструктор класу з дефолтними параметрами
    Student()
    {
        age = 0;        // дефолт параметри
        gender = "";
        scholarship = 0.0;
    }

    // Деструктор класу 
    ~Student()
    {
    }



    void inputStudentData()
    {
        cout << "Введіть вік студента: ";
        cin >> age;
        cin.ignore();       // очищення буфера вводу даних
        cout << "Введіть стать студента: ";
        getline(cin, gender);
        cout << "Введіть стипендію студента: ";
        cin >> scholarship;
    }


    void displayStudentData()
    {
        cout << "Вік: " << age << endl;
        cout << "Стать: " << gender << endl;
        cout << "Стипендія: " << scholarship << endl;
    }

public:
    static vector<Student> students;
};

vector<Student> Student::students;

class Collection
{
private:
    Student *students;
    int studentCount;
    int capacity;

public:
    Collection()
    {
        capacity = 5;
        students = new Student[capacity];
        studentCount = 0;
    }

    void addStudent(const Student& newStudent)
    {
        if (studentCount == capacity)
        {
            capacity += 1;
            Student *newStudents = new Student[capacity];
            for (int i = 0; i < studentCount; i++)
            {
                newStudents[i] = students[i];
            }
            delete[] students;
            students = newStudents;
        }

        students[studentCount] = newStudent;
        studentCount++;
    }


    double calculateAverageAge()
    {
        if (studentCount == 0)
            return 0;

        int totalAge = 0;
        for (int i = 0; i < studentCount; i++)
        {
            totalAge += students[i].age;
        }

        return static_cast<double>(totalAge) / studentCount;
    }


    int calculateTotalScholarship()
    {
        int totalScholarship = 0;
        for (int i = 0; i < studentCount; i++)
        {
            totalScholarship += students[i].scholarship;
        }
        return totalScholarship;
    }

    ~Collection()
    {
        delete[] students;
    }
};

int main()
{
    setlocale(LC_ALL, "Ukrainian");

    Collection studentCollection;

    Student student0(20, "Man", 1000);
    Student student1(22, "Woman", 1200);

    studentCollection.addStudent(student0);
    studentCollection.addStudent(student1);

    double averageAge = studentCollection.calculateAverageAge();
    int totalScholarship = studentCollection.calculateTotalScholarship();

    cout << "Средний возраст студентов: " << averageAge << std::endl;
    cout << "Общая стипендия: " << totalScholarship << std::endl;
    cout << "" << endl;

    ///////////////////////////////////////////////////////////

 
    Student student2(20, "Man", 1000);
    Student student3(22, "Woman", 1200);

    Student::students.push_back(student2);
    Student::students.push_back(student3);

    for (auto &student : Student::students)
    {
        student.displayStudentData();
    }

    //////////////////////////////////
    Student student4(18, "Man", 2000);
    Student student5(19, "Woman", 2400);

    cout << student4.age << " " << student4.gender << " " << student4.scholarship << endl;
    cout << student4.age << " " << student5.gender << " " << student5.scholarship << endl;


    Student student6;
    Student student7;

    cout << "Введіть інфу про студента" << endl;
    student6.inputStudentData();

    cout << "Введіть інфу про студента" << endl;
    student7.inputStudentData();


    cout << "Шостий студент" << endl;
    student6.displayStudentData();

    cout << "Сьомий студент" << endl;
    student7.displayStudentData();

    /////////////////////////////////////////////////////////////////////////////////////

    PrivateStudent pStudent0;
    PrivateStudent pStudent1;

    pStudent0.setAge(18);
    pStudent1.setAge(20);

    pStudent0.setGender("Man");
    pStudent1.setGender("Woman");

    pStudent0.setScholarship(3000);
    pStudent1.setScholarship(2700);


    pStudent0.getAge();
    pStudent1.getAge();

    pStudent0.getGender();
    pStudent1.getGender();

    pStudent0.getScholarship();
    pStudent1.getScholarship();


    int average_age = (pStudent0.getAge() + pStudent1.getAge()) / 2;
    cout << average_age << endl;

    int all_scholarship = pStudent0.getScholarship() + pStudent1.getScholarship();
    cout << all_scholarship << endl;

    ////////////////////

    Date my_birthday;

    my_birthday.setDay(15);
    my_birthday.setMonth(5);
    my_birthday.setYear(2005);

    cout << my_birthday.format1() << endl;
    cout << my_birthday.format2() << endl;
    cout << my_birthday.format3() << endl;

    cout << my_birthday.isLeapYear() << endl;
    cout << my_birthday.isValidDate() << endl;

    return 0;
}
