#include<bits/stdc++.h>
#define int long long 
using namespace std;
const int N=5e5+10;
int c,n,m,d,q;
int W[N],sz[505];
int e[505][505];
vector<pair<int,int> > a[N];
void floyd()
{
	for(int k=1;k<=n;k++)
	{
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=n;j++)
			{
				if(i==j || j==k || i==k) continue;
				e[i][j]=min(e[i][j],e[i][k]+e[k][j]);
			}
		}
	}
}
signed main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++) cin>>W[i];
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++) e[i][j]=1e18;
	for(int i=1;i<=n;i++)
	{
		cin>>sz[i];
		for(int j=1;j<=sz[i];j++)
		{
			int x,y;
			cin>>x>>y;
			a[x].push_back({i,y});
		}
	}
	for(int i=1;i<=n;i++)
	{
		e[i][i]=0;
	} 
	for(int i=1;i<=m;i++)
	{
		for(int j=0;j<a[i].size();j++)
		{
			for(int k=j+1;k<a[i].size();k++)
			{
				int id1=a[i][j].first,id2=a[i][k].first;
				e[id1][id2]=min(e[id1][id2],a[i][j].second+a[i][k].second);	
				e[id2][id1]=min(e[id2][id1],e[id1][id2]);
			} 
		}
	}
	floyd();
	while(q--)
	{
		int st,en;
		cin>>st>>en;
		int ans=1e18;
		for(auto i:a[st])
		{
			for(auto j:a[en])
			{
				int t1=i.first,t2=j.first;
				ans=min(ans,e[t1][t2]+i.second+j.second);
			}
		}
		cout<<W[st]+W[en]+ans<<"\n"; 
	} 
	return 0;
}
