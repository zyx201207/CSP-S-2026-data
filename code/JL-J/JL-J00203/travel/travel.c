#include<bits/stdc++.h>
using namespace std;
int main()
{
int m1,m2,m3,m4;
string c1,s1,c2,s2;
cin>>c1>>s1>>c2>>s2;
if(c1=='01'&&c2=='01'||c1=='02'&&c2=='02')
{
m1=1;
}
else
m1=0;
for(int i=0;i<=s1.size();i++)
{
if(s1[1]==s2[1]&&s1[2]==s2[2])
{
m2=1;
}
else
m2=0;
}
for(int q='A';q<='F';q++)
{
if(s1[3]==q&&s2[3]=q)
{
m3=1;
}
else
m3=0;
}
for(int l=A;l<='F';i++)
{
if(s1[3]=i&&s1[3]=i+1)
{
m4=1;
}
else
m4=0;
}
cout<<m1<<" "<m2<<" "<<m3<<" "<<m4;
return 0;
}
