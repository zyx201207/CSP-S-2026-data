#include<bits/stdc++.h>
using namespace std;
#define int long long
int c,t;
int n,k;
vector<int> e1[20];
int dis1[20],vis1[20];
const int N = 1e6+10;
vector<int> e[N];
void solve1()
{
	cin>>n>>k;
	for(int i=1;i<=n;i++) e1[i].clear();
//	for(int i=1;i<=n;i++) dis1[i]=1e9;
	for(int i=1;i<n;i++)
	{
		int u,v;
		cin>>u>>v;
		e1[u].push_back(v);
		e1[v].push_back(u);
	}
	int ans=1e9;
	for(int i=0;i<(1<<n);i++)
	{
		queue<int> q;
		for(int j=1;j<=n;j++) dis1[j]=1e9,vis1[j]=0;
		for(int j=1;j<=n;j++)
		{
			if(i&(1<<(j-1)))
			{
				q.push(j);			
				dis1[j]=0;
			}
		}
		int tmp=k;
		for(int j=1;j<=n;j++)
			for(auto l:e1[j])
				if(l>j&&(i&(1<<(l-1)))&&(i&(1<<(j-1)))) tmp--;
		if(tmp>2) continue; 
		if(q.size()!=k) continue;
		while(q.size())
		{
			int u=q.front();q.pop();
			if(vis1[u]) continue;
			vis1[u]=1;
			for(auto k:e1[u])
			{
				dis1[k]=min(dis1[k],dis1[u]+1);
				q.push(k);
			}
		}
		int res=0;
//		cerr<<i<<':';
		for(int j=1;j<=n;j++) res=max(res,dis1[j]);
//		cerr<<dis1[j]<<' ';
//		cerr<<'\n';
		ans=min(ans,res);
	}
	cout<<ans<<'\n';
}
void solve2()
{
	cin>>n>>k;
	for(int i=1;i<=n;i++)
	{
		int u,v;
		cin>>u>>v;
		e[u].push_back(v);
		e[v].push_back(u);
	}
	if(n==k) cout<<0<<'\n';
	else if(k>=n/2)
	{
		cout<<1<<'\n';
	}
	else
	{
		int m=n/2+2;
		int tmp=k;
		cout<<(m-tmp+3)/4<<'\n'; 
	}
}
signed main()
{
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin>>c>>t;
	if(c<=3)
	{
		while(t--)solve1();
	}
	if(c==13||c==14)
	{
		while(t--) solve2();
	}
	return 0;
}
