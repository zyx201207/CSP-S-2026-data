#include<bits/stdc++.h>
using namespace std;
#define int long long

const int N=1000005;
int n,k;
int dep[N];
vector<int> a[N];

void dfs(int u,int fa)
{
	dep[u]=dep[fa]+1;
	for(int v:a[u])
	{
		if(v==fa) continue;
		dfs(v,u);
	}
}

void init()
{
	for(int i=1;i<=n;i++) a[i].clear();
}

int cnt;
int c[N];

void dfs1(int u,int fa,int last,int ans)
{
	if(abs(dep[u]-dep[last])==2*ans+1) cnt++,last=u,c[u]++;
	for(int v:a[u])
	{
		if(v==fa) continue;
		dfs1(v,u,last,ans);
		c[u]+=c[v];
	}
}

bool check(int ans)
{
	cnt=1;
	for(int i=1;i<=n;i++) c[i]=0;
	dfs1(1,0,1,ans);
	if(cnt>k) return false;
	
	int sum=0;
	for(int i=0;i<(int)a[1].size();i++) sum+=c[a[1][i]];
	for(int i=0;i<(int)a[1].size();i++)
	{
		int s=sum-c[a[1][i]];
		int cnt1=s*ans;
		if(cnt1<=k-cnt)  return true;
	}
	return false;
}

void solve()
{
	cin>>n>>k;
	init();
	for(int i=1;i<n;i++)
	{
		int u,v; cin>>u>>v;
		a[u].push_back(v);
		a[v].push_back(u);
	}
	
	dfs(1,0);
	
	int l=0,r=n+1,ans=n+1;
	while(l<=r)
	{
		int mid=(l+r)>>1;
		if(check(mid))
		{
			r=mid-1;
			ans=mid;
		}
		else l=mid+1;
	}
	
	cout<<ans<<endl;
}

signed main()
{
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int test_id,t;
	cin>>test_id>>t;
	while(t--) solve();
	return 0;
}

