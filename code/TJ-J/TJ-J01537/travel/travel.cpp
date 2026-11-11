#include <iostream>
#include <string>
using namespace std;
int main()
{
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    string c1,s1,c2,s2;
    cin >> c1 >> s1 >> c2 >> s2;
    bool t=true,row=true,side=true;
    for(int i=0;i<2;i++)
    {
        if(c1[i]-'0'!=c2[i]-'0')
        {
            t=false;
        }
        if(s1[i]-'0'!=s2[i]-'0')
        {
            row=false;
        }
    }
    if(t==true)
    {
        cout << "1";
    }
    else
    {
        cout << "0";
    }
    if(t==true&&row==true)
    {
        cout << "1";
    }
    else
    {
        cout << "0";
    }
    if(t==true&&row==true&&((s1[2]<='C'&&s2[2]<='C')||(s1[2]>'C'&&s2[2]>'C')))
    {
        cout << "1";
    }
    else
    {
        side=false;
        cout << "0";
    }
    if(side==true&&((s1[2]-'A')-(s2[2]-'A')==1||(s2[2]-'A')-(s1[2]-'A')==1))
    {
        if((s1[2]=='C'&&s2[2]=='D')||(s2[2]=='C'&&s1[2]=='D'))
        {
            cout << "0";
        }
        else
        {
            cout << "1";
        }

    }
    else if((s1[2]=='D'&&s2[2]=='F')||(s2[2]=='D'&&s1[2]=='F'))
    {
        cout << "1";
    }
    else
    {
        cout << "0";
    }
    return 0;
}
