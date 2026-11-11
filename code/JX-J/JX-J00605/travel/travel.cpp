#include<bits/stdc++.h>
using namespace std;
string a,s,d,f;
int main()
{
freopen("travel.in","r",stdin);
freopen("travel.out","w",stdout);
cin>>a>>s>>d>>f;


for(int i=0;i<2;i++)
{
	if(a[i]!=d[i])
	{
		cout<<0<<0<<0<<0;
		return 0;
	}
}
	cout<<1;
if(s[0]==f[0]&&s[1]==f[1]) cout<<1;
else
{
	cout<<0<<0<<0;
	return 0;
}
if(((s[2]=='A'||s[2]=='B'||s[2]=='C')&&(f[2]=='A'||f[2]=='B'||f[2]=='C'))||((s[2]=='F'||s[2]=='D')&&(f[2]=='F'||f[2]=='D')))
{
	cout<<1;
}
else 
{
	cout<<0<<0;
	return 0;
}
if((s[2]=='A'&&f[2]=='C')||(s[2]=='C'&&f[2]=='A')) 
{
	cout<<0;
	
}
else cout<<1;
return 0;
}
