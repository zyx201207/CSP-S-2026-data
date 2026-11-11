#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int a,b;
	char a1[3],b1[3];
	cin>>a>>a1>>b>>b1;
	if(a!=b)
	{
		cout<<"0000";
	}
	else if(a1[0]+a1[1]!=b1[0]+b1[1])
	{
		cout<<1000;
	}
	else
	{
		cout<<11;
		if(b1[2]-a1[2]==1 || a1[2]-b1[2]==1)
		{
			if(a1[2]=='C' && b1[2]=='D')
			{
				cout<<"00";
			}
			else if(a1[2]=='D' && b1[2]=='C')
			{
				cout<<"00";
			}
			else
			{
				cout<<11;
			}
		}
		else if(b1[2]-a1[2]==2 || a1[2]-b1[2]==2)
		{
			if(a1[2]=='C' && b1[2]=='A')
			{
				cout<<10;
			}
			else if(a1[2]=='A' && b1[2]=='C')
			{
				cout<<10;
			}
			else
			{
				cout<<"00";
			}
		}
		else
		{
			cout<<"00";
		}
	}
	return 0;
}
