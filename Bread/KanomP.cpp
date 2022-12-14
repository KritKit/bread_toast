#include <iostream>
#include <fstream>
#include <string>
#include <ctime>
#include <sstream>
#include <iomanip>
#include <algorithm>
#include <direct.h>
using namespace std;
void Readdata();
void Bread();

int ID, Cnum = 0, OrderID, SSumtotal = 0;
bool cjp;
string Pid[100] = {};
string Pname[100] = {};
string PpriceS[100] = {};
string Punit[100] = {};

/*int Oid[3] = {};
int Ono[3] = {};
string Osize[3] = {};
int Oquan[3] = {};
int Ofour[3] = {};*/

struct Product
{
    int id;
    string name;
    string priceS;
    string unit;
};

/*struct Orders
{
    int OrderIds;
    int OrderQl;
    int OrderPid;
    int Orderflour;
    string OrderSize;
    int OrderQ;
    int OrderTT;
    int Orderwday;
    int Orderday;
    int Ordermount;
    int Orderyear;
    string Ordertime;
};*/

void Selecttopping()
{
    Readdata();
    int slp, intid, no, intkS, intkM, intkL, intnS, intnM, intnL, intsum, intPS, intPM, intPL, Noa;
    int stopping, tkiM, tkiL, tniS, tniM, tniL, Qt = 0, chks, quan, conselect, flour;
    string Sizes, topid;
    char maxnum[50];
    bool ckp = false, cks = false, ckt = false, ckc = false, checkcha = false;

     do
    {
        cout << "Enter Toppingid : ";
        cin >> topid;
        for (int o = 0; o < topid.size(); o++)
        {
            maxnum[o] = topid[o];
            if (int(maxnum[o]) < 48 || int(maxnum[o]) > 57)
            {
                checkcha = false;
                break;
            }
            else
            {
                checkcha = true;
            }
        }
        if (checkcha == true)
        {
            checkcha = false;
            stringstream kk;
            kk << topid;
            kk >> slp;
            for (int i = 0; i < 100; i++)
            {
                stringstream sw;
                sw << Pid[i];
                sw >> intid;
                if (slp == intid)
                {
                    ckp = true;
                    no = i;
                    chks = 1;
                    break;
                }
                else if (slp == 0)
                {
                    cjp = true;
                    ckp = true;
                }
                else
                {
                    chks = 0;
                    ckp = false;
                }
            }
            if (chks == 1)
            {
                stringstream ttopping;
                ttopping << Punit[no];
                ttopping >> stopping;

                Qt = stopping;

                if (Qt == 0)
                {
                    cout << Pname[no] << "Out of Stock" << endl;
                    ckp = false;
                    chks = 0;
                }
            }
        }
    } while (ckp == false);
}

void Topping()
{
    cout << endl;
    int conselect;
    char can, con;
    Selecttopping();
    bool ckc = false;
    do{
        if(Cnum == 2){
            cout << endl;
            cout << "1.ViewOrder" << endl;
            cout << "2.CancelOrder" << endl;
            cout << "3.ConfirmOrder" << endl;
            cout << "Enter Select : ";
            cin >> conselect;
            if(conselect == 1){

            }else if(conselect == 2){

            }else if(conselect == 3){
            }else{
                ckc = false;
            }
        }else{
            cout << endl;
            cout << "1.Next Topping" << endl;
            cout << "2.Confirm" << endl;
            cout << "Enter Select : ";
            cin >> conselect;
            if(conselect == 1){
                Cnum += 1;
                Topping();
            }else if(conselect == 2){
                Bread();
            }
        }
    } while (ckc == false);
}


void Orderbread()
{
    bool check = false;
    do
    {
        cout << "NotToast OR Toast (N/T)" << endl;
        cout << "Exit (X)" << endl;
        char option;
        string ad_pass;
        cout << "Enter option : ";
        cin >> option;
        if (option == 'N' || option == 'n')
        {
            Topping();

            check = true;
        }
        else if (option == 'T' || option == 't')
        {
            Topping();


            check = true;
        }
        else if (option == 'X' || option == 'x')
        {
            check = true;
        }
        else
        {
            check = false;
        }
    } while (check == false);
}

void Addproduct()
{
    Product pd;
    cout << "Enter toping name : ";
    cin.get();
    getline(cin, pd.name);
    cout << "Enter toping price : ";
    cin >> pd.priceS;
    cout << "Enter toping unit : ";
    cin >> pd.unit;
    ID++;

    ofstream write;
    write.open("C:/Pungping/product.txt", ios::app);
    write << "\n"
          << ID;
    write << "\n"
          << pd.name;
    write << "\n"
          << pd.priceS;
    write << "\n"
          << pd.unit;
    write.close();
    write.open("C:/Pungping/id.txt");
    write << ID;
    write.close();
    cout << "Data save to file" << endl;
}

void print(Product s)
{
    cout << right << ":" << setw(3) << s.id << " : " << setw(20) << s.name << " : " << setw(5) << s.priceS << " :" << setw(5) << s.unit << "  :" << endl;
}


void Bread()
{
    int conselect;
    char can, con;
    Orderbread();
    bool checkbread = false;
    do{
            cout << "1.Select Next Bread" << endl;
            // cout << "2.ViewOrder" << endl;
            // cout << "3.CancelOrder" << endl;
            // cout << "4.ConfirmOrder" << endl;
            cout << "Enter Select : ";
            cin >> conselect;
            if(conselect == 1){              
                system("CLS");
                checkbread = true;
                Bread();
                
            }else if(conselect == 2){
                system("CLS");
                checkbread = true;
            }
       } while (checkbread == false);
}

void Readdata()
{
    Product pd;
    ifstream read;
    read.open("C:/Pungping/product.txt");
    cout << "+===========================================+" << endl;
    cout << ": ID :         Name         : Price : Unit  :" << endl;
    cout << "+-------------------------------------------+" << endl;
    while (!read.eof())
    {
        read >> pd.id;
        read.ignore();
        getline(read, pd.name);
        read >> pd.priceS;
        read >> pd.unit;
        print(pd);
    }
    cout << "+===========================================+" << endl;
    read.close();

}

void Productlist()
{
    Product pd;
    ifstream read;
    read.open("C:/Pungping/product.txt");
    int x = 0;
    cout << "+==========================================+" << endl;
    cout << ": ID :         Name         : Price : Unit :" << endl;
    cout << "+------------------------------------------+" << endl;

    while (!read.eof())
    {
        string strid;

        read >> pd.id;
        read.ignore();
        getline(read, pd.name);
        read >> pd.priceS;
        read >> pd.unit;

        strid = to_string(pd.id);

        Pid[x] = strid;
        Pname[x] = pd.name;
        PpriceS[x] = pd.priceS;
        Punit[x] = pd.unit;

        cout << right << ":" << setw(3) << Pid[x] << " : " << setw(20) << Pname[x] << " : " << setw(5) << PpriceS[x] << " :" << setw(5) << " :" << endl;
        x++;
    }
    cout << "+=========================================+" << endl;
    read.close();
}

int searchData()
{
    int id;
    cout << "Enter id you want to search : ";
    cin >> id;
    Product pd;
    ifstream read;
    read.open("C:/Pungping/product.txt");
    while (!read.eof())
    {
        read >> pd.id;
        read.ignore();
        getline(read, pd.name);
        read >> pd.priceS;
        read >> pd.unit;
        if (pd.id == id)
        {
            cout << "+===========================================+" << endl;
            cout << ": ID :         Name         : Price : Unit  :" << endl;
            cout << "+-------------------------------------------+" << endl;
            print(pd);
            cout << "+===========================================+" << endl;
            return id;
        }
    }
}

void Updatedata()
{
    int id = searchData();
    cout << "You want to update record (y/n) : ";
    char choice;
    cin >> choice;
    if (choice == 'y')
    {
        Product newData;
        cout << "Enter new product name : ";
        cin.get();
        getline(cin, newData.name);
        cout << "Enter name : ";
        cin >> newData.name;
        cout << "Enter price : ";
        cin >> newData.priceS;
        cout << "Enter unit : ";
        cin >> newData.unit;
        Product pd;
        ofstream tempFile;
        tempFile.open("C:/Pungping/temp.txt");
        ifstream read;
        read.open("C:/Pungping/product.txt");
        while (!read.eof())
        {
            read >> pd.id;
            read.ignore();
            getline(read, pd.name);
            read >> pd.priceS;
            read >> pd.unit;
            if (pd.id != id)
            {
                tempFile << "\n"
                         << pd.id;
                tempFile << "\n"
                         << pd.name;
                tempFile << "\n"
                         << pd.priceS;
                tempFile << "\n"
                         << pd.unit;
            }
            else
            {
                tempFile << "\n"
                         << pd.id;
                tempFile << "\n"
                         << newData.name;
                tempFile << "\n"
                         << newData.priceS;
                tempFile << "\n"
                         << newData.unit;
            }
        }
        read.close();
        tempFile.close();
        remove("C:/Pungping/product.txt");
        rename("C:/Pungping/temp.txt", "C:/Pungping/product.txt");
        cout << "Data updated successfuly" << endl;
    }
    else
    {
        cout << "Record not deleted" << endl;
    }
}

void deleteData()
{
    int id = searchData();
    cout << "You want to delete record (y/n) : ";
    char choice;
    cin >> choice;
    if (choice == 'y')
    {
        Product pd;
        ofstream tempFile;
        tempFile.open("C:/Pungping/temp.txt");
        ifstream read;
        read.open("C:/Pungping/product.txt");
        while (!read.eof())
        {
            read >> pd.id;
            read.ignore();
            getline(read, pd.name);
            read >> pd.priceS;
            read >> pd.unit;
            if (pd.id != id)
            {
                tempFile << "\n"
                         << pd.id;
                tempFile << "\n"
                         << pd.name;
                tempFile << "\n"
                         << pd.priceS;
                tempFile << "\n"
                         << pd.unit;
            }
        }
        read.close();
        tempFile.close();
        remove("C:/Pungping/product.txt");
        rename("C:/Pungping/temp.txt", "C:/Pungping/product.txt");
        cout << "Data deleted successfuly" << endl;
    }
    else
    {
        cout << "Record not deleted" << endl;
    }
}

/*void datetime()
{
    time_t nows;
    struct tm datelc;
    nows = time(NULL);
    datelc = *localtime(&nows);
    cout << datelc.tm_mday << "/" << datelc.tm_mon + 1 << "/" << datelc.tm_year + 1900 << endl;
    cout << datelc.tm_hour << ":" << datelc.tm_min << ":" << datelc.tm_sec;
}*/

void Checkfile()
{
    ifstream read;
    read.open("C:/Pungping/id.txt");
    if (!read.fail())
    {
        read >> ID;
    }
    else
    {
        ID = 0;
    }
    read.close();
}

void admin()
{
    Checkfile();
    bool check = false;
    do
    {
        cout << "1.ADD" << endl;
        cout << "2.Check" << endl;
        cout << "3.Update" << endl;
        cout << "4.Delete" << endl;
        cout << "5.Exit" << endl;
        int option;
        cout << "Enter option : ";
        cin >> option;
        if (option == 1)
        {
            system("CLS");
            Addproduct();
            check = false;
        }
        else if (option == 2)
        {
            system("CLS");
            Readdata();
            check = false;
        }
        else if (option == 3)
        {
            system("CLS");
            Updatedata();
            system("CLS");
            check = false;
        }
        else if (option == 4)
        {
            system("CLS");
            deleteData();
            system("CLS");
            check = false;
        }
        else if (option == 5)
        {
            check = true;
        }
        else
        {
            system("CLS");
            check = false;
        }
    } while (check == false);
    system("CLS");
}

void Creatfile()
{
    mkdir("C:/Pungping");
    ofstream pidfile("C:/Pungping/id.txt");
    pidfile << "6";
    pidfile.close();
    /*ofstream oidfile("C:/Pungping/orderid.txt");
    oidfile << "0";
    oidfile.close();*/
    ofstream productfile("C:/Pungping/product.txt");
    productfile << "\n"
                << "1";
    productfile << "\n"
                << "Sugar";
    productfile << "\n"
                << "5";
    productfile << "\n"
                << "100";

    productfile << "\n"
                << "2";
    productfile << "\n"
                << "Chocolate";
    productfile << "\n"
                << "5";
    productfile << "\n"
                << "100";

    productfile << "\n"
                << "3";
    productfile << "\n"
                << "";
    productfile << "\n"
                << "5";
    productfile << "\n"
                << "100";

    productfile << "\n"
                << "4";
    productfile << "\n"
                << "";
    productfile << "\n"
                << "5";
    productfile << "\n"
                << "100";

    productfile << "\n"
                << "5";
    productfile << "\n"
                << "";
    productfile << "\n"
                << "5";
    productfile << "\n"
                << "100";

    productfile << "\n"
                << "6";
    productfile << "\n"
                << "";
    productfile << "\n"
                << "5";
    productfile << "\n"
                << "100";
    productfile.close();
    /*ofstream orderfile("C:/Pungping/order.txt");
    orderfile.close();*/
    ofstream openfile("C:/Pungping/open.dll");
    openfile.close();
}

void select()
{
    bool check = false;
    do
    {
        cout << "1.Buy" << endl;
        cout << "2.For employee" << endl;
        cout << "3.Exit" << endl;
        int option;
        string ad_pass;
        cout << "Enter option : ";
        cin >> option;
        if (option == 1)
        {
            system("CLS");
            Bread();

            check = false;
        }
        else if (option == 2)
        {
            system("CLS");
            cout << "Enter password: ";
            cin >> ad_pass;
            if (ad_pass == "admin1234")
            {
                system("CLS");
                admin();
            }
            else
            {
                system("CLS");
                cout << "Wrong password!" << endl;
            }
            check = false;
        }
        else if (option == 3)
        {
            check = true;
        }
        else
        {
            check = false;
        }
    } while (check == false);
}

int main()
{
    ofstream myfile;
    myfile.open("C:/Pungping/open.dll");
    if (myfile)
    {
        select();
    }
    else
    {
        Creatfile();
        select();
    }
}