#include <iostream>
#include <string>
#include <string.h>
#include <iomanip>
#include <fstream>
#include <conio.h>
#include <cstdlib>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
using namespace std;
string CapitalizeFirstLetter(string text)
{
    for (int x = 0; x < text.length(); x++)
    {
        if (x == 0)
            text[x] = toupper(text[x]);
        else if (text[x - 1] == ' ')
            text[x] = toupper(text[x]);
        else
            text[x] = tolower(text[x]);
    }
    return text;
}
string s;
class customer
{
    string name;
    string *customerNames;
    string *carmodel;
    int index;

public:
    customer()
    {
        index = 0;
        cout << "\t\t\t\tEnter Customer Name : ";
        getline(cin, name);
        name = CapitalizeFirstLetter(name);
        fstream read("Customer.txt");
        cout << "Searching For Entered Customer";
        for (int i = 0; i < 3; i++)
        {
            cout << ".";
            sleep(1);
        }
        int i = 0;
        customerNames = new string[countLines()];
        while (!read.eof())
        {
            getline(read, customerNames[i], '\n');
            i++;
        }
        check();
    }

    int countLines()
    {
        string line;   // To read each line from code
        int count = 0; // Variable to keep count of each line
        ifstream mFile("Customer.txt");
        while (mFile.peek() != EOF)
        {
            getline(mFile, line);
            count++;
        }
        return count;
    }
    void check()
    {
        bool r;
        for (int i = 0; i <= index; i++)
        {
            if (name == customerNames[i])
            {
                r = true;
                break;
            }
            else
                r = false;
        }
        if (r == false)
            getRegistered();
        else
        {
            cout << endl
                 << "\t\t\t\t--- Customer Found ---" << endl;
            sleep(2);
            system("cls");
        }
    }
    void getRegistered()
    {
        fstream write("Customer.txt", ios::app);
        write << "\n"
              << name;
        system("cls");
        cout << "\t\t\t\t---New Customer is Registered---" << endl;
        sleep(2);
        system("cls");
    }
    string getName()
    {
        return name;
    }
    ~customer()
    {
        delete[] customerNames;
        delete[] carmodel;
    }
};

class vehical
{
    string *vehicalDriverName;
    string *vehicalName;
    string *vehicalRegNumber;
    string *vehicalEngine;
    string fileName;

public:
    int countLines(string fn)
    {
        string line;   // To read each line from code
        int count = 0; // Variable to keep count of each line
        ifstream mFile(fn);
        while (mFile.peek() != EOF)
        {
            getline(mFile, line);
            count++;
        }
        return count;
    }
    virtual void readData(string fn)
    {
        fstream read(fn);
        int i = 0;
        vehicalDriverName = new string[countLines(fn)];
        vehicalName = new string[countLines(fn)];
        vehicalRegNumber = new string[countLines(fn)];
        vehicalEngine = new string[countLines(fn)];
        while (!read.eof())
        {
            getline(read, vehicalDriverName[i], '-');
            getline(read, vehicalName[i], '-');
            getline(read, vehicalRegNumber[i], '-');
            getline(read, vehicalEngine[i], '\n');
            i++;
        }
    }
    string getVehicalDriverName(int i)
    {
        return vehicalDriverName[i];
    }
    string getVehicalName(int i)
    {
        return vehicalName[i];
    }
    string getVehicalEngine(int i)
    {
        return vehicalEngine[i];
    }
    string getVehicalRegNumber(int i)
    {
        return vehicalRegNumber[i];
    }
};

class Admin
{
    string *ID;
    string *pass;
    string driverName;
    vehical v; //   aggregate vehicle  information from vehicle class
    char choose;

public:
    bool verification()
    {
        string inID;
        string inpass;
        fstream read("Admin.txt");
        int i = 0;
        ID = new string[v.countLines("Admin.txt")];
        pass = new string[v.countLines("Admin.txt")];
        while (!read.eof())
        {
            getline(read, ID[i], '-');
            getline(read, pass[i], '\n');
            i++;
        }
        cout << "\t\t\t\t";
        s = "--- LOGIN ---";
        for (int i = 0; i < s.size(); i++)
        {
            cout << s[i];
            usleep(30000);
        }
        cout << endl
             << endl;
        cout << "\t\t\t\tID : ";
        getline(cin, inID);
        cout << "\t\t\t\tPassword : ";
        getline(cin, inpass);
        bool b;
        for (int i = 0; i < v.countLines("Admin.txt"); i++)
        {
            if (inID == ID[i] && inpass == pass[i])
            {
                b = true;
                break;
            }
            else
                b = false;
        }
        return b;
    }
    void selectOption()
    {
        do
        {
            cout << "\t\t\t\t";
            s = "--- Admin Main Menu ---";
            for (int i = 0; i < s.size(); i++)
            {
                cout << s[i];
                usleep(30000);
            }
            cout << endl
                 << endl;
            cout << "\t\t\t\t1 - Add New Employee" << endl;
            cout << "\t\t\t\t2 - Delete An Existing Employee" << endl;
            cout << "\t\t\t\t3 - Exit" << endl;
            cout << endl;

            s = "Choose>>";
            cout << endl
                 << "\t\t\t\t";
            for (int i = 0; i < s.size(); i++)
            {
                cout << s[i];
                usleep(150000);
            }
            choose = getch();
            system("cls");

            if (choose == '1')
            {
                do
                {
                    choose == '\0';
                    cout << "\t\t\t\t";
                    s = "--- Service Type ---";
                    for (int i = 0; i < s.size(); i++)
                    {
                        cout << s[i];
                        usleep(30000);
                    }
                    cout << endl
                         << endl;
                    cout << "\t\t\t\t1 - Ride" << endl;
                    cout << "\t\t\t\t2 - Delivery" << endl;
                    cout << "\t\t\t\t3 - Rent" << endl;
                    cout << endl;
                    s = "Choose>>";
                    cout << endl
                         << "\t\t\t\t";
                    for (int i = 0; i < s.size(); i++)
                    {
                        cout << s[i];
                        usleep(150000);
                    }
                    choose = getch();
                    system("cls");
                    if (choose == '1')
                    {
                        do
                        {
                            choose == '\0';
                            cout << "\t\t\t\t";
                            s = "--- Vehicle Type ---";
                            for (int i = 0; i < s.size(); i++)
                            {
                                cout << s[i];
                                usleep(30000);
                            }
                            cout << endl
                                 << endl;
                            cout << "\t\t\t\t1 - Bike" << endl;
                            cout << "\t\t\t\t2 - Car" << endl;
                            cout << endl;
                            s = "Choose>>";
                            cout << endl
                                 << "\t\t\t\t";
                            for (int i = 0; i < s.size(); i++)
                            {
                                cout << s[i];
                                usleep(150000);
                            }
                            choose = getch();
                            if (choose == '1')
                            {
                                addMember("Bikes.txt");
                                break;
                            }
                            else if (choose == '2')
                            {
                                addMember("Cars.txt");
                                break;
                            }
                            else
                            {
                                cout << endl
                                     << "\t\t\t\t--- Invalid Input ---" << endl;
                                cout << "\t\t\t\t---- Input Again ----" << endl;
                                sleep(2);
                                system("cls");
                            }
                        } while (true);
                        break;
                    }
                    else if (choose == '2')
                    {
                        addMember("HeavyVehicals.txt");
                        break;
                    }
                    else if (choose == '3')
                    {
                        addMember("RentVehicals.txt");
                        break;
                    }
                    else
                    {
                        cout << endl
                             << "\t\t\t\t--- Invalid Input ---" << endl;
                        cout << "\t\t\t\t---- Input Again ----" << endl;
                        sleep(2);
                        system("cls");
                    }
                } while (true);
                cout << "\n\t\t\t\t";
                s = "------- Successfully Added New Member -------";
                for (int i = 0; i < s.size(); i++)
                {
                    cout << s[i];
                    usleep(10000);
                }
                cout << endl;
                cout << "\t\t\t\t--- Press Any Key To Go Back To Main Manu ---";
                cout << endl;
                while (!kbhit())
                {
                    cout << "\t\t\t\t\t\t";
                    for (int i = 0; i < 3; i++)
                    {
                        cout << ".";
                        sleep(1);
                        if (kbhit())
                            break;
                    }
                    cout << "\r\t\t\t\t\t\t   \r";
                }
                getch();
                system("cls");
            }
            else if (choose == '2')
            {
                do
                {
                    choose == '\0';
                    cout << "\t\t\t\t";
                    s = "--- Service Type ---";
                    for (int i = 0; i < s.size(); i++)
                    {
                        cout << s[i];
                        usleep(30000);
                    }
                    cout << endl
                         << endl;
                    cout << "\t\t\t\t1 - Ride" << endl;
                    cout << "\t\t\t\t2 - Delivery" << endl;
                    cout << "\t\t\t\t3 - Rent" << endl;
                    cout << endl;
                    s = "Choose>>";
                    cout << endl
                         << "\t\t\t\t";
                    for (int i = 0; i < s.size(); i++)
                    {
                        cout << s[i];
                        usleep(150000);
                    }
                    choose = getch();
                    system("cls");
                    if (choose == '1')
                    {
                        do
                        {
                            choose == '\0';
                            cout << "\t\t\t\t";
                            s = "--- Vehicle Type ---";
                            for (int i = 0; i < s.size(); i++)
                            {
                                cout << s[i];
                                usleep(30000);
                            }
                            cout << endl
                                 << endl;
                            cout << "\t\t\t\t1 - Bike" << endl;
                            cout << "\t\t\t\t2 - Car" << endl;
                            cout << endl;
                            s = "Choose>>";
                            cout << endl
                                 << "\t\t\t\t";
                            for (int i = 0; i < s.size(); i++)
                            {
                                cout << s[i];
                                usleep(150000);
                            }
                            choose = getch();
                            if (choose == '1')
                            {
                                searchDriver("Bikes.txt");
                                break;
                            }
                            else if (choose == '2')
                            {
                                searchDriver("Cars.txt");
                                break;
                            }
                            else
                            {
                                cout << endl
                                     << "\t\t\t\t--- Invalid Input ---" << endl;
                                cout << "\t\t\t\t---- Input Again ----" << endl;
                                sleep(2);
                                system("cls");
                            }
                        } while (true);
                        break;
                    }
                    else if (choose == '2')
                    {
                        searchDriver("HeavyVehicals.txt");
                        break;
                    }
                    else if (choose == '3')
                    {
                        searchDriver("RentVehicals.txt");
                        break;
                    }
                    else
                    {
                        cout << endl
                             << "\t\t\t\t--- Invalid Input ---" << endl;
                        cout << "\t\t\t\t---- Input Again ----" << endl;
                        sleep(2);
                        system("cls");
                    }
                } while (true);
                system("cls");
            }
            else if (choose == '3')
                break;
            else
            {
                cout << endl
                     << "\t\t\t\t--- Invalid Input ---" << endl;
                cout << "\t\t\t\t---- Input Again ----" << endl;
                sleep(2);
                system("cls");
            }
        } while (true);
    }

    void addMember(string fn)
    {
        system("cls");
        ofstream write(fn, ios ::app);
        string data;
        cout << "\t\t\t\t";
        s = "--- Input Data ---";
        for (int i = 0; i < s.size(); i++)
        {
            cout << s[i];
            usleep(20000);
        }
        cout << endl
             << endl;
        cout << "\t\t\t\tDriver Name         : ";
        getline(cin, data);
        data = CapitalizeFirstLetter(data);
        write << "\n"
              << data << "-";
        cout << "\t\t\t\tVehicle Name        : ";
        getline(cin, data);
        data = CapitalizeFirstLetter(data);
        write << data << "-";
        cout << "\t\t\t\tRegistration Number : ";
        getline(cin, data);
        data = CapitalizeFirstLetter(data);
        write << data << "-";
        cout << "\t\t\t\tVehicle Power       : ";
        getline(cin, data);
        data = CapitalizeFirstLetter(data);
        write << data;
    }

    void searchDriver(const char *fn)
    {
        system("cls");
        v.readData(fn);
        cout << "\t\t\t\tEnter Driver Name : ";
        getline(cin, driverName);
        int index = -1;
        for (int i = 0; i < v.countLines(fn); i++)
        {
            if (driverName == v.getVehicalDriverName(i))
            {
                index = i + 1;
                break;
            }
        }
        if (index == -1)
        {
            cout << "\t\t\t\t";
            s = "----------- Driver Does Not Exist -----------";
            for (int i = 0; i < s.size(); i++)
            {
                cout << s[i];
                usleep(15000);
            }
            cout << endl;
            cout << "\t\t\t\t--- Press Any Key To Go Back To Main Menu ---";
            cout << endl;
            while (!kbhit())
            {
                cout << "\t\t\t\t\t\t";
                for (int i = 0; i < 3; i++)
                {
                    cout << ".";
                    sleep(1);
                    if (kbhit())
                        break;
                }
                cout << "\r\t\t\t\t\t\t   \r";
            }
            getch();
        }
        else
        {
            deleteMember(fn, index);
            cout << "\n\t\t\t\t";
            s = "--- Successfully Deleted Existing Member ---";
            for (int i = 0; i < s.size(); i++)
            {
                cout << s[i];
                usleep(10000);
            }
            cout << endl;
            cout << "\t\t\t\t--- Press Any Key To Go Back To Main Manu ---";
            cout << endl;
            while (!kbhit())
            {
                cout << "\t\t\t\t\t\t";
                for (int i = 0; i < 3; i++)
                {
                    cout << ".";
                    sleep(1);
                    if (kbhit())
                        break;
                }
                cout << "\r\t\t\t\t\t\t   \r";
            }
            getch();
        }
    }

    void deleteMember(const char *file_name, int n)
    {
        ifstream is(file_name);
        ofstream ofs;
        ofs.open("temp.txt", ofstream::out);

        char c;
        int line_no = 1;
        while (is.get(c))
        {
            if (c == '\n')
                line_no++;
            if (line_no != n)
                ofs << c;
        }

        ofs.close();
        is.close();

        remove(file_name);
        rename("temp.txt", file_name);
    }
};

class bike : public vehical
{
public:
    bike()
    {
        readData("Bikes.txt");
    }
};
class car : public vehical
{
    bool AC;

public:
    car()
    {
        readData("Cars.txt");
    }
    void setAC(bool a)
    {
        AC = a;
    }
};
class heavyVehicals : public vehical
{
public:
    heavyVehicals()
    {
        readData("HeavyVehicals.txt");
    }
};
class rentVehicals : public vehical
{
public:
    rentVehicals()
    {
        readData("RentVehicals.txt");
    }
};

class Inputs
{
protected:
    string destination;
    string dateTime;
    int distance;
    float charges;
    float totalCharges;
    string selectedVehical;
    string driver;
    string vehicalReg;
    string vehicalPower;
    char conformation;
    customer *c; // composition of customer information from customer class
public:
    Inputs()
    {
        destination = '\0';
        dateTime = '\0';
        distance = 0;
        charges = 0.0;
        totalCharges = 0.0;
        selectedVehical = '\0';
        driver = '\0';
        vehicalReg = '\0';
        vehicalPower = '\0';
        conformation = '\0';
    }
    void inputs()
    {
        system("cls");
        cout << endl
             << "\t\t\t\t";
        s = "--- Enter Data ---";
        for (int i = 0; i < s.size(); i++)
        {
            cout << s[i];
            usleep(150000);
        }
        cout << endl
             << endl;

        cout << "\t\t\t\tDestination : ";
        getline(cin, destination);
        destination = CapitalizeFirstLetter(destination);
    }
    void calculateCharges()
    {
        totalCharges = charges * getDistance();
    }
    void datentime()
    {
        dateTime = __TIMESTAMP__;
    }
    int getDistance()
    {
        return distance;
    }
    void setCustomer(customer *a)
    {
        c = a;
    }
    bool rideConfirmation()
    {
        do
        {
            system("cls");
            s = "--- Confirmation ---";
            cout << endl
                 << endl
                 << "\t\t\t\t";
            for (int i = 0; i < s.size(); i++)
            {
                cout << s[i];
                usleep(150000);
            }
            cout << endl;
            cout << "\t\t\t\t1- Confirm" << endl;
            cout << "\t\t\t\t2- Cancel" << endl;
            s = "Choose>>";
            cout << endl
                 << "\t\t\t\t";
            for (int i = 0; i < s.size(); i++)
            {
                cout << s[i];
                usleep(150000);
            }
            conformation = getch();
            if (conformation == '1')
            {
                datentime();
                return true;
            }
            else if (conformation == '2')
            {
                return false;
            }
            else
            {
                cout << endl
                     << "\t\t\t\t--- Invalid Input ---" << endl;
                cout << "\t\t\t\t---- Input Again ----" << endl;
                sleep(2);
                system("cls");
            }
        } while (true);
    }
};

class Ride : public Inputs
{
    string picloc; // pickup location
    bike b;        // aggregate bike information from bike class
    car C;         // aggregate car information from car class
    char ride;

public:
    void chooseRide()
    {
        do
        {
            cout << endl;
            cout << "\t\t\t\t--- Select A Ride ---" << endl
                 << endl;
            cout << "\t\t\t\t1- Bike" << endl;
            cout << "\t\t\t\t2- Car" << endl;
            cout << endl
                 << "\t\t\t\t";
            s = "Choose>>";
            cout << endl
                 << "\t\t\t\t";
            for (int i = 0; i < s.size(); i++)
            {
                cout << s[i];
                usleep(150000);
            }
            ride = getch();
            if (ride == '1')
            {
                inputs();
                cout << "\t\t\t\tPickup Location : ";
                getline(cin, picloc);
                picloc = CapitalizeFirstLetter(picloc);
                cout << "\t\t\t\tDistance : ";
                cin >> distance;
                cin.ignore(1, '\n');
                charges = 12.9;
                selectBike();
                calculateCharges();
                break;
            }
            else if (ride == '2')
            {
                inputs();
                cout << "\t\t\t\tPickup Location : ";
                getline(cin, picloc);
                picloc = CapitalizeFirstLetter(picloc);
                cout << "\t\t\t\tDistance : ";
                cin >> distance;
                cin.ignore(1, '\n');
                charges = 30.5;
                selectCar();
                calculateCharges();
                break;
            }
            else
            {
                cout << endl
                     << "\t\t\t\t--- Invalid Input ---" << endl;
                cout << "\t\t\t\t---- Input Again ----" << endl;
                sleep(2);
                system("cls");
            }
        } while (true);
    }
    void selectBike()
    {
        int lines = b.countLines("Bikes.txt");
        srand(time(0));
        int free = (rand() % lines);
        int pos[free] = {0};
        int t = 1;
        cout << "Searching For Available Rides";
        for (int i = 0; i < 3; i++)
        {
            cout << ".";
            sleep(1);
        }
        system("cls");
        cout << endl;
        cout << "\t\t\t\t---Available Rides Are---" << endl
             << endl;
        for (int i = 0; i < free; i++)
        {
            int temp = (rand() % free) + 1;
            for (int j = 0; j <= i; j++)
            {
                if (temp == pos[j])
                {
                    t = 2;
                    break;
                }
                else
                    t = 1;
            }
            if (t == 2)
            {
                i--;
            }
            else
            {
                pos[i] = temp;
                cout << "\t\t\t\t" << i + 1 << "-" << b.getVehicalDriverName(temp) << "\t\t"
                     << b.getVehicalName(temp) << "\t"
                     << b.getVehicalRegNumber(temp) << "\t"
                     << b.getVehicalEngine(temp) << endl;
            }
        }
        int choose;
        s = "Choose>>";
        cout << endl
             << "\t\t\t\t";
        for (int i = 0; i < s.size(); i++)
        {
            cout << s[i];
            usleep(150000);
        }
        cin >> choose;
        cin.ignore(1, '\n');
        int in = pos[choose - 1];
        selectedVehical = b.getVehicalName(in);
        driver = b.getVehicalDriverName(in);
        vehicalReg = b.getVehicalRegNumber(in);
        vehicalPower = b.getVehicalEngine(in);
    }
    void selectCar()
    {
        int lines = C.countLines("Cars.txt");
        srand(time(0));
        int free = (rand() % lines);
        int pos[free] = {0};
        int t = 1;
        cout << "Searching For Available Rides";
        for (int i = 0; i < 3; i++)
        {
            cout << ".";
            sleep(1);
        }
        system("cls");
        cout << endl;
        cout << "\t\t\t\t---Available Rides Are---" << endl
             << endl;
        for (int i = 0; i < free; i++)
        {
            int temp = (rand() % free) + 1;
            for (int j = 0; j <= i; j++)
            {
                if (temp == pos[j])
                {
                    t = 2;
                    break;
                }
                else
                    t = 1;
            }
            if (t == 2)
            {
                i--;
            }
            else
            {
                pos[i] = temp;
                cout << "\t\t\t\t" << i + 1 << "-" << C.getVehicalDriverName(temp) << "\t\t"
                     << C.getVehicalName(temp) << "\t"
                     << C.getVehicalRegNumber(temp) << "\t"
                     << C.getVehicalEngine(temp) << endl;
            }
        }

        int choose;
        s = "Choose>>";
        cout << endl
             << "\t\t\t\t";
        for (int i = 0; i < s.size(); i++)
        {
            cout << s[i];
            usleep(150000);
        }
        cin >> choose;
        cin.ignore(1, '\n');
        int in = pos[choose - 1];
        selectedVehical = C.getVehicalName(in);
        driver = C.getVehicalDriverName(in);
        vehicalReg = C.getVehicalRegNumber(in);
        vehicalPower = C.getVehicalEngine(in);
        char ac;
        do
        {
            cout << endl;
            cout << "\t\t\t\tAC : \n\t\t\t\t1- ON \n\t\t\t\t2- OFF" << endl
                 << endl
                 << "\t\t\t\t";
            s = "Choose>>";
            cout << endl
                 << "\t\t\t\t";
            for (int i = 0; i < s.size(); i++)
            {
                cout << s[i];
                usleep(150000);
            }
            ac = getch();
            if (ac == '1')
            {
                C.setAC(true);
                ACcharges();
                break;
            }
            else if (ac == '2')
            {
                C.setAC(false);
                break;
            }
            else
            {
                cout << endl
                     << "\t\t\t\t--- Invalid Input ---" << endl;
                cout << "\t\t\t\t---- Input Again ----" << endl;
                sleep(2);
                system("cls");
            }
        } while (true);
    }
    void ACcharges()
    {
        totalCharges = totalCharges + 10 * getDistance();
    }
    void printRideRecipt()
    {
        int random_integer;
        int lowest = 9999, highest = 65389;
        int range = (highest - lowest) + 1;
        random_integer = lowest + int(range * rand() / (RAND_MAX + 1.0));
        cout << "\n\t\t                       CHALLO CHALIEN - Customer Invoice                  " << endl;
        cout << "\t\t	| Service        :" << " ------------------ |" << "    Ride" << endl;
        cout << "\t\t	| Date and Time  :" << " ------------------ |" << "    " << dateTime << endl;
        cout << "\t\t	////////////////////////////////////////////////////////////////////" << endl;
        cout << "\t\t	| Invoice No.    :" << " ------------------ |" << "    " << " #Cnb" << random_integer << endl;
        cout << "\t\t	| Customer Name  :" << " ------------------ |" << "    " << c->getName() << endl;
        cout << "\t\t	| Driver Name    :" << " ------------------ |" << "    " << driver << endl;
        cout << "\t\t	| Vehicle Model  :" << " ------------------ |" << "    " << selectedVehical << endl;
        cout << "\t\t	| Vehical No.    :" << " ------------------ |" << "    " << vehicalReg << endl;
        cout << "\t\t	| Engine Power   :" << " ------------------ |" << "    " << vehicalPower << endl;
        cout << "\t\t	| Distance       :" << " ------------------ |" << "    " << getDistance() << endl;
        cout << "\t\t	| Charges per km :" << " ------------------ |" << "    " << "Rs." << charges << endl;
        if (ride == '2')
            cout << "\t\t	| AC Charges     :" << " ------------------ |" << "    " << "Rs.10" << endl;
        cout << "\t\t	 ___________________________________________________________________" << endl;
        cout << "\n";
        cout << "\t\t	| Total Amount   :" << " ------------------ |" << "    " << "Rs." << totalCharges << endl;
        cout << "\t\t	 ___________________________________________________________________" << endl;
        cout << "\t\t	 # This is a computer generated invoce and it does not" << endl;
        cout << "\t\t	 require an authorised signture #" << endl;
        cout << " " << endl;
        cout << "\t\t	////////////////////////////////////////////////////////////////////" << endl;

        //-------------------------------Writimg------------------------------------------

        string reciptName = "#Cnb" + to_string(random_integer) + "_Ride_" + c->getName() + ".txt"; // concatenation
        ofstream out;
        out.open(reciptName);
        out << "\n\t\t                       CHALLO CHALIEN - Customer Invoice                  " << endl;
        out << "\t\t	| Service        :" << " ------------------ |" << "    Ride" << endl;
        out << "\t\t	| Date and Time  :" << " ------------------ |" << "    " << dateTime << endl;
        out << "\t\t	////////////////////////////////////////////////////////////////////" << endl;
        out << "\t\t	| Invoice No.    :" << " ------------------ |" << "    " << " #Cnb" << random_integer << endl;
        out << "\t\t	| Customer Name  :" << " ------------------ |" << "    " << c->getName() << endl;
        out << "\t\t	| Driver Name    :" << " ------------------ |" << "    " << driver << endl;
        out << "\t\t	| Vehicle Model  :" << " ------------------ |" << "    " << selectedVehical << endl;
        out << "\t\t	| Vehical No.    :" << " ------------------ |" << "    " << vehicalReg << endl;
        out << "\t\t	| Engine Power   :" << " ------------------ |" << "    " << vehicalPower << endl;
        out << "\t\t	| Distance       :" << " ------------------ |" << "    " << getDistance() << endl;
        out << "\t\t	| Charges per km :" << " ------------------ |" << "    " << "Rs." << charges << endl;
        if (ride == '2')
            out << "\t\t	| AC Charges     :" << " ------------------ |" << "    " << "Rs.10" << endl;
        out << "\t\t	 ___________________________________________________________________" << endl;
        out << "\n";
        out << "\t\t	| Total Amount   :" << " ------------------ |" << "    " << "Rs." << totalCharges << endl;
        out << "\t\t	 ___________________________________________________________________" << endl;
        out << "\t\t	 # This is a computer generated invoce and it does not" << endl;
        out << "\t\t	 require an authorised signture #" << endl;
        out << " " << endl;
        out << "\t\t	////////////////////////////////////////////////////////////////////" << endl;
        cout << endl
             << "\t\t\t\t";
        s = "--- Recipt Has Also Been Saved On Computer ---";
        for (int i = 0; i < s.size(); i++)
        {
            cout << s[i];
            usleep(150000);
        }
        cout << endl;
        cout << "\t\t\t\t--- Press Any Key To Go Back To Main Manu ---";
        cout << endl;
        while (!kbhit())
        {
            cout << "\t\t\t\t\t\t";
            for (int i = 0; i < 3; i++)
            {
                cout << ".";
                sleep(1);
                if (kbhit())
                    break;
            }
            cout << "\r\t\t\t\t\t\t   \r";
        }
        getch();
        system("cls");
    }
};
class Delivery : public Inputs
{
    string picloc;
    string goodsType;
    heavyVehicals v;

public:
    void getData()
    {
        inputs();
        cout << "\t\t\t\tPickup Location : ";
        getline(cin, picloc);
        picloc = CapitalizeFirstLetter(picloc);
        cout << "\t\t\t\tDistance : ";
        cin >> distance;
        cin.ignore(1, '\n');
        cout << "\t\t\t\tGoods Type : ";
        getline(cin, goodsType);
        goodsType = CapitalizeFirstLetter(goodsType);
        charges = 20.4;
        calculateCharges();
        selectVehical();
    }
    void selectVehical()
    {
        int lines = v.countLines("heavyVehicals.txt");
        srand(time(0));
        int free = (rand() % lines);
        int pos[free] = {0};
        int t = 1;
        cout << "Searching For Available Vehicals";
        for (int i = 0; i < 3; i++)
        {
            cout << ".";
            sleep(1);
        }
        system("cls");
        cout << endl;
        cout << "\t\t\t\t--- Available Vehicals Are ---" << endl
             << endl;
        for (int i = 0; i < free; i++)
        {
            int temp = (rand() % free) + 1;
            for (int j = 0; j <= i; j++)
            {
                if (temp == pos[j])
                {
                    t = 2;
                    break;
                }
                else
                    t = 1;
            }
            if (t == 2)
            {
                i--;
            }
            else
            {
                pos[i] = temp;
                cout << "\t\t\t\t" << i + 1 << "-" << v.getVehicalDriverName(temp) << "\t\t"
                     << v.getVehicalName(temp) << "\t"
                     << v.getVehicalRegNumber(temp) << "\t"
                     << v.getVehicalEngine(temp) << endl;
            }
        }
        s = "Choose>>";
        cout << endl
             << "\t\t\t\t";
        for (int i = 0; i < s.size(); i++)
        {
            cout << s[i];
            usleep(150000);
        }
        int choose;
        cin >> choose;
        cin.ignore(1, '\n');
        int in = pos[choose - 1];
        selectedVehical = v.getVehicalName(in);
        driver = v.getVehicalDriverName(in);
        vehicalReg = v.getVehicalRegNumber(in);
        vehicalPower = v.getVehicalEngine(in);
    }

    void printRideRecipt()
    {
        int random_integer;
        int lowest = 9999, highest = 65389;
        int range = (highest - lowest) + 1;
        random_integer = lowest + int(range * rand() / (RAND_MAX + 1.0));
        cout << "\n\t\t                       CHALLO CHALIEN - Customer Invoice                  " << endl;
        cout << "\t\t	| Service        :" << " ------------------- |" << "    Delivery" << endl;
        cout << "\t\t	| Goods Type     :" << " ------------------- |" << "    " << goodsType << endl;
        cout << "\t\t	| Date and Time  :" << " ------------------- |" << "    " << dateTime << endl;
        cout << "\t\t	////////////////////////////////////////////////////////////////////" << endl;
        cout << "\t\t	| Invoice No.    :" << " ------------------- |" << "    #Cnb" << random_integer << endl;
        cout << "\t\t	| Customer Name  :" << " ------------------- |" << "    " << c->getName() << endl;
        cout << "\t\t	| Driver Name    :" << " ------------------- |" << "    " << driver << endl;
        cout << "\t\t	| Vehicle Model  :" << " ------------------- |" << "    " << selectedVehical << endl;
        cout << "\t\t	| Vehical No.    :" << " ------------------- |" << "    " << vehicalReg << endl;
        cout << "\t\t	| Distance       :" << " ------------------- |" << "    " << getDistance() << endl;
        cout << "\t\t	| Charges per km :" << " ------------------- |" << "    " << "Rs." << charges << endl;
        cout << "\t\t	 ___________________________________________________________________" << endl;
        cout << "\n";
        cout << "\t\t	| Total Amount   :" << " ------------------- |" << "    " << "Rs." << totalCharges << endl;
        cout << "\t\t	 ___________________________________________________________________" << endl;
        cout << "\t\t	 # This is a computer generated invoce and it does not" << endl;
        cout << "\t\t	 require an authorised signture #" << endl;
        cout << " " << endl;
        cout << "\t\t	////////////////////////////////////////////////////////////////////" << endl;

        //-------------------------------Writimg------------------------------------------

        string reciptName = "#Cnb" + to_string(random_integer) + "_Delivery_" + c->getName() + ".txt";
        ofstream out;
        out.open(reciptName);
        out << "\n\t\t                       CHALLO CHALIEN - Customer Invoice                  " << endl;
        out << "\t\t	| Service        :" << " ------------------- |" << "    Delivery" << endl;
        out << "\t\t	| Goods Type     :" << " ------------------- |" << "    " << goodsType << endl;
        out << "\t\t	| Date and Time  :" << " ------------------- |" << "    " << dateTime << endl;
        out << "\t\t	////////////////////////////////////////////////////////////////////" << endl;
        out << "\t\t	| Invoice No.    :" << " ------------------- |" << "    #Cnb" << random_integer << endl;
        out << "\t\t	| Customer Name  :" << " ------------------- |" << "    " << c->getName() << endl;
        out << "\t\t	| Driver Name    :" << " ------------------- |" << "    " << driver << endl;
        out << "\t\t	| Vehicle Model  :" << " ------------------- |" << "    " << selectedVehical << endl;
        out << "\t\t	| Vehical No.    :" << " ------------------- |" << "    " << vehicalReg << endl;
        out << "\t\t	| Distance       :" << " ------------------- |" << "    " << getDistance() << endl;
        out << "\t\t	| Charges per km :" << " ------------------- |" << "    " << "Rs." << charges << endl;
        out << "\t\t	 ___________________________________________________________________" << endl;
        out << "\n";
        out << "\t\t	| Total Amount   :" << " ------------------- |" << "    " << "Rs." << totalCharges << endl;
        out << "\t\t	 ___________________________________________________________________" << endl;
        out << "\t\t	 # This is a computer generated invoce and it does not" << endl;
        out << "\t\t	 require an authorised signture #" << endl;
        out << " " << endl;
        out << "\t\t	////////////////////////////////////////////////////////////////////" << endl;

        cout << endl
             << "\t\t\t\t";
        s = "--- Recipt Has Also Been Saved On Computer ---";
        for (int i = 0; i < s.size(); i++)
        {
            cout << s[i];
            usleep(150000);
        }
        cout << endl;
        cout << "\t\t\t\t--- Press Any Key To Go Back To Main Manu ---";
        cout << endl;
        while (!kbhit())
        {
            cout << "\t\t\t\t\t\t";
            for (int i = 0; i < 3; i++)
            {
                cout << ".";
                sleep(1);
                if (kbhit())
                    break;
            }
            cout << "\r\t\t\t\t\t\t   \r";
        }
        getch();
        system("cls");
    }
};
class Rent : public Inputs
{
    bool outOfCity;
    string CNIC;
    string phoneNo;
    rentVehicals re; // aggregate rentVehicals information from rentVehicals class
public:
    void getData()
    {
        system("cls");
        inputs();
        do
        {
            cout << "\t\t\t\tScope : " << endl;
            cout << "\t\t\t\t1- Within The City" << endl;
            cout << "\t\t\t\t2- Out Of City" << endl
                 << "\t\t\t\t";
            char c = getche();
            cout << endl;
            if (c == '1')
            {
                outOfCity = true;
                break;
            }
            else if (c == '2')
            {
                outOfCity = false;
                break;
            }
            else
            {
                cout << endl
                     << "\t\t\t\t--- Invalid Input ---" << endl;
                cout << "\t\t\t\t---- Input Again ----" << endl;
                sleep(2);
                system("cls");
            }
        } while (true);
        cout << "\t\t\t\tNo of Days : ";
        cin >> distance;
        cin.ignore(1, '\n');
        cout << "\t\t\t\tCNIC : ";
        getline(cin, CNIC);
        cout << "\t\t\t\tPhone Number : ";
        getline(cin, phoneNo);
        if (outOfCity == false)
            charges = 3000;
        else
            charges = 5000;
        calculateCharges();
    }
    void selectVehical()
    {
        int lines = re.countLines("heavyVehicals.txt");
        srand(time(0));
        int free = (rand() % lines);
        int pos[free] = {0};
        int t = 1;
        cout << "Searching For Available Vehicals";
        for (int i = 0; i < 3; i++)
        {
            cout << ".";
            sleep(1);
        }
        system("cls");
        cout << endl;
        cout << "\t\t\t\t--- Available Vehicals Are ---" << endl
             << endl;
        for (int i = 0; i < free; i++)
        {
            int temp = (rand() % free) + 1;
            for (int j = 0; j <= i; j++)
            {
                if (temp == pos[j])
                {
                    t = 2;
                    break;
                }
                else
                    t = 1;
            }
            if (t == 2)
            {
                i--;
            }
            else
            {
                pos[i] = temp;
                cout << "\t\t\t\t" << i + 1 << "- " << re.getVehicalName(temp) << "\t\t"
                     << re.getVehicalRegNumber(temp) << "\t"
                     << re.getVehicalEngine(temp) << endl;
            }
        }
        s = "Choose>>";
        cout << endl
             << "\t\t\t\t";
        for (int i = 0; i < s.size(); i++)
        {
            cout << s[i];
            usleep(150000);
        }
        int choose;
        cin >> choose;
        cin.ignore(1, '\n');
        int in = pos[choose - 1];
        selectedVehical = re.getVehicalName(in);
        driver = re.getVehicalDriverName(in);
        vehicalReg = re.getVehicalRegNumber(in);
        vehicalPower = re.getVehicalEngine(in);
        getData();
    }

    void printRentRecipt()
    {
        int random_integer;
        int lowest = 9999, highest = 65389;
        int range = (highest - lowest) + 1;
        random_integer = lowest + int(range * rand() / (RAND_MAX + 1.0));
        cout << "\n\t\t                       CHALLO CHALIEN - Customer Invoice                  " << endl;
        cout << "\t\t	| Service        :" << " ------------------- |" << "    Rent" << endl;
        cout << "\t\t	| Date and Time  :" << " ------------------- |" << "    " << dateTime << endl;
        cout << "\t\t	////////////////////////////////////////////////////////////////////" << endl;
        cout << "\t\t	| Invoice No.    :" << " ------------------- |" << "    #Cnb" << random_integer << endl;
        cout << "\t\t	| Customer Name  :" << " ------------------- |" << "    " << c->getName() << endl;
        cout << "\t\t	| Vehicle Model  :" << " ------------------- |" << "    " << selectedVehical << endl;
        cout << "\t\t	| Vehical No.    :" << " ------------------- |" << "    " << vehicalReg << endl;
        cout << "\t\t	| Customer CNIC  :" << " ------------------- |" << "    " << CNIC << endl;
        cout << "\t\t	| Phone No.      :" << " ------------------- |" << "    " << phoneNo << endl;
        cout << "\t\t	| Days For Rent  :" << " ------------------- |" << "    " << getDistance() << endl;
        cout << "\t\t	| Charges per km :" << " ------------------- |" << "    " << "Rs." << charges << endl;
        cout << "\t\t	 ___________________________________________________________________" << endl;
        cout << "\n";
        cout << "\t\t	| Total Amount   :" << " ------------------- |" << "    " << "Rs." << totalCharges << endl;
        cout << "\t\t	 ___________________________________________________________________" << endl;
        cout << "\t\t	 # This is a computer generated invoce and it does not" << endl;
        cout << "\t\t	 require an authorised signture #" << endl;
        cout << " " << endl;
        cout << "\t\t	////////////////////////////////////////////////////////////////////" << endl;

        //-------------------------------Writimg------------------------------------------

        string reciptName = "#Cnb" + to_string(random_integer) + "_Delivery_" + c->getName() + ".txt";
        ofstream out;
        out.open(reciptName);
        out << "\n\t\t                       CHALLO CHALIEN - Customer Invoice                  " << endl;
        out << "\t\t	| Service        :" << " ------------------- |" << "    Rent" << endl;
        out << "\t\t	| Date and Time  :" << " ------------------- |" << "    " << dateTime << endl;
        out << "\t\t	////////////////////////////////////////////////////////////////////" << endl;
        out << "\t\t	| Invoice No.    :" << " ------------------- |" << "    #Cnb" << random_integer << endl;
        out << "\t\t	| Customer Name  :" << " ------------------- |" << "    " << c->getName() << endl;
        out << "\t\t	| Vehicle Model  :" << " ------------------- |" << "    " << selectedVehical << endl;
        out << "\t\t	| Vehical No.    :" << " ------------------- |" << "    " << vehicalReg << endl;
        out << "\t\t	| Customer CNIC  :" << " ------------------- |" << "    " << CNIC << endl;
        out << "\t\t	| Phone No.      :" << " ------------------- |" << "    " << phoneNo << endl;
        out << "\t\t	| Days For Rent  :" << " ------------------- |" << "    " << getDistance() << endl;
        out << "\t\t	| Charges per km :" << " ------------------- |" << "    " << "Rs." << charges << endl;
        out << "\t\t	 ___________________________________________________________________" << endl;
        out << "\n";
        out << "\t\t	| Total Amount   :" << " ------------------- |" << "    " << "Rs." << totalCharges << endl;
        out << "\t\t	 ___________________________________________________________________" << endl;
        out << "\t\t	 # This is a computer generated invoce and it does not" << endl;
        out << "\t\t	 require an authorised signture #" << endl;
        out << " " << endl;
        out << "\t\t	////////////////////////////////////////////////////////////////////" << endl;
        cout << endl
             << "\t\t\t\t";
        s = "--- Recipt Has Also Been Saved On Computer ---";
        for (int i = 0; i < s.size(); i++)
        {
            cout << s[i];
            usleep(150000);
        }
        cout << endl;
        cout << "\t\t\t\t--- Press Any Key To Go Back To Main Manu ---";
        cout << endl;
        while (!kbhit())
        {
            cout << "\t\t\t\t\t\t";
            for (int i = 0; i < 3; i++)
            {
                cout << ".";
                sleep(1);
                if (kbhit())
                    break;
            }
            cout << "\r\t\t\t\t\t\t   \r";
        }
        getch();
        system("cls");
    }
};
class Service
{
    customer *cus;
    Ride r;
    Delivery d;
    Rent rent;

public:
    void selectService()
    {
        do
        {
            cout << "\t\t\t\t";
            s = "--- Main Menu ---";
            for (int i = 0; i < s.size(); i++)
            {
                cout << s[i];
                usleep(100000);
            }
            cout << endl
                 << "Loading";
            for (int i = 0; i < 3; i++)
            {
                cout << ".";
                sleep(1);
            }
            cout << "\r          " << endl
                 << endl;
            cout << "\t\t\t\t1-Book A Ride" << endl;
            cout << "\t\t\t\t2-Send A Delivery" << endl;
            cout << "\t\t\t\t3-Rent A Vehical" << endl;
            cout << "\t\t\t\t4-Exit" << endl;
            cout << endl;
            s = "Choose>>";
            cout << endl
                 << "\t\t\t\t";
            for (int i = 0; i < s.size(); i++)
            {
                cout << s[i];
                usleep(150000);
            }
            char choose = getch();
            if (choose == '1')
            {
                system("cls");
                r.setCustomer(cus);
                r.chooseRide();
                if (r.rideConfirmation() == true)
                {
                    system("cls");
                    cout << "Calculating Charges";
                    sleep(1);
                    for (int i = 0; i < 3; i++)
                    {
                        cout << ".";
                        sleep(1);
                    }
                    system("cls");
                    cout << endl
                         << "\t\t\t\t";
                    s = "--- Your Ride Has Been Booked ---";
                    for (int i = 0; i < s.size(); i++)
                    {
                        cout << s[i];
                        usleep(150000);
                    }
                    cout << endl
                         << endl;
                    cout << "Printing Slip";
                    sleep(1);
                    for (int i = 0; i < 3; i++)
                    {
                        cout << ".";
                        sleep(1);
                    }
                    cout << "\r                " << endl;
                    r.printRideRecipt();
                }
                else
                {
                    cout << endl
                         << "\t\t\t\t";
                    s = "--------- Your Ride Has Been Cancelled ---------";
                    for (int i = 0; i < s.size(); i++)
                    {
                        cout << s[i];
                        usleep(150000);
                    }
                    cout << endl;
                    cout << "\t\t\t\t--- Press Any Key To Go Back To Manu ---" << endl;
                    while (!kbhit())
                    {
                        cout << "\t\t\t\t\t\t";
                        for (int i = 0; i < 3; i++)
                        {
                            cout << ".";
                            sleep(1);
                            if (kbhit())
                                break;
                        }
                        cout << "\r\t\t\t\t\t\t   \r";
                    }
                    getch();
                    system("cls");
                }
            }
            else if (choose == '2')
            {
                system("cls");
                d.setCustomer(cus);
                d.getData();
                if (d.rideConfirmation() == true)
                {
                    system("cls");
                    cout << "Calculating Charges";
                    sleep(1);
                    for (int i = 0; i < 3; i++)
                    {
                        cout << ".";
                        sleep(1);
                    }
                    system("cls");
                    cout << endl
                         << "\t\t\t\t";
                    s = "-------- Your Delivey Has Been Confirmed --------";
                    for (int i = 0; i < s.size(); i++)
                    {
                        cout << s[i];
                        usleep(100000);
                    }
                    cout << endl
                         << "\t\t\t\t";
                    s = "--- The Driver Will Be At Pickup Location Soon ---";
                    for (int i = 0; i < s.size(); i++)
                    {
                        cout << s[i];
                        usleep(100000);
                    }
                    cout << endl
                         << endl;
                    cout << "Printing Slip";
                    sleep(1);
                    for (int i = 0; i < 3; i++)
                    {
                        cout << ".";
                        sleep(1);
                    }
                    cout << "\r                " << endl;
                    d.printRideRecipt();
                }
                else
                {
                    cout << endl
                         << "\t\t\t\t";
                    s = "----- Your Delivery Has Been Cancelled -----";
                    for (int i = 0; i < s.size(); i++)
                    {
                        cout << s[i];
                        usleep(150000);
                    }
                    cout << "----- Press Any Key To Go Back To Manu -----" << endl;
                    while (!kbhit())
                    {
                        cout << "\t\t\t\t\t\t";
                        for (int i = 0; i < 3; i++)
                        {
                            cout << ".";
                            sleep(1);
                            if (kbhit())
                                break;
                        }
                        cout << "\r\t\t\t\t\t\t   \r";
                    }
                    getch();
                    system("cls");
                }
            }
            else if (choose == '3')
            {
                system("cls");
                rent.setCustomer(cus);
                rent.selectVehical();
                if (rent.rideConfirmation() == true)
                {
                    system("cls");
                    cout << "Calculating Charges";
                    sleep(1);
                    for (int i = 0; i < 3; i++)
                    {
                        cout << ".";
                        sleep(1);
                    }
                    system("cls");
                    cout << endl
                         << "\t\t\t\t";
                    s = "--------------- You Have Successfully Rented A Vehical ---------------";
                    for (int i = 0; i < s.size(); i++)
                    {
                        cout << s[i];
                        usleep(100000);
                    }
                    cout << endl
                         << "\t\t\t\t";
                    s = "--- You Can Collect Your Vehical From Nearby Chalo Chalian Workshop ---";
                    for (int i = 0; i < s.size(); i++)
                    {
                        cout << s[i];
                        usleep(100000);
                    }
                    cout << endl
                         << endl;
                    cout << "Printing Slip";
                    sleep(1);
                    for (int i = 0; i < 3; i++)
                    {
                        cout << ".";
                        sleep(1);
                    }
                    cout << "\r                " << endl;
                    rent.printRentRecipt();
                }
                else
                {
                    cout << endl
                         << "\t\t\t\t";
                    s = "--- You Request To Rent A Vehical Has Been Canceled ---";
                    for (int i = 0; i < s.size(); i++)
                    {
                        cout << s[i];
                        usleep(150000);
                    }
                    cout << endl
                         << "\t\t\t\t";
                    cout << "----------- Press Any Key To Go Back To Manu -----------";
                    cout << endl;
                    while (!kbhit())
                    {
                        cout << "\t\t\t\t\t\t";
                        for (int i = 0; i < 3; i++)
                        {
                            cout << ".";
                            sleep(1);
                            if (kbhit())
                                break;
                        }
                        cout << "\r\t\t\t\t\t\t   \r";
                    }
                    getch();
                    system("cls");
                }
            }
            else if (choose == '4')
            {
                system("cls");
                break;
            }
            else
            {
                cout << endl
                     << "\t\t\t\t--- Invalid Input ---" << endl;
                cout << "\t\t\t\t---- Input Again ----" << endl;
                sleep(2);
                system("cls");
            }
        } while (true);
    }
    void setCus(customer *c) // set the customer
    {
        cus = c;
    }
};
int main()
{

    char select;
    {
        cout << "\t\t\t\t\t\t--- Welcome To ---" << endl
             << endl;
        cout << setw(10) << setfill(' ');
        s = "               _____ _           _ _          _____ _           _ _       _       ";
        for (int i = 0; i < s.size(); i++)
        {
            cout << s[i];
            usleep(10000);
        }
        cout << endl;
        cout << setw(10) << setfill(' ');
        s = "              / ____| |         | | |        / ____| |         | | |     (_)      ";
        for (int i = 0; i < s.size(); i++)
        {
            cout << s[i];
            usleep(10000);
        }

        cout << endl;
        cout << setw(10) << setfill(' ');
        s = "             | |    | |__   __ _| | | ___   | |    | |__   __ _| | | __ _ _ _ __  ";
        for (int i = 0; i < s.size(); i++)
        {
            cout << s[i];
            usleep(10000);
        }
        cout << endl;
        cout << setw(10) << setfill(' ');
        s = "             | |    | '_ \\ / _` | | |/ _ \\  | |    | '_ \\ / _` | | |/ _` | | '_ \\ ";
        for (int i = 0; i < s.size(); i++)
        {
            cout << s[i];
            usleep(10000);
        }
        cout << endl;
        cout << setw(10) << setfill(' ');
        s = "             | |____| | | | (_| | | | (_) | | |____| | | | (_| | | | (_| | | | | |";
        for (int i = 0; i < s.size(); i++)
        {
            cout << s[i];
            usleep(10000);
        }
        cout << endl;
        cout << setw(10) << setfill(' ');
        s = "              \\_____|_| |_|\\__,_|_|_|\\___/   \\_____|_| |_|\\__,_|_|_|\\__,_|_|_| |_|";
        for (int i = 0; i < s.size(); i++)
        {
            cout << s[i];
            usleep(10000);
        }
        cout << endl;
        cout << endl
             << "\t\t\t\t\t--- Press Any Key To Continue ---" << endl;
        while (!kbhit())
        {
            cout << "\t\t\t\t\t\t\t";
            for (int i = 0; i < 3; i++)
            {
                cout << ".";
                sleep(1);
                if (kbhit())
                    break;
            }
            cout << "\r\t\t\t\t\t\t\t   \r";
        }
        getch();
        system("cls");
    }
    cout << "\t\t\t--->>> Complete Menu Of Challo Challain <<<--- \n\t\t\t\t\t (TRANSPORT SYSTEM)\n";
    cout << "\t\tModes: \n \t\t\t1: Admin \n";
    cout << "\t\t\t\t1: Add New Employee \n\n";
    cout << "\t\t\t\t--- SERVICES TYPES ---\n";
    cout << "\t\t\t\t\t1: Ride \n";
    cout << "\t\t\t\t\t2: Delivery \n";
    cout << "\t\t\t\t\t3: Rent \n";
    cout << "\t\t\t\t2: Delete an Existing Employee\n";
    cout << "\t\t\t2: Customer \n";
    cout << "\t\t\t\t1: Book a Ride \n";
    cout << "\t\t\t\t\t1: Bike \n";
    cout << "\t\t\t\t\t2: Car \n";
    cout << "\t\t\t\t2: Send a Delivery \n";
    cout << "\t\t\t\t3: Rent a Vehicle \n";
    getch();
    system("cls");
    do
    {
        cout << "\t\t\t\t";
        s = "--- Select Mode ---";
        for (int i = 0; i < s.size(); i++)
        {
            cout << s[i];
            usleep(30000);
        }
        cout << endl
             << endl;
        cout << "\t\t\t\t1 - Admin" << endl;
        cout << "\t\t\t\t2 - Customer" << endl;
        cout << "\t\t\t\t3 - Exit" << endl;
        cout << endl;
        s = "Choose>>";
        cout << endl
             << "\t\t\t\t";
        for (int i = 0; i < s.size(); i++)
        {
            cout << s[i];
            usleep(150000);
        }
        select = getch();
        system("cls");
        if (select == '1')
        {
            Admin a;

            if (a.verification() == true)
            {
                system("cls");
                cout << "\t\t\t\t";
                s = "--- Login Succesfull ---";
                for (int i = 0; i < s.size(); i++)
                {
                    cout << s[i];
                    usleep(30000);
                }
                cout << endl
                     << endl;
                s = "Loading";
                for (int i = 0; i < s.size(); i++)
                {
                    cout << s[i];
                    usleep(20000);
                }
                for (int i = 0; i < 6; i++)
                {
                    cout << ".";
                    sleep(1);
                    if (i == 2)
                    {
                        cout << "\b\b\b   \b\b\b";
                    }
                }
                system("cls");
                a.selectOption();
            }
            else
            {
                system("cls");
                cout << "\t\t\t\t";
                s = "--- Login Fail ---";
                for (int i = 0; i < s.size(); i++)
                {
                    cout << s[i];
                    usleep(50000);
                }
                sleep(2);
                system("cls");
            }
        }
        else if (select == '2')
        {
            customer c;
            Service s;
            s.setCus(&c);
            s.selectService();
        }
        else if (select == '3')
        {
            break;
        }
        else
        {
            cout << endl
                 << "\t\t\t\t--- Invalid Input ---" << endl;
            cout << "\t\t\t\t---- Input Again ----" << endl;
            sleep(2);
            system("cls");
        }
    } while (true);
    system("cls");
    cout << "\t\t\t\tThank You For Selecting Our Service" << endl;
    cout << "\t\t\t\tMade By" << endl;
    cout << "\t\t\t\tShahroz Atiq(601)" << endl;
    cout << "\t\t\t\tMudassir Ali (635)" << endl;
    cout << "\t\t\t\tAhmad Murtaza (629)" << endl;

    return 0;
}