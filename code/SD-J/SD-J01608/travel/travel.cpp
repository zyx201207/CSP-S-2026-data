#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int n,m;
	string u,v;
	cin>>n>>u>>m>>v;
	if (n==m)
	{
		cout<<1;
		if (u[0]==v[0] && u[1]==v[1])
		{
			cout<<1;
			if(u[2]=='D' && v[2]=='F' || u[2]=='F' && v[2]=='D')
			{
				cout<<11;
			}
			else 
			{
				cout<<1;
				if (u[2]=='A' && v[2]=='B' || u[2]=='B' && v[2]=='C' || u[2]=='B' && v[2]=='A' || u[2]=='C' && v[2]=='B')
				{
					cout<<1;
				}
				else
				{
					cout<<0;
				}
			}
			
		}
		else
		{
			cout<<"000";
		}
	}
	else
	{
		cout<<"0000";
	}
	return 0;
} 
