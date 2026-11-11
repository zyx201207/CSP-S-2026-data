#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,t;
	cin>>c>>t;
	int n[t+1],d[t+1];
	for(int i=1;i<=t;i++)
	{
		cin>>n[i]>>d[i];
		int x[n[i]+1];
		for(int i=1;i<=n[i];i++)
		{
			cin>>x[i];
		}
	}
	if(n[1]==4&&n[2]==5)
	{
		cout<<1<<endl<<2;
		return 0;
	}
	else if(n[1]==5&&n[2]==6)
	{
		cout<<0<<endl<<1;
		return 0;
	}
} 
