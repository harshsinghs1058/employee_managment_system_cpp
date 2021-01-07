//this code is created by HARSH.
#include <bits/stdc++.h>
#include <conio.h>
using namespace std;
const char *fileName = "Employee.txt";
char tempFile[] = "temp.txt";
fstream file;
char TEMP[50];
void upper(char s[])
{
     for (int i = 0; i < strlen(s); i++)
     {
          s[i] = (char)toupper(s[i]);
     }
}
bool isNumber(char s[])
{
     for (int i = 0; i < strlen(s); i++)
     {
          if (isdigit(s[i]) == 0)
          {
               return false;
          }
     }
     return true;
}
int chanegeStringToNum(char s[])
{
     int result = 0;
     for (int i = 0; i < strlen(s); i++)
     {
          result = result * 10 + (int)s[i] - 48;
     }
     return result;
}
void LogIn();
class admin
{
     char adminName[50], password[50];
     long int contact;

public:
     void readData(char s[])
     {
          strcpy(adminName, s);
          cout << "Enter password : ";
          cin >> password;
     }
     void printData()
     {
          cout << "|" << setw(20) << adminName << "|" << endl;
     }
     char *getName()
     {
          return adminName;
     }
     char *getPassword()
     {
          return password;
     }
     friend void getContact(li x);
};
void contact(li x)
{
     contact = x;
}
class Employee
{
public:
     int EmpID;
     char EmpName[50], Post[50], Department[50], pass[50];
     float Salary;
     bool ReadData(int x)
     {
          EmpID = x;
          cout << "Employee First Name:";
          cin >> EmpName;
          upper(EmpName);
          cout << "Employee Last Name (enter 0 if none):";
          cin >> TEMP;
          if (toupper(TEMP[0]) != 48)
          {
               upper(TEMP);
               strcat(EmpName, " ");
               strcat(EmpName, TEMP);
          }
          cout << "Employee's Post:";
          cin >> Post;
          upper(Post);
          cout << "Employee's Department:";
          cin >> Department;
          upper(Department);
          cout << "Salary:";
          cin >> TEMP;
          if (isNumber(TEMP))
          {
               Salary = (float)chanegeStringToNum(TEMP);
          }
          else
          {
               cout << "Salary must be number. . .";
               return false;
          }
          cout << "Employee's profile password : ";
          cin >> pass;
          return true;
     }
     int GetID()
     {
          return EmpID;
     }
     void DisplayRecord()
     {
          cout << endl
               << "____________________________________________________________________________________________";
          cout << endl
               << "|" << setw(5) << EmpID << "|" << setw(20) << EmpName << "|" << setw(20) << Post << "|" << setw(20) << Department << "|" << setw(10) << Salary << "|" << setw(10) << pass << "|";
     }
     char *GetDepartment()
     {
          return Department;
     }
};
Employee emp, e;
void Stop()
{
     cout << endl
          << endl;
     system("pause");
     system("cls");
}

void insertNewEmployee()
{
     int x;
     cout << "*******INSERT NEW EMPLOYEE*******" << endl;
     cout << "Enter new employee ID : ";
     cin >> TEMP;
     if (isNumber(TEMP))
     {
          x = chanegeStringToNum(TEMP);
     }
     else
     {
          cout << "Employee ID must be in digits..." << endl
               << endl;
          system("pause");
          return;
     }
     file.open(fileName, ios::in | ios::out | ios ::binary);
     file.seekg(0, ios::beg);
     int isFound = 0;
     file.read((char *)&e, sizeof(e));
     while (!file.eof())
     {
          if (e.GetID() == x)
          {
               cout << "This ID already exist...Try for another ID" << endl;
               isFound = 1;
               file.close();
               Stop();
               return;
          }
          file.read((char *)&e, sizeof(e));
     }
     file.clear();
     file.seekp(0, ios::end);
     if (emp.ReadData(x))
     {
          cout << endl
               << "New record has been added successfully..." << endl;
          file.write((char *)&emp, sizeof(emp));
     }
     else
     {
          cout << endl
               << "Hence, cannot add new employee";
     }
     Stop();
     file.close();
}
void SearchEmployee()
{
     int isFound = 0, ID;
     cout << endl
          << "Enter ID of an employee to be searched : ";
     cin >> TEMP;
     if (isNumber(TEMP) == false)
     {
          cout << "ID not found..." << endl;
          Stop();
          return;
     }
     ID = chanegeStringToNum(TEMP);
     file.open(fileName, ios::in | ios::out | ios ::binary);
     file.seekg(0, ios::beg);
     file.read((char *)&e, sizeof(e));
     while (!file.eof())
     {
          if (e.GetID() == ID)
          {
               cout << endl
                    << "The record found...." << endl;
               cout << endl
                    << "ID : " << e.EmpID
                    << endl
                    << "Name : " << e.EmpName
                    << endl
                    << "Post : " << e.Post
                    << endl
                    << "Department : " << e.Department
                    << endl
                    << "Salary : " << e.Salary
                    << endl
                    << "Password : " << e.pass
                    << endl;
               isFound = 1;
               break;
          }
          file.read((char *)&e, sizeof(e));
     }
     if (isFound == 0)
          cout << endl
               << "Data not found for employee ID : " << ID;
     Stop();
     file.close();
}
void DisplayDepartment()
{
     file.open(fileName, ios::in | ios::out | ios ::binary);
     int isFound = 0;
     char Dept[50];
     cout << "Enter department name to list employee within it:";
     cin >> Dept;
     upper(Dept);
     file.seekg(0, ios::beg);
     file.read((char *)&e, sizeof(e));
     while (!file.eof())
     {
          if (strcmp(e.GetDepartment(), Dept) == 0)
          {
               if (isFound == 0)
               {
                    cout << endl
                         << "The record found for this department" << endl;
                    cout << endl
                         << "____________________________________________________________________________________________";
                    cout << endl
                         << "|"
                         << setw(5) << "ID"
                         << "|" << setw(20) << "Name"
                         << "|" << setw(20) << "Post"
                         << "|" << setw(20) << "Department"
                         << "|" << setw(10) << "Salary"
                         << "|" << setw(10) << "Password"
                         << "|";
               }
               e.DisplayRecord();
               isFound = 1;
          }
          file.read((char *)&e, sizeof(e));
     }
     file.close();
     if (isFound == 0)
          cout << endl
               << "Data not found for department : " << Dept;
     else
          cout << endl
               << "--------------------------------------------------------------------------------------------";
     Stop();
}
void DisplayAll()
{
     cout << endl
          << "Record for employee";
     file.open(fileName, ios::in | ios::out | ios ::binary);
     int counter = 0;
     file.seekg(0, ios::beg);
     counter = 0;
     file.read((char *)&e, sizeof(e));
     while (!file.eof())
     {
          counter++;
          if (counter == 1)
          {

               cout << endl
                    << "____________________________________________________________________________________________";
               cout << endl
                    << "|"
                    << setw(5) << "ID"
                    << "|" << setw(20) << "Name"
                    << "|" << setw(20) << "Post"
                    << "|" << setw(20) << "Department"
                    << "|" << setw(10) << "Salary"
                    << "|" << setw(10) << "Password"
                    << "|";
          }
          e.DisplayRecord();
          file.read((char *)&e, sizeof(e));
     }
     if (counter > 0)
          cout << endl
               << "--------------------------------------------------------------------------------------------";

     cout << endl
          << counter
          << " records found...... " << endl;
     file.close();
     Stop();
}
void UpdateEmployeeData()
{
     int recordNo = 0, isFound = 0, ID;
     cout << endl
          << "File is being modified....";
     cout << endl
          << "Enter employee ID to be updated : ";
     cin >> TEMP;
     if (isNumber(TEMP) == false)
     {
          cout << "ID not found..." << endl;
          Stop();
          return;
     }
     ID = chanegeStringToNum(TEMP);
     file.open(fileName, ios::in | ios::out | ios ::binary);
     file.seekg(0, ios::beg);
     file.read((char *)&e, sizeof(e));
     while (!file.eof())
     {
          recordNo++;
          if (e.GetID() == ID)
          {
               cout << "The old record of employee having ID " << ID << " is : ";
               cout << endl
                    << "ID : " << e.EmpID
                    << endl
                    << "Name : " << e.EmpName
                    << endl
                    << "Post : " << e.Post
                    << endl
                    << "Department : " << e.Department
                    << endl
                    << "Salary : " << e.Salary
                    << endl
                    << "Password : " << e.pass
                    << endl;
               isFound = 1;
               break;
          }
          file.read((char *)&e, sizeof(e));
     }

     if (isFound == 0)
     {
          cout << endl
               << "Data not found for employee ID : " << ID;
          Stop();
          file.close();
          return;
     }
     file.clear();
     int location = (recordNo - 1) * sizeof(e);
     file.seekp(location, ios::beg);
     cout << endl
          << "Enter new record for employee having ID : " << ID << endl;
     cout << "Employee First Name:";
     cin >> e.EmpName;
     upper(e.EmpName);
     cout << "Employee Last Name (enter 0 if none):";
     cin >> TEMP;
     if (toupper(TEMP[0]) != 48)
     {
          upper(TEMP);
          strcat(e.EmpName, " ");
          strcat(e.EmpName, TEMP);
     }
     cout << "Employee's Post:";
     cin >> e.Post;
     upper(e.Post);
     cout << "Employee's Department:";
     cin >> e.Department;
     upper(e.Department);
     cout << "Salary:";
     cin >> e.Salary;
     cout << "Employee's profile password : ";
     cin >> e.pass;
     cout << endl
          << "Record successfully updated...";
     file.write((char *)&e, sizeof(e));
     file.close();
     Stop();
}
void DeleteEmployee()
{
     int recordNo = 0, ID;
     cout << endl
          << "Enter employment ID to be deleted:";
     cin >> TEMP;
     if (isNumber(TEMP) == false)
     {
          cout << "ID not found..." << endl;
          Stop();
          return;
     }
     ID = chanegeStringToNum(TEMP);
     int isFound = 0;
     file.open(fileName, ios::in | ios::out | ios ::binary);
     fstream temp(tempFile, ios::out | ios ::binary);
     file.clear();
     file.seekg(0, ios::beg);
     file.read((char *)&e, sizeof(e));
     while (!file.eof())
     {
          recordNo++;
          if (e.GetID() == ID)
          {
               cout << "The old record of employee having ID " << ID << " is: ";
               cout << endl
                    << "|"
                    << setw(5) << "ID"
                    << "|" << setw(20) << "Name"
                    << "|" << setw(20) << "Post"
                    << "|" << setw(20) << "Department"
                    << "|" << setw(10) << "Salary"
                    << "|" << setw(10) << "Password"
                    << "|";
               e.DisplayRecord();
               cout << endl
                    << "is deleted...";
               isFound = 1;
               break;
          }
          file.read((char *)&e, sizeof(e));
     }

     if (isFound == 0)
     {
          cout << endl
               << "Data not found for employee ID : " << ID;
          Stop();
          file.close();
          return;
     }
     else
     {
          file.clear();
          file.seekg(0, ios::beg);
          file.read((char *)&e, sizeof(e));
          while (!file.eof())
          {
               if (e.GetID() != ID)
                    temp.write((char *)&e, sizeof(e));
               file.read((char *)&e, sizeof(e));
          }
          file.close();
          temp.close();
          temp.open(tempFile, ios::in | ios ::binary);
          file.open(fileName, ios::out | ios ::binary);
          temp.read((char *)&e, sizeof(e));
          while (!temp.eof())
          {
               file.write((char *)&e, sizeof(e));
               temp.read((char *)&e, sizeof(e));
          }
     }
     temp.close();
     file.close();
     remove(tempFile);
     Stop();
}
void AddAdmin()
{
     admin adm, k;
     int isFound = 0;
     char AdminName[50], password[50];
     cout << "Enter new admin username : ";
     cin >> AdminName;
     upper(AdminName);
     if (strcmp(AdminName, "HARSH") == 0 || strcmp(AdminName, "DEVANSHU") == 0)
     {
          cout << "This username already exists . . .try with another name...";
          Stop();
          return;
     }
     fstream fout("admin.txt", ios::in | ios::out | ios::binary);
     fout.seekg(0, ios::beg);
     fout.read((char *)&adm, sizeof(adm));
     while (!fout.eof())
     {
          if (strcmp(adm.getName(), AdminName) == 0)
          {
               cout << "Admin username already exists . . .try with another name";
               fout.close();
               Stop();
               return;
          }
          fout.read((char *)&adm, sizeof(adm));
     }
     k.readData(AdminName);
     fout.clear();
     fout.seekp(0, ios::end);
     fout.write((char *)&k, sizeof(k));
     cout << "New user sucessfully created.." << endl;
     Stop();
     fout.close();
}
void printAdminList()
{
     cout << "PRINTING ADMIN LIST : " << endl
          << endl;
     cout << "----------------------" << endl;
     cout << "|" << setw(20) << "USERNAME"
          << "|" << endl;
     cout << "----------------------" << endl;

     cout << "|" << setw(20) << "DEVANSHU"
          << "|" << endl;
     cout << "----------------------" << endl;

     cout << "|" << setw(20) << "HARSH"
          << "|" << endl;
     fstream fout("admin.txt", ios::in | ios::binary);
     admin adm;
     int i = 2;
     fout.seekg(0, ios::beg);
     fout.read((char *)&adm, sizeof(adm));
     while (!fout.eof())
     {
          cout << "----------------------" << endl;
          adm.printData();
          i++;
          fout.read((char *)&adm, sizeof(adm));
     }
     cout << "----------------------" << endl;
     cout << i << " admins record found";
     Stop();
     fout.close();
}
void deleteAdmin()
{
     string s;
     admin adm;
     int isFound = 0, recordNo;
     cout << "Enter user name to be deleted : ";
     cin >> s;
     transform(s.begin(), s.end(), s.begin(), ::toupper);
     if (s == "HARSH" || s == "DEVANSHU")
     {
          cout << "Cannot delete default admin . . .";
          Stop();
          return;
     }
     fstream temp(tempFile, ios::out | ios ::binary);
     fstream fout("admin.txt", ios::in | ios::binary);
     fout.seekg(0, ios::beg);
     fout.read((char *)&adm, sizeof(adm));
     while (!fout.eof())
     {
          recordNo++;
          if (adm.getName() == s)
          {
               cout << "deleting admin with USERNAME - " << adm.getName() << endl;
               isFound = 1;
               break;
          }
          fout.read((char *)&adm, sizeof(adm));
     }
     if (isFound == 0)
     {
          cout << endl
               << "Data not found for Admin Username : " << s << endl;
          Stop();
          fout.close();
          return;
     }
     else
     {
          fout.clear();
          fout.seekg(0, ios::beg);
          fout.read((char *)&adm, sizeof(adm));
          while (!fout.eof())
          {
               if (adm.getName() != s)
                    temp.write((char *)&adm, sizeof(adm));
               fout.read((char *)&adm, sizeof(adm));
          }
          fout.close();
          temp.close();
          temp.open(tempFile, ios::in | ios ::binary);
          fstream fout("admin.txt", ios::out | ios::binary);
          temp.read((char *)&adm, sizeof(adm));
          while (!temp.eof())
          {
               fout.write((char *)&adm, sizeof(adm));
               temp.read((char *)&adm, sizeof(adm));
          }
     }
     temp.close();
     fout.close();
     remove(tempFile);
     Stop();
}
void solve()
{
     system("Color 0A");
     string option, ch;
     int isFound = 10;
     do
     {
          if (isFound == 10)
          {
               system("cls");
          }
          cout << endl
               << "*******ADMIN MAIN MENU*******";
          cout << endl
               << "Enter your option";
          cout << endl
               << " 1 => Add a new record";
          cout << endl
               << " 2 => Search record from employee id";
          cout << endl
               << " 3 => List Employee of particular department";
          cout << endl
               << " 4 => Display all employee";
          cout << endl
               << " 5 => Update record of an employee";
          cout << endl
               << " 6 => Delete record of particular employee";
          cout << endl
               << " 7 => Log off";
          cout << endl
               << " 8 => Add admin";
          cout << endl
               << " 9 => Print admin list";
          cout << endl
               << "10 => Delete admin";
          cout << endl
               << "11 => Exit from the program" << endl;
          cout << "********************" << endl
               << "Enter option : ";
          cin >> option;
          system("cls");
          if (option == "1")
               insertNewEmployee();
          else if (option == "2")
               SearchEmployee();
          else if (option == "3")
               DisplayDepartment();
          else if (option == "4")
               DisplayAll();
          else if (option == "5")
               UpdateEmployeeData();
          else if (option == "6")
               DeleteEmployee();
          else if (option == "7")
               LogIn();
          else if (option == "8")
               AddAdmin();
          else if (option == "9")
               printAdminList();
          else if (option == "10")
               deleteAdmin();
          else if (option == "11")
               exit(0);
          else
          {
               cout << "Invalid Options" << endl
                    << "Do you still wants to continue (y or n) : ";
               cin >> ch;
               if (ch != "y" || ch != "Y")
                    system("cls");
          }
     } while (ch != "n" && ch != "N");
}
void AdminLogIn()
{
     admin adm;
     fstream fout("admin.txt", ios::in | ios::binary);
     system("cls");
     fout.seekg(0, ios::beg);
     cout << endl
          << "***********************************" << endl
          << "*************ADMIN LOG*************" << endl
          << "***********************************" << endl;
     string INPUT, passInput;
     int password = 1234, i = 0, isFound = 0;
     cout << "ENTER ADMIN NAME : ";
     cin >> INPUT;
     // upper(INPUT);
     transform(INPUT.begin(), INPUT.end(), INPUT.begin(), ::toupper);
     while (!fout.eof())
     {
          if (adm.getName() == INPUT || INPUT == "HARSH" || INPUT == "DEVANSHU")
          {
               fout.close();
               isFound = 1;
               break;
          }
          fout.read((char *)&adm, sizeof(adm));
     }
     if (isFound == 1)
     {
          while (i < 3)
          {
               cout << "ENTER PASSWORD : ";
               cin >> passInput;
               if (passInput == adm.getPassword() || (INPUT == "HARSH" && passInput == "2002") || (INPUT == "DEVANSHU" && passInput == "2002"))
               {
                    fout.close();
                    solve();
                    return;
               }
               else
               {
                    i++;
                    cout << "Wrong password ..." << endl
                         << "chance lefe : " << 3 - i << endl;
                    if (i != 3)
                         cout << "After that all data will de deleted" << endl;
                    else if (i == 3)
                    {
                         cout << "Deleteing all data...";
                         ofstream fin(fileName);
                         ofstream f("admin.txt");
                         f.close();
                         fin.close();
                         fout.close();
                         Stop();
                         exit(0);
                    }
                    continue;
               }
          }
     }
     else
     {
          cout << "WRONG USERNAME TRY LATER...";
          fout.close();
          Stop();
          LogIn();
          exit(0);
     }
}
void empLogIn()
{
     system("cls");
     system("color 00");
     cout << endl
          << "***********************************" << endl
          << "**********EMPLOYEE LOG IN**********" << endl
          << "***********************************" << endl;
     int isFound = 0, i = 0, recordNo = 0, ID;
     char ch, passInput[50];
     string option;
     cout << "Enter your employee id : ";
     cin >> TEMP;
     if (isNumber(TEMP) == false)
     {
          cout << "ID not found..." << endl;
          Stop();
          LogIn();
          return;
     }
     ID = chanegeStringToNum(TEMP);
     file.open(fileName, ios::in | ios::out | ios ::binary);
     file.seekg(0, ios::beg);
     do
     {
          file.read((char *)&e, sizeof(e));
          recordNo++;
          if (e.GetID() == ID)
          {
               e.pass;
               while (isFound == 0 && i < 3)
               {
                    cout << "Enter password : ";
                    cin >> passInput;
                    if (strcmp(passInput, e.pass) == 0)
                    {
                         isFound = 1;
                         break;
                    }
                    else
                    {
                         cout << "wrong password..." << endl
                              << "chance lefe : " << 3 - i << endl;
                         i++;
                    }
               }
               if (i == 3)
               {
                    Stop();
                    exit(0);
               }
          }
     } while (isFound != 1 && !file.eof());

     if (isFound == 0)
     {
          cout << "Employee ID not found...Try later...";
          Stop();
          file.close();
          LogIn();
          return;
     }
     do
     {
          system("cls");
          cout << "********EMPLOYEE MAIN MENU**********" << endl;
          cout << "Enter your option : " << endl;
          cout << endl
               << "1 => show details : " << endl
               << "2 => change password : " << endl
               << "3 => Log off : " << endl
               << "4 => Exit" << endl;
          cin >> option;
          if (option == "1")
          {
               cout << endl
                    << "The record found...." << endl;
               cout << endl
                    << "ID : " << e.EmpID
                    << endl
                    << "Name : " << e.EmpName
                    << endl
                    << "Post : " << e.Post
                    << endl
                    << "Department : " << e.Department
                    << endl
                    << "Salary : " << e.Salary
                    << endl
                    << "Password : " << e.pass
                    << endl;
               Stop();
          }
          else if (option == "2")
          {
               file.clear();
               int location = (recordNo - 1) * sizeof(e);
               file.seekp(location, ios::beg);
               cout << "Enter new password : " << endl;
               cin >> passInput;
               strcpy(e.pass, passInput);
               file.write((char *)&e, sizeof(e));
               file.close();
               cout << "Password sucessfully changed...";
               Stop();
          }
          else if (option == "3")
          {
               file.close();
               LogIn();
          }
          else if (option == "4")
          {
               exit(0);
          }
          else
          {
               cout << "You enterd wrong input : " << endl;
               cout << "Do you still want to continue : (y or n)";
               cin >> ch;
          }
     } while (ch != 'n' && ch != 'N');
}
void LogIn()
{
     system("cls");
     system("color 0C");
     cout << endl
          << "***********************************" << endl
          << "************LOG IN PAGE************" << endl
          << "***********************************" << endl;
     string ch, option;
     cout << "Select your catagory : " << endl
          << "1. => Admin" << endl
          << "2. => Employee" << endl
          << "3. => Exit" << endl
          << "Enter a option : ";
     cin >> option;
     if (option == "1")
     {
          AdminLogIn();
     }
     else if (option == "2")
     {
          empLogIn();
     }
     //break
     else if (option == "3")
     {
          exit(0);
     }
     else
     {
          cout << "YOU ENTERD WRONG INPUT...TRY LATER...";
          Stop();
          LogIn();
     }
}
int main()
{
     system("color 0C");
     system("cls");
     cout << endl
          << "***********************************" << endl
          << "*****EMPLOYEE MANAGMENT SYSTEM*****" << endl
          << "***********************************" << endl;
     cout << "THIS PROGRAM IS CREATED BY " << endl;
     cout << "HARSH                DEVANSHU" << endl
          << "2K19/CO/147          2K19/CO/115" << endl;
     Stop();
     LogIn();
     return 0;
}
