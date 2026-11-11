#include<bits/stdc++.h>
#define int long long
using namespace std;
struct st
{
	int sub;
	int cos;
};
int n,m,c,d,b;
int walk_in[500002];
vector<st> lines[510];
vector<int> fa[500003];
int v[508][602];
map<pair<int,int>,int> ma;
signed main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	 for(int i=1;i<=502;i++)
	 {
	 	for(int j=1;j<=502;j++)
	 		v[i][j]=1e18;
	 }
	cin>>c>>n>>m>>d>>b;
	for(int i=1;i<=m;i++)
	{
		cin>>walk_in[i];
	}
	for(int i=1;i<=n;i++)
	{
		int k;
		cin>>k;
		for(int j=1;j<=k;j++)
		{
			int u,v;
			cin>>u>>v;
			ma[{i,u}]=v;
//			cout<<ma[{i,u}]<<"\n";
			fa[u].push_back(i);
		}
	}
//	for(int i=1;i<=m;i++)
//	{
//		cout<<i<<":";
//		for(auto x:fa[i])
//			cout<<x<<" ";
//		cout<<"\n";
//	}
	for(int i=1;i<=m;i++)
	{
		for(int j=0;j<fa[i].size();j++)
		{
			for(int k=j+1;k<fa[i].size();k++)
			{
			//	cout<<j<<" "<<k<<"\n";
				v[fa[i][j]][fa[i][k]]=ma[{fa[i][j],i}]+ma[{fa[i][k],i}];
				v[fa[i][k]][fa[i][j]]=v[fa[i][j]][fa[i][k]];
			}
		}
	}
//		for(int i=1;i<=n;i++)
//	{
//		for(int j=1;j<=n;j++)
//		{
//			cout<<v[i][j]<<" ";
//		}
//		cout<<"\n";
//	}
for(int i=1;i<=n;i++)
		v[i][i]=0;
	for(int i=1;i<=n;i++)
	{
		for(int j=i+1;j<=n;j++)
		{
			for(int k=1;k<=n;k++)
			{
				if(k!=i&&k!=j)
				{
					v[i][j]=min(v[i][j],v[i][k]+v[k][j]);
					v[j][i]=v[i][j];
				}
			}
		}
	}
	
	while(b--)
	{
		int s,t;
		cin>>s>>t;
		long long ans=1e18;
		for(auto i:fa[s])
		{
			for(auto j:fa[t])
			{
				ans=min(ans,walk_in[s]+walk_in[t]+v[i][j]+ma[{i,s}]+ma[{j,t}]);
			}
		}
		cout<<ans<<"\n";
	}
	return 0;
}
/*
0 2 5 20 2
4 1 9 2 5
3 1 5 2 7 4 6
3 2 3 3 4 5 7
1 3 
1 2

0 3 7 20 2
8 3 6 1 7 2 9
3 1 4 2 5 5 100
3 2 6 3 1 7 2
4 3 2 5 100 4 6 6 7
*/