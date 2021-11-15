#include <iostream>
#include <vector>

using namespace std;

class Person
{
protected:
    string firstName;
    string lastName;
    int id;

public:
    Person(string firstName, string lastName, int identification)
    {
        this->firstName = firstName;
        this->lastName = lastName;
        this->id = identification;
    }
    void printPerson()
    {
        cout << "Name: " << lastName << ", " << firstName << "\nID: " << id << "\n";
    }
};

class Student : public Person
{
private:
    vector<int> testScores;

public:
    /*	
        *   Class Constructor
        *   
        *   Parameters:
        *   firstName - A string denoting the Person's first name.
        *   lastName - A string denoting the Person's last name.
        *   id - An integer denoting the Person's ID number.
        *   scores - An array of integers denoting the Person's test scores.
        */
    // Write your constructor here
    Student(string, string, int, vector<int> &);

    /*	
        *   Function Name: calculate
        *   Return: A character denoting the grade.
        */
    // Write your function here
    char calculate();
};

Student::Student(string firstName, string lastName, int identification, vector<int> &testscores) : Person(firstName, lastName, identification), testScores(testscores)
{
    //base called constructor is called from list initialiser
}
char Student::calculate()
{
    int avg = 0;
    int num_Of_Subjects = testScores.size();
    for (int i = 0; i < num_Of_Subjects; i++)
    {
        avg += testScores[i];
    }
    avg /= num_Of_Subjects;
    switch (avg)
    {
    case 90 ... 100:
        return 'O';
        break;
    case 80 ... 89:
        return 'E';
        break;
    case 70 ... 79:
        return 'A';
        break;
    case 55 ... 69:
        return 'P';
        break;
    case 40 ... 54:
        return 'D';
        break;
    default:
        return 'T';
        break;
    }
}

int main()
{
    string firstName;
    string lastName;
    int id;
    int numScores;
    cin >> firstName >> lastName >> id >> numScores;
    vector<int> scores;
    for (int i = 0; i < numScores; i++)
    {
        int tmpScore;
        cin >> tmpScore;
        scores.push_back(tmpScore);
    }
    Student *s = new Student(firstName, lastName, id, scores);
    s->printPerson();
    cout << "Grade: " << s->calculate() << "\n";
    return 0;
}