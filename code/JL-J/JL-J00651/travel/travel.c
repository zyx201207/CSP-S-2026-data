#include<bits/stdc++.h>
using namespace std;
int main(){
freopen("travel.c.in","r",stdin);
freopen("travel.c.out","w",stdout);
bool g=1,m=1,z=1;
int a,b;
string s,c,sam[2];
cin>>a>>s>>b>>c;
if(a==b)
{
	cout<<"1";
}else{
	cout<<"0";
}
sam[0]=s[1]+s[0];
sam[1]=c[1]+c[0];
if(sam[0]==sam[1])
{
	cout<<g;
}else{
	g=0;
	cout<<g;
}
if(s[2]<D||s[2]>=A&&c[2]<D||c[2]>=A)
{
	m=1;
}else{
	m=0;
}
if(s[2]+1==c[2]||s[2]-1==c[2]&&s>=D&&s<=F&&s>=D&&s<=F)
{
	z=1;
}else{
	z=0;
}
if(m==1||z==1&&g==1)
{
	cout<<g;
}else{
	g=0;
	cout<<g;
}
return 0;
}
