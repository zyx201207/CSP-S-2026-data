#include<bits/stdc++.h>
using namespace std;
int c1,c2;
string s1,s2;
char q1,q2;
bool check1()
{
    if(q1=='A'&&q2=='B')
        return 1;
    if(q1=='A'&&q2=='C')
        return 1;
    if(q1=='B'&&q2=='C')
        return 1;
    if(q1=='D'&&q2=='F')
        return 1;
    return 0;
}
bool check2()
{
    if(q1=='A'&&q2=='B')
        return 1;
    if(q1=='B'&&q2=='C')
        return 1;
    if(q1=='D'&&q2=='F')
        return 1;
    return 0;
}
int main()
{
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>c1>>s1>>c2>>s2;
    if(c1==c2)//q1
        cout<<'1';
    else
        cout<<'0';
    if(c1==c2&&s1[0]==s2[0]&&s1[1]==s2[1])//q2
        cout<<'1';
    else
        cout<<'0';
    q1=s1[2];
    q2=s2[2];
    if(q1>q2)
        swap(q1,q2);
    if(c1==c2&&s1[0]==s2[0]&&s1[1]==s2[1]&&check1())//q3
        cout<<'1';
    else
        cout<<'0';
    if(c1==c2&&s1[0]==s2[0]&&s1[1]==s2[1]&&check2())//q4
        cout<<'1';
    else
        cout<<'0';
    return 0;
}