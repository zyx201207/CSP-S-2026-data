#include<bits/stdc++.h>
using namespace std;
bool tree[10005][10005];
int d(int root,int n)
{
	int cnt=0;
	for(int i=1;i<=n;i++)
	{
		if(tree[root][i]) cnt=max(d(i,n)+1,cnt);
	}
	return cnt;
}
int main()
{
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	int c,t;
	cin>>c>>t;
	while(t--)
	{
		int n,k;
		cin>>n>>k;
		for(int i=1;i<n;i++)
		{
			int u,v;
			cin>>u>>v;
			tree[u][v]=true;
			tree[v][u]=true;
		}
		int ans=0;
		for(int i=1;i<=n;i++)
		{
			ans=max(ans,d(i,n));
		}
		cout<<ans<<endl;
	}
	return 0;
}
