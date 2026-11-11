#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	#define int long long 
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	string c1,s1,c2,s2,p1,p2;
	int ad=0,as=0;
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2)
	{
		cout<<"1";
		ad=1;
	}
	else 
	{
		cout<<"0"; 
	}
	for(int i=0;i<2;i++)
	{
		p1+=s1[i];
		p2+=s2[i];
	}
	if(p1==p2&&ad==1)
	{
		cout<<"1";
		as=1;
	}
	else 
	{
		cout<<"0"; 
	}
	if(s1[2]<='C'&&s2[2]<='C'&&as==1||s1[2]>='D'&&s1[2]>='D'&&as==1)
	{
		cout<<"1";
	}
	else
	{
		cout<<"0";
	}
	if(s1[2]+1==s2[2]&&s1[2]!='C')
	{
		cout<<"1";
	}
	else
	{
		cout<<"0";
	}
	return 0;
}	
