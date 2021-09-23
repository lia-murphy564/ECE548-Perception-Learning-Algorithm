// ------------------------------------------------------ //
// Perception Learning Algorithm for ECE548 Project 1 # 8
// Code written by Lia Murphy, Julio, Khaled
// on 9/15/2021
// ------------------------------------------------------ //

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <cmath>
#include <vector>

#include "model.h"
#include "data.h"

using namespace std;

struct csection
{
    int id;
    int age;
    int deliveryNum;
    int deliveryType;
    int blood;
    int heart;
    int csection;
};

struct banknote
{
    double variance, skewness, curtosis, entropy;
    int truth;
};

vector<csection> readFileIntoCsection(string path)
{
    ifstream inputFile(path);
    if (!inputFile.is_open())
    {
        cout << "failed to open file\n";
        exit(1);
    }

    vector<csection> v;

    string out;
    string str;

    getline(inputFile, str); // skip first line

    while (getline(inputFile, str))
    {
        csection e;
        istringstream iss(str);
        string token;

        getline(iss, token, ',');
        e.id = stoi(token);

        getline(iss, token, ',');
        e.age = stoi(token);

        getline(iss, token, ',');
        e.deliveryNum = stoi(token);

        getline(iss, token, ',');
        e.deliveryType = stoi(token);

        getline(iss, token, ',');
        e.blood = stoi(token);

        getline(iss, token, ',');
        e.heart = stoi(token);

        getline(iss, token, ',');
        e.csection = stoi(token);

        v.push_back(e);

    }
    return v;
}

vector<banknote> readFileIntoBanknote(string path)
{
    ifstream inputFile(path);
    if (!inputFile.is_open())
    {
        cout << "failed to open file\n";
        exit(1);
    }

    vector<banknote> v;

    string out;
    string str;

    getline(inputFile, str); // skip first line

    while (getline(inputFile, str))
    {
        banknote e;
        istringstream iss(str);
        string token;

        getline(iss, token, ',');
        e.variance = stod(token);

        getline(iss, token, ',');
        e.skewness = stod(token);

        getline(iss, token, ',');
        e.curtosis = stod(token);

        getline(iss, token, ',');
        e.entropy = stod(token);

        getline(iss, token, ',');
        e.truth = stoi(token);

        v.push_back(e);
    }
    return v;
}

int main()
{
    string in;
    cout << "Input type of data (banknote, csection, cars)";
    cin >> in;
    cout << "\n";

    //string path = "C:/Users/julio/source/repos/ECE548-Perception-Learning-Algorithm/ECE548-Proj1-PLA/caesarian.csv";
    string path = "C:/Users/Amelia/source/repos/ECE548-Proj1-PLA/ECE548-Proj1-PLA/caesarian.cs";




    //vector<int> x;
    //vector<vector<int>> attributes; // input vector
    //vector<int> y; // output vector

    //cs = readFileIntoCsection(path);
    //bn = readFileIntoBanknote(path);
    

    if (in == "csection")
    {
        vector<vector<int>> attributes; // input vector
        vector<int> y; // output vector

        vector<csection> cs = readFileIntoCsection(path);
        vector<int> temp = { 0,0,0,0,0 };
        for (int i = 0; i < cs.size(); i++)
        {
            //x.push_back(v[i].age);
            temp[0] = cs[i].age;
            temp[1] = cs[i].deliveryNum;
            temp[2] = cs[i].deliveryType;
            temp[3] = cs[i].blood;
            temp[4] = cs[i].heart;
            attributes.push_back(temp);
        }

        // parse into output vector
        for (int i = 0; i < v.size(); i++)
        {
            y.push_back(v[i].csection);
        }
    }

    else if (in == "banknote")
    {
        vector<vector<double>> attributes; // input vector
        vector<int> y; // output vector
        
        vector<banknote> bn = readFileIntoBanknote(path);
        vector<double> temp = { 0,0,0,0,0 };

        for (int i = 0; i < bn.size(); i++)
        {
            //x.push_back(v[i].age);
            temp[0] = bn[i].variance;
            temp[1] = bn[i].skewness;
            temp[2] = bn[i].curtosis;
            temp[3] = bn[i].entropy;

            // need to change attributes to double
            attributes.push_back(temp);
        }

        // parse into output vector
        for (int i = 0; i < bn.size(); i++)
        {
            // need to change attributes to double
            y.push_back(stoi(bn[i].truth));
        }
    }

    // parse into input vector
    

    PLA model;

    model.loadData(attributes, y);

    int epochs = 10;
    double eta = 0.2;
    model.runModel(epochs, eta);

   // model.optimizeModel(1, 10, 0.05, 0.5);

    //for (int i = 1; i <= 20; i++)
    //{
    //    for (double j = 0.05; j < 0.2; j += 0.01)
    //    {
    //        cout << "epochs = " << i << "  eta = " << j << " ";
    //        model.runModel(i, j);
    //    }
    //}


    //model.runModel(25, 0.1);

    //for (int i = 0; i < v.size(); i++)
    //{
    //    cout << "Age: " << x[i] << " | Csection " << y[i] << "\n";
    //}

    //cout << "x size = " << x.size() << "\n";

    //for (int i = 0; i < v.size(); i++)
    //{
    //    if (i < v.size() / 2)
    //        train.push_back(v[i]);
    //    else
    //        test.push_back(v[i]);
    //}

    //cout << "v size = " << v.size() << "\n";
    //cout << "train size = " << train.size() << "\n";
    //cout << "test size = " << test.size() << "\n";




    //model.loadData(x., y);

    //cmodel.runModel(20, 0.1);

    //for (int i = 0; i < v.size(); i++)
    //    cout << v[i].id << ' ' << v[i].age << ' ' << v[i].deliveryNum << ' ' << v[i].deliveryType << ' ' << v[i].blood << ' '
    //    << v[i].heart << ' ' << v[i].csection << '\n';
}
