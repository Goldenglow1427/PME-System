// Package Message Editor

#include <cstdlib>
#include <cstdio>
#include <algorithm>
#include <string>
#include <cstring>
#include <iostream>

using namespace std;

int n;
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
    printf("Version 1.0, Create By Victor Chen\n");

    printf("\n");

    ans += "Packages arrived today: ";
}

void getName()
{
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

    printf("All the inputs are loaded!\n");

    printf("\n");
}

void output()
{
    for(int i=1; i<n; i++)
    {
        ans += names[i];
        ans += ", ";
    }

    ans += names[n];

    cout<<ans<<endl;

    printf("\n");

    printf("Automatically copied to the clipboard\n");

    ans = "echo " + ans;
    ans += "|clip";
    strcpy(str, ans.c_str());
    system(str);
}

int main()
{
    setup();
    getName();
    output();

    system("pause");

    return 0;
}