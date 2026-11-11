#include<bits/stdc++.h>
#define ll long long
using namespace std;
string c1,s1,c2,s2;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2) cout<<'1';
	else
	{
		cout<<"0000";
		return 0;
	}
	bool flag=true;
	for(int i=0;i<2;i++)
	{
		if(s1[i]!=s2[i]) flag=false;
	}
	if(flag) cout<<'1';
	else
	{
		cout<<"000";
		return 0;
	}
	int x=2;
	if(s1[x]<='C'&&s2[x]<='C') cout<<'1';
	else if(s1[x]>='D'&&s2[x]>='D') cout<<'1';
	else
	{
		cout<<"00";
		return 0;
	}
	int n=s1[2]-'A',m=s2[2]-'A';
	if(s1[2]<='C'&&s2[2]<='C')
	{
		if(abs(n-m)==1) cout<<'1';
		else cout<<'0';
	}
	if(s1[2]>='D'&&s2[2]>='D') cout<<'1';
	return 0;
}
