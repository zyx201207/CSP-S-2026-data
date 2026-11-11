#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    string s1,s2,s3,s4;
    cin>>s1>>s2>>s3>>s4;
    if(s1==s3)
    {
        cout<<1;
    }
    else
    {
        cout<<"0000";
        return 0;
    }
    char a=s2[0],b=s2[1],c=s2[2],d=s4[0],e=s4[1],f=s4[2];
    if(a==d&&b==e)
    {
        cout<<1;
    }
    else
    {
        cout<<"000";
        return 0;
    }
    if((c=='F'&&f=='D')||(c=='D'&&f=='F')||('A'<=c&&c<='C'&&'A'<=f&&f<='C'))
    {
        cout<<1;
    }
    else
    {
        cout<<"00";
        return 0;
    }
    if(c=='A'&&f=='B'||c=='B'&&f=='C'||c=='D'&&f=='F'||c=='F'&&f=='D'||c=='B'&&f=='A'||c=='C'&&f=='B')
    {
        cout<<1;
    }
    else
    {
        cout<<0;
    }
    return 0;
}
