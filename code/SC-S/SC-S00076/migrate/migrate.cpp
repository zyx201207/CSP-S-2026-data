#include<bits/stdc++.h>
using namespace std;
#define int long long
#define rep(i,l,r) for(int i=l;i<=r;i++)
#define per(i,r,l) for(int i=r;i>=l;i--)
#define gc() (p1==p2&&(p2=(p1=ibuf)+fread(ibuf,1,1<<20,stdin),p1==p2)?EOF:*p1++)
char ibuf[1<<20],*p1,*p2;
inline void read(int &x)
{
	x=0;bool f=0;char ch=getchar();
	for(;!isdigit(ch);ch=gc())if(ch=='-')f=1;
	for(;isdigit(ch);ch=gc())x=x*10+ch-'0';
	x=f?-x:x; 
}
template<typename ...Args>
void read(int &x,Args&...args)
{
	read(x);read(args...);
}
#define pii pair<int,int>
#define fi first
#define se second
#define ls (u<<1)
#define rs (u<<1|1)
#define mid (l+r>>1)
#define lson ls,l,mid
#define rson rs,mid+1,r
//
const int N=1e5+12,inf=1e18;
int C,T,n,D,a[N],d[N],g[N],du[N],ans,R[N];
vector<pii>G[N];
queue<int>q;
void solve()
{
	cin>>n>>D;
	rep(i,1,n)cin>>a[i];
	rep(i,1,n)
	{
		int r=i;
		rep(j,i,n)if(a[j]-a[i]<=D)r=j;
		R[i]=r;
	}
	rep(s,1,n)
	{
		rep(i,s,n)G[i].clear();
		rep(i,1,n)du[i]=0,g[i]=0,d[i]=inf;
		rep(i,s,n)rep(j,i+1,R[i])
		{
			G[i].push_back({j,1});
			du[j]++;
		}
		d[s]=0;g[s]=1;
		q.push(s);
		while(!q.empty())
		{
			int u=q.front();
			q.pop();
			for(auto p:G[u])
			{
				int v=p.fi,w=p.se;
				if(d[v]>d[u]+w)d[v]=d[u]+w,g[v]=g[u];
				else if(d[v]==d[u]+w)g[v]+=g[u];
				--du[v];
				if(!du[v])q.push(v);
			}
		}
		rep(i,s,n)if(g[i]==2&&d[i]<inf)ans++;
	}
	cout<<ans<<'\n';
	
	rep(i,1,n)G[i].clear();
	ans=0;
}

signed main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin.tie(0)->sync_with_stdio(0);
	cin>>C>>T;
	while(T--)solve();
	
	return 0;
}