#include<bits/stdc++.h>

using namespace std;
#define ll long long 
#define ull unsigned long long 
#define int long long 
#define endl '\n'

const int N=515;
const int M=1000015;
const int inf=1e18;

int f[N][N];
vector<int> p[N];
vector<int> t[N];
int c,n,m,d,q;
int w[M];
vector< pair<int,int> > bel[M];
int val[M];

void solve()
{
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			f[i][j]=inf;
	for(int i=1;i<=n;i++) f[i][i]=0;
	for(int i=1;i<=m;i++) cin>>w[i];
	for(int i=1;i<=n;i++)
	{
		int k;
		cin>>k;
		for(int j=1;j<=k;j++)
		{
			int u,w;
			cin>>u>>w;
			p[i].push_back(u);
			t[i].push_back(w);
			bel[u].push_back({i,w});
		}
	}
//	for(int i=1;i<=m;i++) cout<<i<<" "<<(signed)bel[i].size()<<endl;
	for(int i=1;i<=n;i++)
		for(int j=i+1;j<=n;j++)
		{
			for(int k=0;k<p[i].size();k++)
				val[p[i][k]]=t[i][k];
			for(int k=0;k<p[j].size();k++)
				if(val[p[j][k]])
				{
					f[i][j]=min(f[i][j],val[p[j][k]]+t[j][k]);
					f[j][i]=f[i][j];
				}
			for(int k=0;k<p[i].size();k++)
				val[p[i][k]]=0;
		}
//	for(int i=1;i<=m;i++) cout<<i<<" "<<(signed)bel[i].size()<<endl;
	for(int k=1;k<=n;k++)
		for(int i=1;i<=n;i++)
			for(int j=1;j<=n;j++)
				f[i][j]=min(f[i][j],f[i][k]+f[k][j]);
	while(q--)
	{
		int u,v;
		int ans=inf;
		cin>>u>>v;
//		cout<<u<<" "<<v<<" "<<bel[u].size()<<" "<<bel[v].size()<<endl;
		for(int i=0;i<bel[u].size();i++)
		{
			int belu=bel[u][i].first;
			int wu=bel[u][i].second;
			for(int j=0;j<bel[v].size();j++)
			{
				int belv=bel[v][j].first;
				int wv=bel[v][j].second;
//				cerr<<f[belu][belv]<<endl;
				ans=min(ans,f[belu][belv]+wu+wv+w[u]+w[v]);
			}
		}
		cout<<ans<<endl;
	}
}

signed main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	int T=1;
//	cin>>T;
	while(T--)
		solve();
	return 0;
}
/*
n,m看反的来
只是把一个简单题看成了另外一个简单题
c，浪费20min
*/