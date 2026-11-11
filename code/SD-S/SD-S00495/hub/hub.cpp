#include <bits/stdc++.h>

#define IOS ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define rep(i,l,r) for(int i=l;i<=r;i++)
#define per(i,l,r) for(int i=r;i>=l;i--)
#define c1(x) __builtin_popcountll(x)
#define ull unsigned long long
#define lowbit(x) x&-x
#define int long long
#define pb push_back
#define db double

using namespace std;

typedef pair<int,int> pii;
typedef pair<db,db> pdd;

const int N=1e6+10;
int c,t,n,k,cv,ce,dep[N],fa[N],fa1[N][20];
bool vis[N],vv[N];
vector<int> g[N],ng[N]; 

void dfs(int u,int p)
{
	fa[u]=p;
	for(int v:g[u])
	{
		if(v==p) continue;
		dep[v]=dep[u]+1;
		dfs(v,u);
	}
}

int dis(int x,int y)
{
	rep(i,1,n) vis[i]=0;
	int tmp=dep[x]+dep[y];
	while(x)
	{
		vis[x]=1;
		x=fa[x];
	}
	int lca=0;
	while(y)
	{
		if(vis[y])
		{
			lca=y;
			break;
		}
		y=fa[y]; 
	}
	return tmp-2*dep[lca];
}

void dfs2(int x)
{
	vv[x]=1;
	for(int y:ng[x])
		if(!vv[y])
			dfs2(y);
}

//int lca(int x,int y)
//{
//	if(dep[x]<=dep[y]) swap(x,y);
//	per(i,0,18) if(dep[fa1[x][i]]>=dep[y]) x=fa1[x][i];
//	if(x==y) return x;
//	per(i,0,18) if(fa1[x][i]!=fa1[y][i]){x=fa1[x][i];y=fa1[y][i];}
//	return fa1[x][0];
//}

//int getdis(int x,int y)
//{
//	return dep[x]+dep[y]-2*dep[lca(x,y)];
//}

//void dfs3(int u)
//{
//	vv[u]=1;cv++;
//	for(int v:ng[u]) 
//	{
//		ce++;
//		if(!vv[v]) dfs3(v);
//	}
//}
//
//bool check(int d)
//{
//	rep(i,1,n) ng[i].clear(),vv[i]=0;
//	rep(i,1,n)
//		rep(j,1,n)
//			if(i!=j&&getdis(i,j)<=2*d)
//				ng[i].pb(j);
//	vector<pii> v;
//	rep(i,1,n) if(!vv[i]) cv=0,ce=0,dfs3(i),cnt++,v.pb({cv,ce});
//	
//}

void solve()
{
	cin>>n>>k;
	rep(i,1,n) g[i].clear();
	rep(i,1,n-1)
	{
		int u,v;
		cin>>u>>v;
		g[u].pb(v);
		g[v].pb(u);
	}
	dep[1]=0;
	dfs(1,0);
//	if(c<=3)
//	{
		int res=1e18;
		rep(i,0,(1<<n)-1)
		{
			if(c1(i)==k)
			{
				vector<int> v;
				rep(j,1,n) vv[j]=0,ng[j].clear();
				rep(j,1,n) if((i>>(j-1))&1) v.pb(j);
				for(int x:v)
					for(int y:v)
						if(fa[x]==y||fa[y]==x)
							ng[x].pb(y),ng[y].pb(x); 
				int cnt=0;
				for(int x:v) if(!vv[x]) dfs2(x),cnt++;
				if(cnt>2) continue;
				int ans=0;
				rep(j,1,n)
				{
					int md=1e18;
					for(int x:v) md=min(md,dis(x,j));
					ans=max(ans,md);
				}
	//			cout<<ans<<"\n";
				res=min(res,ans);
			}
		}
		cout<<res<<"\n";
//	}
//	else if(c==7) 
//	{
//		rep(i,1,n) fa1[i][0]=fa[i];
//		rep(j,1,18)
//			rep(i,1,n)
//				fa1[i][j]=fa1[fa1[i][j-1]][j-1];
//		int l=1,r=n,ans=-1;
//		while(l<=r)
//		{
//			int mid=l+r>>1;
//			if(check(mid)) 
//			{
//				ans=mid;
//				r=mid-1;
//			}
//			else l=mid+1;
//		}
//		cout<<ans<<"\n";
//	}
}

signed main()
{
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	IOS
	cin>>c>>t;
	while(t--) solve();
	return 0;
}
/*CSP-S 2026 AK RP++!
有没有写freopen?
数组是否开够？
有没有爆空间？
有没有交错代码？
0 3
8 6
4 8
5 8
6 3
3 2
2 1
1 8
7 8
6 5
1 2
2 5
4 5
5 3
3 6
9 3
1 2
2 8
4 7
6 5
7 9
8 5
5 3
3 9


*/

