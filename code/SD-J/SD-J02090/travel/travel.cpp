#include<bits/stdc++.h>
#define CLOSE ios::syne_with_stdio(0),cin.tie(0),cout.tie(0);
#define endl "/n";
using namespace std;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int s1,s2;
	char c1[5],c2[5];
	cin>>s1;
	for(int i=0;i<3;i++)
	{
		cin>>c1[i];
	}
	cin>>s2;
	for(int i=0;i<3;i++)
	{
		cin>>c2[i];
	}
	if(s1==s2)
	{
		cout<<"1";
	}else
	{
		cout<<"0000";
		return 0;
	}
	for(int i=0;i<=1;i++)
	{
		if(c1[i]!=c2[i])
		{
			cout<<"000";
			return 0;
		}
	}
	cout<<"1";
	if(c1[2]=='A'||c1[2]=='B'||c1[2]=='C')
	{
		if(c2[2]=='A'||c2[2]=='B'||c2[2]=='C')
		{
			cout<<"1";
		}else
		{
			cout<<"00";
			return 0;
		}
	}else
	{
		if(c2[2]=='D'||c2[2]=='F')
		{
			cout<<"1";
		}else
		{
			cout<<"00";
			return 0;
		}
	}
	int z=c1[2],y=c2[2];
	if(z+1==y||y+1==z)
	{
		cout<<"1";
	}else
	{
		cout<<"0";
	}
	return 0;
}
