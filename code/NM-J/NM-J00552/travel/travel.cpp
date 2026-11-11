#include<bits/stdc++.h>
using namespace std;
string c1;
string s1;
string c2;
string s2;
char a[10];
char b[10];
int main()
{
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdin);
    cin>>c1>>s1>>c2>>s2;
    if(c1==c2)
    {
        cout<<"1";
    }
    else
    {
        cout<<"0";
    }
    for(int i=1;i<=3;i++)
    {
        a[i]-'0'=s1%10;
        b[i]-'0'=s2%10;
        s1/=10;
        s2/=10;
    }
    if(a[1]==b[1]&&a[2]==b[2])
    {
        cout<<"1";
        if((a[3]<='c'&&b[3]<='c')||(a[3]>'c'&&b[3]>'c'))
        {
            cout<<"1";
        }
        cout<<"0";
    }
    else
    {
        cout<<"0"<<"0";
    }
    if(a[3]-'0'+1==s2[3]-'0'||s1[3]-'0'-1==s2[3]-'0')
    {
        cout<<"1";
    }
    else
    {
        cout<<"0";
    }
    return  0;
}
