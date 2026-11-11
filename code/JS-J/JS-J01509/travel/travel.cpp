#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    string c1,s1,c2,s2;
    cin>>c1>>s1>>c2>>s2;
    string a=" ",b=" ";
    char m,n;
    if(c1==c2)
    {
        cout<<'1';
        for(int i=0;i<=1;i++)
    {
        a+=s1[i];
        b+=s2[i];
    }
    if(a==b)
    {
        cout<<'1';
        m=s1[2];
        n=s2[2];
        if(m=='A')
    {
        if(n=='B'||n=='C')
        cout<<'1';
        else cout<<'0';
        if(n=='B')
        cout<<'1';
        else cout<<'0';
    }
    if(m=='B')
    {
        if(n=='A'||n=='C')
        cout<<'11';
        else cout<<'00';
    }
    if(m=='C')
    {
        if(n=='A'||n=='B')
        cout<<'1';
        else cout<<'0';
        if(n=='B')
        cout<<'1';
        else cout<<'0';
    }
    if(m=='D')
    {
        if(n=='F')
        cout<<'11';
        else cout<<'00';
    }
    if(m=='F')
    {
        if(n=='D')
        cout<<'11';
        else cout<<'00';
    }
    }
    else cout<<"000";
    }
    else cout<<"0000";
    fclose(stdin);
    fclose(stdout);
    return 0;
}
