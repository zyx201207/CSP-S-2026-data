#include<bits/stdc++.h>
using namespace std;
string a,b,c,d;
bool f()
{
	int x,y;
	for(int i=0;i<5;i++)
	{
		if('A'+i==b[2])
		{
			x=i+1;
		}
		if('A'+i==d[2])
		{
			y=i+1;
		}
	}
	for(int i=1;i<=3;i++)
	{
		if(x==i) x=0;
		if(y==i) y=0;
	}
	if(x==0&&y==0)
	{
		return 1;
	}
	else if(x!=0&&y!=0)
	{
		return 1;
	}
	return 0;
}
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	
	cin>>a>>b>>c>>d;
	if(a==c)
	{
		if(b[0]*10+b[1]==d[0]*10+d[1])
		{
			if(f())
			{
				if(b[2]==d[2]+1 || b[2]+1==d[2])
				{
					cout<<"1111";
				}
				else
				{
					cout<<"1110";
				}
			}
			else
			{
				cout<<"1100";
			}
		}
		else
		{
			cout<<"1000";
		}
	}
	else
	{
		cout<<"0000";
	}
	
	return 0;
} 
