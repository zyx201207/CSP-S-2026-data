#include<bits/stdc++.h>
using namespace std;

int main()
{
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    int a,b,dc=0;
    char s,s1,s2,s3,s4,s5,s6;
    cin>>a;
    cin>>s1>>s2>>s3;
    cin>>b;
    cin>>s4>>s5>>s6;
    if(a==b)
        cout<<"1";
    else
    {
        cout<<"0";
        dc=1;
    }
    if(s1==s4 && s2==s5)
    {
        if(dc==0)
            cout<<"1";
        else
            cout<<"0";
    }
    else
    {
        cout<<"0";
        dc=1;
    }
    if(s3=='A' || s3=='B' || s3=='C')
    {
        if(s6=='A' || s6=='B' || s6=='C')
            if(dc==0)
                cout<<"1";
        else
        {
            cout<<"0";
            dc==1;
        }
    }
    else
    {
        if(s6=='D' || s6=='F')
            if(dc==0)
                cout<<"11";
        else
        {
            cout<<"0";
            dc==1;
        }
    }
    if(s3=='B' || s6=='B')
    {
        if(dc==0)
            cout<<"1";
        else
        {
            cout<<"0";
            dc==1;
        }
    }
    else
        cout<<"0";
    return 0;
}
