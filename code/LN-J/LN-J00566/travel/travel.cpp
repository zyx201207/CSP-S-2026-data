#include<bits/stdc++.h>
using namespace std;
string case1,num1,case2,num2;
int hallside(string a)
{
    if(a[2]=='A'||a[2]=='B'||a[2]=='C')return 1;
    if(a[2]=='D'||a[2]=='E')return 2;
}
int lineof(string a)
{
    int n;
    n=(a[0]-'0')*10+a[1]-'0';
    return n;
}
int main()
{
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>case1>>num1>>case2>>num2;
    if(case1==case2)cout<<1;
    else 
    {
        cout<<"0000";
        return 0;
    }
    if(lineof(num1)==lineof(num2))cout<<1;
    else 
    {
        cout<<"000";
        return 0;
    }
    if(hallside(num1)==hallside(num2))cout<<1;
    else 
    {
        cout<<"00";
        return 0;
    }
    if(num1[2]-num2[2]==1||num1[2]-num2[2]==-1)cout<<1;
    else cout<<0;
    return 0;
}