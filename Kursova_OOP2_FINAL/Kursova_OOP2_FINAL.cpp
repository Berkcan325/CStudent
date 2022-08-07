// Kursova_OOP2_FINAL.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include <iostream>
#include <fstream>
#include< vector>

using namespace std;

class CStudentData {
private:
    string Cname;
    double Cdiploma = 0;
    double Cizpit = 0;
    double Caverage = 0;
public:
    CStudentData() {}

    CStudentData(string name) {
        CStudentGen();
        Cname = name;
        Caverage = (Cdiploma + Cizpit) / 2;
    }
    void SetName(string name) {
        Cname = name;
    }
    void SetDiploma(double diploma) {
        Cdiploma = diploma;
    }
    void SetIzpit(double izpit) {
        Cizpit = izpit;
    }
    double GetAverage() {
        return this->Caverage;
    }
    string GetName() {
        return this->Cname;
    }
    double GetDiploma() {
        return this->Cdiploma;
    }
    double GetIzpit() {
        return this->Cizpit;
    }
    friend ostream& operator<<(ostream& out, CStudentData& obj) {
        out << "Ime: " << obj.GetName();
        out << "\nOcenka ot izpit: " << obj.GetIzpit();
        out << "\nOcenka na diploma: " << obj.GetDiploma();
        out << "\nSrednoaritmetichna ocenka: " << ((obj.GetIzpit() + obj.GetDiploma()) / 2);
        return out;
    }
    istream& Input(istream& in, CStudentData& Student)
    {
        in >> Student.Cname;
        in >> Student.Cizpit;
        in >> Student.Cdiploma;
        return in;
    }
    void CStudentGen() {
        this->Cdiploma = 3 + (double)(rand()) / ((double)(RAND_MAX / (6 - 3)));
        this->Cizpit = 3 + (double)(rand()) / ((double)(RAND_MAX / (6 - 3)));
    }
    bool CheckGrade() {
        if (this->Cdiploma > 3 && this->Cdiploma < 6 && this->Cizpit > 3 && this->Cizpit < 6) return true;
        return false;
    }
    static void CAverageFunction(vector<CStudentData>Student)
    {
        double Diploma = 0, Izpit = 0, Average = 0;
        for (int i = 0; i < Student.size(); i++)
        {
            Diploma += Student[i].GetDiploma();
            Izpit += Student[i].GetIzpit();
            Average += Student[i].GetAverage();
        }
        Diploma /= Student.size();
        cout << "Sreden uspeh na diploma: " << Diploma << endl;
        Izpit /= Student.size();
        cout << "Sreden uspeh na izpit: " << Izpit << endl;
        Average /= Student.size();
        cout << "Sreden uspeh na vsichki studenti: " << Average << endl;
    }
    static void CreateFile(vector<CStudentData>Student)
    {
        ofstream  file;
        file.open("Info.txt", ios::out);
        if (file.fail())
        {
            cout << "\nFaylat ne moje da se sazdade";
        }
        else
        {
            for (int a = 0; a < Student.size(); a++)
            {
                file << Student[a] << "\n";
            }
            cout << "\nStudentite sa zapisani";
        }
        file.close();
    }
};

int main()
{
    CStudentData a("Berkcan ");
    CStudentData b("Sinan ");
    vector<CStudentData> Student;
    if (a.CheckGrade() && b.CheckGrade()) {
        Student.push_back(a);
        Student.push_back(b);
        CStudentData::CAverageFunction(Student);
    }
    else cout << "Nevaildni ocenki";
    CStudentData::CreateFile(Student);
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
