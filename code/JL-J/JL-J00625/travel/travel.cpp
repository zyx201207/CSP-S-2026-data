#include<bits/stdc++.h>
using namespace std;
int q(string sx,string sr)
{
    if(int(sx[2])>int(sr[2]))
    {
        return int(sr[2]);
    }
    else{
        return int(sx[2]);
    }
}
char p(string sx,string sr)
{
    if(int(sx[2])>int(sr[2]))
    {

        return sx[2];
    }
    else{
        return sr[2];
    }
}
int main()
{
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    string cx,sx,cr,sr;
    cin>>cx>>sx>>cr>>sr;
    if(cx==cr)
    {
        cout<<'1';
    }
    else
    {
        cout<<"0000";
        return 0;
    }
    if(sx[0]==sr[0]&&sx[1]==sr[1])
    {
        cout<<'1';
    }
    else
    {
        cout<<"000";
        return 0;
    }
    char b=q(sx,sr)+1;
    char c=q(sx,sr)+2;
    bool n=0;
    if(b==p(sx,sr)||c==p(sx,sr))
    {
        n=1;
    }
    else
    {
        cout<<"00";
        return 0;
    }
    if(n=1&&q(sx,sr)!='C')
    {

        cout<<'1';
    }
    else
    {
        cout<<"00";
        return 0;
    }
    char a=q(sx,sr)+1;
    if(a==p(sx,sr)&&q(sx,sr)!='C')
    {
        cout<<'1';
    }
    else
    {
        cout<<"0";
        return 0;
    }
}
