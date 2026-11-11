#include<iostream>
#include<cstdio> 
char a[11],b[11];
int n,m,x,y;
using namespace std;
int main()
{
	freopen("travel.in.txt","r",stdin);
	freopen("travel.out.txt","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n;
	cin>>a;
	cin>>m;
	cin>>b;
	if(n==m)
	{
		cout<<1;
		if(a[0]==b[0]&&a[1]==b[1])
		{
			cout<<1;
			if(a[2]<='C'&&b[2]<='C')
			{
				cout<<1;
				if(a[2]+1==b[2]||a[2]-1==b[2])
				{
					cout<<1;
				}
				else
				{
					cout<<0;
				}
			}
			else if(a[2]>='D'&&b[2]>='D')
			{
				cout<<1<<1; 
			}
			else
			{
				cout<<0<<0;
			}
			
		}
		else
		{
			cout<<0<<0<<0;
			return 0;
		}
	}
	else
	{
		cout<<0<<0<<0<<0;
		return 0;
	}
	return 0;
 } 
