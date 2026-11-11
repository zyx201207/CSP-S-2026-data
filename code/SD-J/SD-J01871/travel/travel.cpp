#include<bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio();cin.tie(0);cout.tie(0);
	cin>>c1>>s1>>c2>>s2;
	if(c1!=c2)
	{
		cout<<"0000";
		return 0;
	}
	string g1="",g2="";
	char d1,d2;
	for(int i=0;i<s1.size();i++)
	{
		if(s1[i]>='0'&&s1[i]<='9')g1+=s1[i];
		else d1=s1[i];
	}
	for(int i=0;i<s2.size();i++)
	{
		if(s2[i]>='0'&&s2[i]<='9')g2+=s2[i];
		else d2=s2[i];
	}
	if(g1!=g2)
	{
		cout<<"1000";
		return 0;
	}
	if(d1<='C'&&d2<='C'||d1>='D'&&d2>='D')
	{
		if(d1=='A'&&d2=='C'||d1=='C'&&d2=='A')cout<<"1110";
		else cout<<"1111";
	}
	else cout<<"1100";
	return 0;
} 
