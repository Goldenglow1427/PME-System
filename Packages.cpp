// Package Message Editor

#include <cstdlib>
#include <cstdio>
#include <algorithm>
#include <string>
#include <cstring>
#include <iostream>
#include <fstream>

using namespace std;

string ans;
char str[100010];

string names[10010];

bool cmp(string x, string y)
{
    return x < y;
}

void setup()
{
    printf("Welcome to use the package message editor system!\n");
    printf("Version 1.1, Create By Victor Chen\n");

    printf("\n");
}

void getName()
{
    int n = 0;

    printf("Please enter the name of package owners today, ended by -1\n");
    while(true)
    {
        string x;
        n++;
        getline(cin, names[n]);

        if(names[n].at(0) == '-' && names[n].at(1) == '1')
        {
            n--;
            break;
        }
    }

    sort(names+1, names+n+1, cmp);

    for(int i=1; i<n; i++)
    {
        ans += names[i];
        ans += ", ";
    }

    ans += names[n];

    printf("All the inputs are loaded!\n");

    printf("\n");
}

void output()
{
    srand(time(0));

    printf("\n");

    ifstream infile;
    infile.open("Template.dat");

    int n, rnd;

    infile>>n;

    rnd = rand()%n + 1;

    string x;
    getline(infile, x);
    for(int i=1; i<=2*(rnd-1); i++)
        getline(infile, x);
    
    getline(infile, x);
    if(x.at(0) != '-')
        ans = x + ans;
    getline(infile, x);
    if(x.at(0) != '-')
        ans = ans + x;

    infile.close();

    cout<<ans<<endl;

    printf("Automatically copied to the clipboard\n");

    ans = "echo " + ans;
    ans += "|clip";
    strcpy(str, ans.c_str());
    system(str);
}

int main()
{
    srand(time(0));

    setup();
    getName();
    output();

    system("pause");

    return 0;
}