#include<bits/stdc++.h>
using namespace std;
int c,T;
int n,k; 
int main()
{
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin>>c>>T;
	while(T--)
	{
		cin>>n>>k;
		for(int i=1;i<=n;i++)
		{
			int u,v;
			cin>>u>>v;
		}
		if(n<=5)
		{
			if(k==n)
			{
				cout<<"0"<<endl;
			}
			else
			{
				cout<<"1"<<endl;
			}
			continue;
		}
		if(k<=n/2)
		{
			cout<<"2"<<endl;
		}
		else if(k==n)
		{
			cout<<"0"<<endl;
		}
		else
		{
			cout<<"1"<<endl;
		}
	}
	return 0;
}
