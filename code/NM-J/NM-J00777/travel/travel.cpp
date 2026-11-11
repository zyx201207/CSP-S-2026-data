#include<bits/stdc++.h>
using namespace std;
int a,b,x,y;
string s1,s2;
char c1,c2;
bool f=1;
int main()
{
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>a>>s1>>b>>s2;
    if(a==b)cout<<1;
    else
	{
		f=0;
		cout<<0;
	}
    x=(s1[0]-'0')*10+(s1[1]-'0');
    y=(s2[0]-'0')*10+(s2[1]-'0');
    if(x==y&&f)cout<<1;
    else
	{
		f=0;
		cout<<0;
	 }
    c1=s1[2];
    c2=s2[2];
    if(c1>='A'&&c1<='C'&&c2>='A'&&c2<='C'&&f)
	{
		cout<<1;
		if(c1+1==c2||c2+1==c1)cout<<1;
		else cout<<0;
	}
	else if(c1>='D'&&c1<='F'&&c2>='D'&&c2<='F'&&f)
	{
		cout<<"11";
	}
    else cout<<"00";
    return 0;
}
