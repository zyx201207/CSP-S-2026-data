#include<bits/stdc++.h>
using namespace std;
int c1;
int c2;
string s1;
string s2;
int a;
int b;
int c;
int d;
int main()
{
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>c1>>s1>>c2>>s2;
    if(c1==c2)
    {

        a=1;
    }
    else
    {
        a=0;
    }
    if(s1[0]==s2[0] && s1[1]==s2[1] && c1==c2)
    {

        b=1;
    }
    else
    {
        b=0;
    }
    if(s1[2]=='A'&&s2[2]=='B' || s1[2]=='A'&&s2[2]=='C' || s1[2]=='B'&&s2[2]=='A' || s1[2]=='B'&&s2[2]=='C' || s1[2]=='C'&&s2[2]=='A' || s1[2]=='C'&&s2[2]=='B' || s1[2]=='D'&&s2[2]=='F' || s1[2]=='F'&&s2[2]=='D')
    {
        if(c1==c2)
        {
            if(s1[0]==s2[0] && s1[1]==s2[1] && c1==c2)
            {
                c=1;
            }


        }

    }
    else
    {
        c=0;
    }
    if(s1[2]=='A'&&s2[2]=='B' || s1[2]=='B'&&s2[2]=='A' || s1[2]=='B'&&s2[2]=='C' || s1[2]=='C'&&s2[2]=='B' || s1[2]=='D'&&s2[2]=='F' || s1[2]=='F'&&s2[2]=='D')
    {
        if(c1==c2)
        {
            if(s1[0]==s2[0] && s1[1]==s2[1])
            {
                d=1;
            }
        }


    }
    else
    {

        d=0;
    }
    cout<<a<<b<<c<<d;
    return 0;

}
