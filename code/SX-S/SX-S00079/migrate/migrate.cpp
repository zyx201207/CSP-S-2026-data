#include <bits/stdc++.h>
#define ll long long
#define pll pair<ll,ll>
using namespace std;
ll c,t,n,d,x[2000005],ans;
vector<ll> vt[2000005];
ll bfs(ll r,ll g)
{
	ll zd=0,a=0;
	queue<pll> q;
	bool vis[20005]={};
	q.push(make_pair(r,0));
	while(!q.empty())
	{
		pll fr=q.front();
		ll to=fr.first,st=fr.second;
		vis[to]=1;
		q.pop();
		if(zd!=0&&st>zd) return a;
		if(to==g)
		{
			a++;
			zd=st;
		}
		for(auto i:vt[to]) if(vis[i]==0) q.push(make_pair(i,st+1));
	}
	return a;
}
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>c>>t;
	while(t--)
	{
		ans=0;
		cin>>n>>d;
		for(ll i=1;i<=n;i++) vt[i].clear();
		for(ll i=1;i<=n;i++)
		{
			cin>>x[i];
			for(ll j=1;j<i;j++)
			{
				if(x[i]-x[j]<=d)
				{
					vt[i].push_back(j);
					vt[j].push_back(i);
				}
			}
		}
		for(ll i=1;i<=n;i++)
		{
			for(ll j=1;j<i;j++)
			{
				if(bfs(i,j)==2) ans++;
			}
		}
		cout<<ans;
		if(t>=1) cout<<"\n";
	}
	return 0;
}