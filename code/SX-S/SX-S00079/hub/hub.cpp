#include <bits/stdc++.h>
#define ll long long
#define pll pair<ll,ll>
using namespace std;
ll c,t,mn=1e18,n,k,a[100005],fa[100005],cnt;
vector<ll> vt[300005];
ll bfs(ll r)
{
	queue<pll> q;
	bool vis[20005]={};
	q.push(make_pair(r,0));
	while(!q.empty())
	{
		pll fr=q.front();
		ll to=fr.first,st=fr.second;
		vis[to]=1;
		q.pop();
		ll yy=0;
		for(ll i=0;i<k;i++) if(to==a[i]) yy=1;
		if(yy) return st;
		for(auto i:vt[to]) if(vis[i]==0) q.push(make_pair(i,st+1));
	}
	return -1;
}
void dfs(ll step)
{
	if(step>=k)
	{
		ll mx=-1e18,lt=k;
		for(ll i=0;i<k;i++)
		{
			for(ll j=0;j<k;j++)
			{
				for(auto l:vt[i])
				{
					if(l==j) lt--;
				}
			}
		}
		if(lt>2) return;
		for(ll i=1;i<=n;i++)
		{
			ll f=0;
			for(ll j=0;j<k;j++) if(a[j]==i) f=1;
			if(f==0)
			{
				ll h=bfs(i);
				mx=max(mx,h);
			}
		}
		mn=min(mn,mx);
		return;
	}
	ll lst=cnt;
	for(ll i=cnt+1;i<=n;i++)
	{
		a[step]=i;
		cnt=i;
		dfs(step+1);
		cnt=lst;
	}
}
int main()
{
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>c>>t;
	while(t--)
	{
		cin>>n>>k;
		for(ll i=1;i<=n;i++) vt[i].clear();
		for(ll i=1;i<n;i++)
		{
			ll u,v;
			cin>>u>>v;
			vt[u].push_back(v);
			vt[v].push_back(u);
		}
		mn=1e18;
		cnt=0;
		dfs(0);
		cout<<mn;
		if(t>=1) cout<<"\n";
	}
	return 0;
}