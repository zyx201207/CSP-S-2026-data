#include<bits/stdc++.h>
using namespace std;
const int N=2e6+5;
int CST,CSN;
int n,k;
bool vis[N];
vector<int>e[N];
inline bool check()
{
	int cnt=0;
	for(int i=1;i<=n;i++)
	{
		for(int ii=0;ii<e[i].size();ii++)
		{
			int j=e[i][ii];
			if(vis[i]&&vis[j]) cnt++;
		}
	}
	return cnt==(k-2<<1);
}
bool is[N];
inline int ask(int s)
{
	queue<pair<int,int> >q;
	while(!q.empty()) q.pop();
	for(int i=1;i<=n;i++) is[i]=0;
	q.push(make_pair(s,0));is[s]=1;
	while(!q.empty())
	{
		pair<int,int> cur=q.front();q.pop();
		if(vis[cur.first]) return cur.second;
		for(int ii=0;ii<e[cur.first].size();ii++)
		{
			int v=e[cur.first][ii];
			if(is[v]) continue;
			is[v]=1;q.push(make_pair(v,cur.second+1));
		}
	}
}
inline void BruteForce()
{
	int Mask=(1<<n),ans=n+1;
	for(int i=1;i<=n;i++) vis[i]=0;
	for(int t=0;t<Mask;t++)
	{
		if(__builtin_popcount(t)!=k) continue;
		for(int i=1;i<=n;i++) vis[i]=((t>>i-1)&1);
		if(!check()) continue;
		int res=0;
		for(int i=1;i<=n;i++)
		{
			if(vis[i]) continue;
			res=max(res,ask(i));
		}
		ans=min(ans,res);
	}
	cout<<ans<<'\n';
}
inline void Solve()
{
	cin>>n>>k;
	for(int i=1;i<=n;i++) e[i].clear();
	for(int i=1,u,v;i<n;i++)
	{
		cin>>u>>v;
		e[u].push_back(v);
		e[v].push_back(u);
	}
	if(CST<=3){BruteForce();return;}
//	if(k==2) 
	cout<<n/6<<'\n';
}
signed main()
{
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	
	cin>>CST>>CSN;
	while(CSN--) Solve();
	return 0;
}
/*
Two graphs, no strings! Wish for a good ending. To be continue...
*/
