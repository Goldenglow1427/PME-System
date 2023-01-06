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

// This is for loading the command into the Command Prompt.
char str[100010];

// Compare two string by alphabetical order.
bool cmp(string x, string y)
{
    return x < y;
}

// Transform an integer into string
string transInt(int x)
{
    int len = 0;
    string ret = "";
    while(x != 0)
    {
        ret += (char)(x%10+'0');
        x /= 10;

        len++;
    }
    
    for(int i=0; i<len/2; i++)
        swap(ret[i], ret[len-i-1]);

    return ret;
}

class Names
{
    private:
        int len = 0;
        string name[10010];
    
    public:
        void query(); // Get the name from user's input.
        void reorganize(); // Reorganize the name list.
        void loadTo(string &x); // Load the names into a list.
}owner, helper;

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
    string withRep = ""; // The name list with repetition.
    string withoutRep = ""; // The name list without repetition.
    string countRep = ""; // The name list that counts the amount of repetition.
    
    int cnt = 1;
    for(int i=1; i<len; i++)
    {
        withRep += name[i];
        withRep += ", ";

        if(name[i] != name[i-1])
        {
            if(cnt > 1)
            {
                countRep += "(";
                countRep += transInt(cnt);
                countRep += "), ";
            }
            else if(i != 1)
                countRep += ", ";
            cnt = 1;
            withoutRep += name[i];
            withoutRep += ", ";

            countRep += name[i];
        }
        else
            cnt++;
    }

    withRep += name[len];
    if(name[len] != name[len-1])
    {
        if(cnt > 1)
        {
            countRep += "(";
            countRep += transInt(cnt);
            countRep += "), ";
        }
        else
            countRep += ", ";

        withoutRep += name[len];
        countRep += name[len];
    }
    else
    {
        cnt++;
        countRep += "(";
        countRep += transInt(cnt);
        countRep += ")";
    }
    
    if(withRep != withoutRep)
    {
        printf("\n");
        printf("Repetition detected in the input. Do you want to leave the same name?\n");
        printf("Y stands for you want to remain all the repetition.\n");
        printf("N stands for deleting all repetition while only remains one.\n");
        printf("C stands for recording the amount that repeating name occurs.\n");

        char receiver;
        scanf("%c", &receiver);

        if(receiver == 'Y')
        {
            printf("Affirmative answer received.\n");
            printf("\n");
            x = withRep;
        }
        else if(receiver == 'N')
            x = withoutRep;
        else if(receiver == 'C')
            x = countRep;
    }
    else
       x = withoutRep;
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
}

void output()
{
    srand(time(0));

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