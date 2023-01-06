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

bool cmp(string x, string y)
{
    return x < y;
}

class Names
{
    private:
        int len;
        string name[10010];
    
    public:
        void query(); // Get the name from user's input.
        void reorganize(); // Reorganize the name list.
        void loadTo(string &x); // Load the names into a list.
}owner;

void Names::query()
{
    len = 0;
    while(true)
    {
        string x;
        len++;
        getline(cin, name[len]);

        if(name[len].at(0) == '-' && name[len].at(1) == '1')
        {
            len--;
            break;
        }
    }
}
void Names::reorganize()
{
    sort(name+1, name+len+1, cmp);
}
void Names::loadTo(string &x)
{
    x = "";
    for(int i=1; i<len; i++)
    {
        x += name[i];
        x += ", ";
    }

    x += name[len];
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
    
    owner.query();
    owner.reorganize();
    owner.loadTo(ans);

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