#include<bits/stdc++.h>
using namespace std;
int main()
{
freopen("travel.in","r",stdin);
freopen("travel.out","w",stdout);
string a,z1,b,z2;
cin>>a>>z1>>b>>z2;

if(a==b)
{
cout<<1;
if(z1[0]==z2[0]&&z1[1]==z2[1])
{
if(z1[2]=='C'||z1[2]=='D')
{
if(z2[2]=='C'||z2[2]=='D')
{
cout<<1;
if(z1[2]>z2[2]&&z1[2]==z2[2]+1||z1[2]<z2[2]&&z1[2]==z2[2]-1)
cout<<1;
else
cout<<0;
}
else
cout<<00;
}
if(z1[2]!='C'||z1[2]!='D')
{
if(z2[2]!='C'||z2[2]!='D'){
cout<<1;
if(z1[2]>z2[2]&&z1[2]==z2[2]+1||z1[2]<z2[2]&&z1[2]==z2[2]-1)
{
cout<<1;
}
else
cout<<0;
}
else
cout<<00;
}

}
cout<<1;
else
cout<<000;

}
else
cout<<0000;
return 0;
}
