#include<bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2;
int a=0;
int main()
{
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>c1>>s1>>c2>>s2;
    if (c1==c2)
    {
        cout<<'1';
    }
    else
    {
        cout<<'0'<<'0'<<'0'<<'0';
        return 0;
    }
    if (s1[0]==s2[0]&&s1[1]==s2[1])
    {
        cout<<'1';
    }
    else{
        cout<<'0'<<'0'<<'0';
        return 0;
    }
    if ((s1[2]-'0'<='C'-'0'&&s2[2]-'0'<='C'-'0')||(s1[2]-'0'>='D'-'0'&&s2[2]-'0'>='D'-'0'))
    {
        cout<<'1';
        a=1;
    }
    else{
        cout<<'0';
    }
    if ((s1[2]-s2[2]==1)||(s2[2]-s1[2]==1)&&(a==1))
    {
        cout<<'1';
    }
    else{
        cout<<'0';
    }
    return 0;
}
