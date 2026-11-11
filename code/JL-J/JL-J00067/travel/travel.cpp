#include<bits/stdc++.h>
using namespace std;
int main()
{
preopen("travel.in","r",stdin);
preopen("travel.out","w",stdout);
string c1;
string s1;
string c2;
string s2;
if(c1==c2)
{
cout<<1;
}
else
{
cout<<0;
}
if(s1[0]==s2[0]&&s1[1]==s2[1])
{
cout<<1;
}
else{
cout<<0;
}
if('65'<=s1[2]<='67'&&'65'<=s2[2]<='67')
{
cout<<1;
}
if ('68'<=s1[2]<='69'&&'68'<=s2[2]<='69')
{
cout<<1;
else
{
cout<<0;
}
if (abs(s1[2]-s2[2])=='1'&&s1[2]!='C's2[2]!='D'&&s1[2]!='D's2[2]!='C'){
    cout<<1;
}
else{
cout<<0;
}
return 0;
}

