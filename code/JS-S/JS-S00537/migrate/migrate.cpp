#include<bits/stdc++.h>
using namespace std;
const int maxn=2e6+10;
int c,t,n,u,v;
long long x[maxn],d,dc,ans;
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>c>>t;
	while(t--)
	{
		cin>>n>>d;
		for(int i=1;i<=n;i++)
		{
			cin>>x[i];
		}
		// for(int i=1;i<n;i++)
		// 	for(int j=i+1;j<=n;j++)
		// 	{
		// 		u=i,v=j;
		// 		dfs(i,j);
		// 	}
		dc=x[2]-x[1];
		if(d<=dc||d>=x[n]-x[1])
			cout<<0<<'\n';
		else
			cout<<n<<'\n';
	}
	return 0;	
}