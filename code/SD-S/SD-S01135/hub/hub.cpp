#include<bits/stdc++.h>
//#define int long long
#define ull unsigned long long
#define lowbit(x) (x&-x)
#define PII pair<int,int>
#define P(x,y) make_pair(x,y)
#define c(x) cout<<#x<<"="<<x<<endl;
using namespace std;
const int inf=1e9;
const int N=1e6+10;
vector<int> q[N];
int n,k;
vector<int> vec;
int dep[N],fat[N],maxdep[N];
bool vis[N];
void dfs(int u,int fa)
{
	for(auto to:q[u])
	{
		if(to==fa) continue;
		fat[to]=u;
		dep[to]=dep[u]+1;
		dfs(to,u);
	}
}
void dfs1(int u,int fa)
{
	for(auto to:q[u])
	{
		if(to==fa||vis[to]) continue;
		dep[to]=dep[u]+1;
		dfs1(to,u);
		maxdep[u]=max(maxdep[u],dep[to]);
	}
}
int dfs2(int u,int fa,int cur)
{
	int cnt=0;
	for(auto to:q[u])
	{
		if(to==fa||vis[to]) continue;
		if(maxdep[to]-dep[u]>cur) cnt+=dfs2(to,u,cur);
	}
	return cnt+1;
}
bool check(int mid)
{
	int l=mid,r=(int)vec.size()-1-mid;
	if(l>=r) return 1;
	int cnt=0;
	vector<int> p;
	vector<PII> p1;
	p.push_back(l);
	for(int i=l+1;i<r;i++)
	{
		int u=vec[i];
		if(maxdep[u]>mid)
		{
			cnt+=dfs2(u,-1,mid)-1;
			p.push_back(i);
		}
		else if(maxdep[u]+min(i-l,r-i)>mid)
		{
			int L=i-mid+maxdep[u];
			int R=mid+i-maxdep[u];
			p1.push_back({L,R});
		}
	}
	p.push_back(r);
	int minn=inf;
	for(int v=0;v<(int)p.size()-1;v++)
	{
		int L=p[v],R=p[v+1];
		for(int i=L;i<=R;i++)
		{
			int j=R;
			for(auto to:p1)
			{
				if(to.first>i) j=min(j,to.second);
			}
			minn=min(minn,i-l+2+r-j);
		}
	}

	return cnt+minn<=k;
}
void solve()
{
	cin>>n>>k;
	for(int i=1;i<n;i++)
	{
		int a,b;
		cin>>a>>b;
		q[a].push_back(b);
		q[b].push_back(a); 
	}
	dfs(1,1);
	int rt=0,maxx=0;
	for(int i=1;i<=n;i++)
	{
		if(maxx<dep[i])
		{
			maxx=dep[i];
			rt=i;
		}
	}
	for(int i=1;i<=n;i++) dep[i]=fat[i]=0;
	dfs(rt,-1);
	int b=0;
	maxx=0;
	for(int i=1;i<=n;i++)
	{
		if(maxx<dep[i])
		{
			maxx=dep[i];
			b=i;
		}
	}
	while(b)
	{
		vec.push_back(b);
		vis[b]=1;
		b=fat[b];
	}
	for(auto r:vec)
		dfs1(r,-1);
	int l=0,r=n;
	while(l<=r)
	{
		int mid=(l+r)>>1;
		if(check(mid)) r=mid-1;
		else l=mid+1;
	}
	cout<<l<<endl;
	for(int i=1;i<=n;i++)
	{
		q[i].clear();
		maxdep[i]=dep[i]=fat[i]=0;
		vis[i]=0;
	}
	vec.clear();
}
signed main()
{
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	int c,t;
	cin>>c>>t;
	while(t--)
	{
		solve();
	}
	return 0;
}
/*
0 2
5 2
1 2
2 3
3 4
4 5
10 3
1 2
1 3
2 4
2 5
3 6
3 7
3 8
7 9
9 10
*/

