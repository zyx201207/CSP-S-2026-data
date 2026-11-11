#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define fst ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

const int P=998244353;
const long long INF=0x3f3f3f3f3f3f3f3f;
const int N=5e2+10,M=5e5+10;

int conid,n,m,d,q;
int w[M];
vector<int> a[N];
map<pair<int,int>,int> t;
vector<int> v[N];
bool vis[M];
int s,e;
long long ans;

void dfs(int x,long long y)
{
	cout<<x<<" "<<y<<endl;
	if(x==e)
	{
		ans=min(ans,0ll+y+w[e]);
		return;
	}
	vis[x]=1;
	for(auto l:v[x])
	{
		for(auto u:a[l])
		{
			if(vis[u]==0)
			{
				long long ny=y+t[{l,x}]+t[{l,u}];
				dfs(u,ny);
			}
		}
	}
	vis[x]=0;
}

void solve()
{
	cin>>s>>e;
	memset(vis,0,sizeof(vis));
	ans=INF;
	dfs(s,0ll+w[s]);
	cout<<ans<<endl;
}

int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	fst
	cin>>conid>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)
	{
		cin>>w[i];
	}
	for(int i=1;i<=n;i++)
	{
		int k;
		cin>>k;
		for(int j=1;j<=k;j++)
		{
			int x,y;
			cin>>x>>y;
			a[i].push_back(x);
			v[x].push_back(i);
			t[{i,x}]=y;
		}
	}
	while(q--)
	{
		solve();
	}
	return 0;
}

