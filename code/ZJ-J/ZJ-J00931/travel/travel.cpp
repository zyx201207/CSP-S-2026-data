#include<bits/stdc++.h>
using namespace std;
string a1,a2,b1,b2;
bool check1()
{
    if(a1[0]==b1[0] and a1[1]==b1[1])
        return true;
    else
        return false;
}
bool check2()
{
    if(a2[0]==b2[0] and a2[1]==b2[1])
        return true;
    else
        return false;
}
int check3()
{
    if(a2[2]=='A')
    {
        if(b2[2]=='B')
            return 2;
        else if(b2[2]=='C')
            return 1;
        else
            return 0;
    }
    if(a2[2]=='B')
    {
        if(b2[2]=='A')
            return 2;
        else if(b2[2]=='C')
            return 2;
        else
            return 0;
    }
    if(a2[2]=='C')
    {
        if(b2[2]=='B')
            return 2;
        else if(b2[2]=='A')
            return 1;
        else
            return 0;
    }
    if(a2[2]=='D')
    {
        if(b2[2]=='F')
            return 2;
        else
            return 0;
    }
    if(a2[2]=='F')
    {
        if(b2[2]=='D')
            return 2;
        else
            return 0;
    }
}
int main()
{
    freopen("travel.in", "r", stdin);
    freopen("travel.out", "w", stdout);
    cin >> a1 >> a2 >> b1 >> b2;
    if(check1())
    {
        if(check2())
        {
            if(check3()==2)
            {
                cout << "1111";
            }
            else if(check3()==1)
                cout << "1110";
            else
                cout << "1100";
        }
        else
            cout << "1000";
    }
    else
        cout << "0000";
    return 0;
}
