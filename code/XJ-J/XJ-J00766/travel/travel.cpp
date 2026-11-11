#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string c1,s1,c2,s2;
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2) cout<<"1";
	else
	{
		cout<<"0000";
		return 0;
	}
	string a="12",b="12";
	for(int i=0;i<=1;i++)
	{
		a[i]=s1[i];
		b[i]=s2[i];
	}
	if(a==b)
	{
		cout<<1;
	}
	else
	{
		cout<<"000";
		return 0;
	}
	if((s1[2]=='A'&&(s2[2]=='B'||s2[2]=='C'))||(s1[2]=='B'&&(s2[2]=='A'||s2[2]=='C'))||(s1[2]=='C'&&(s2[2]=='A'||s2[2]=='B'))||(s1[2]=='D'&&s2[2]=='F')||(s1[2]=='F'&&s2[2]=='D'))
	{
		cout<<"1";
	}
	else
	{
		cout<<"00";
		return 0;
	}
	if((s1[2]=='A'&&s2[2]=='B')||(s1[2]=='B'&&(s2[2]=='A'||s2[2]=='C'))||(s1[2]=='C'&&s2[2]=='B')||(s1[2]=='D'&&s2[2]=='F')||(s1[2]=='F'&&s2[2]=='D'))
	{
		cout<<"1";
	}
	else
	{
		cout<<"0";
	}
	return 0;
}