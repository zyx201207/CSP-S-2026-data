#include <bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2;

bool iftongce()
{
    if(s1[2]=='A'&&(s2[2]=='B'||s2[2]=='C'))
    {
        return true;
    }
    else if(s1[2]=='B'&&(s2[2]=='A'||s2[2]=='A'))
    {
        return true;
    }
    else if(s1[2]=='C'&&(s2[2]=='B'||s2[2]=='A'))
    {
        return true;
    }
    else if(s1[2]=='D'&&s2[2]=='F'||s1[2]=='F'&&s2[2]=='D')
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool ifxianglin()
{

    if(s1[2]=='A'&&s2[2]=='B')
    {
        return true;
    }
    else if(s1[2]=='B'&&(s2[2]=='A'||s2[2]=='C'))
    {
        return true;
    }
    else if(s1[2]=='C'&&s2[2]=='B')
    {
        return true;
    }
    else if(s1[2]=='D'&&s2[2]=='F'||s1[2]=='F'&&s2[2]=='D')
    {
        return true;
    }
    else
    {
        return false;
    }
}


int main()
{
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>c1>>s1>>c2>>s2;
    if(c1==c2)
    {
        cout<<1;
    }
    else
    {
        cout<<0;
    }
    if(s1[1]==s2[1]&&s2[0]==s1[0])
    {
        cout<<1;
        if(iftongce())
        {
            cout<<1;
        }
        else
        {
            cout<<0;
        }
        if(ifxianglin())
        {
            cout<<1;
        }
        else
        {
            cout<<0;
        }
    }
    else
    {
        cout<<0;
        cout<<0;
        cout<<0;
    }
    return 0;

}
