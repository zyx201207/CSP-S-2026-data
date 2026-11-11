#include<bits/stdc++.h>
#define int long long
using namespace std;

namespace Memory_Love{
	int read(){ int x=0; char ch=getchar(); bool flag=1;
		while(ch<'0' || ch>'9'){if(ch=='-') flag=0;ch=getchar();}
		while(ch>='0' && ch<='9'){x=(x<<3)+(x<<1)+(ch^48);ch=getchar();}
		return (flag==1? 1:-1)*x;}
	void write(int x,char ch=0){ if(x<0) x=-x,putchar('-');
		static short s[35],top=-1; do{s[++top]=x%10;x/=10;}while(x);
		while(~top) putchar(s[top--]+48); if(ch) putchar(ch);}
} using namespace Memory_Love;
const int N=1e6+5;
const int INF=0x3f3f3f3f3f3f3f3fll;
int n,m;
vector<int> G[N];

namespace GetRoot
{
	int SIZE[N],dist[N],son[N],root;
	void dfs1(int x,int fa)
	{
		SIZE[x]=1;
		for(auto y:G[x])
		{
			if(y==fa) continue;
			dfs1(y,x);
			SIZE[x]+=SIZE[y];
			if(SIZE[y]>SIZE[son[x]]) son[x]=y;
//			dist[x]=dist[y]+1;
		}
		if(max(SIZE[son[x]],n-SIZE[x])<=n/2) root=x;
	}
	int solve()
	{
//		dfs1(1,0); int x=10; cerr<<n<<' '<<max(SIZE[son[root]],n-SIZE[root])<<'\n';
//		for(int i=1;i<=n;i++) if(max(SIZE[son[i]],n-SIZE[i])>max(SIZE[son[root]],n-SIZE[root])) root=i;
//		cerr<<n<<' '<<max(SIZE[son[root]],n-SIZE[root])<<'\n';
//		return root;
		return root=1;
		dfs1(1,0); //cerr<<root<<'\n';
		return root;
	}
}

namespace SubK2 
{
	int Limit,Mdep[N],Mdist[N],cnt;
	void dfs(int x,int fa)
	{
		int Dist=-INF,Dep=-INF;
		for(auto y:G[x])
		{
			if(y==fa) continue; dfs(y,x);
			Dist=max(Dist,Mdist[y]-1);
		}
		for(auto y:G[x])
		{
			if(y==fa) continue;
			if(Mdep[y]+1<=Dist) continue;
			Dep=max(Dep,Mdep[y]+1);
		}
		if(Dist<0) Dep=max(Dep,0ll);
	//	cerr<<"Point ";
	//	cerr<<x<<' '<<Dist<<' '<<Dep<<'\n';
		if(Dep<Limit)
		{
			Mdep[x]=Dep;
			Mdist[x]=Dist;
			return ;
		}
		cnt++,Mdep[x]=-INF,Mdist[x]=Limit;
		return ;
	}
	
	bool check(int mid,int root)
	{
		Limit=mid; cnt=0;
		for(int i=1;i<=n;i++) Mdep[i]=-INF,Mdist[i]=0;
	//	for(int i=1;i<=n;i++) dp[i]=0;
		dfs(root,0); //cerr<<mid<<' '<<dp[1]<<' '<<m<<'\n';
//		if(mid==2) for(int i=1;i<=n;i++) cerr<<i<<' '<<Mdep[i]<<' '<<Mdist[i]<<'\n';
		return (cnt+(Mdep[1]>=0)<=m);
	}
	void Init()
	{
		for(int i=0;i<=n+3;i++)
		{
			G[i].clear();
		}
	}
	int Solve()
	{
//		cerr<<"\n\nNew Test\n";
		int i,u,v; Init(); n=read(),m=read();
		for(i=1;i<=n-1;i++)
		{
			u=read(),v=read();
			G[u].push_back(v);
			G[v].push_back(u);
		}
		
//		check(1);
		int root=GetRoot::solve();
		int left=0,right=n;
		while(left<right)
		{
			int mid=(left+right>>1);
			if(check(mid,root)) right=mid;
			else left=mid+1;
		}
//		cerr<<(int)(check(232,root))<<'\n';
		return left;
	}
}

namespace Sub123
{
	int ans,cnt,dist[N],Belong[N];
	bool vis[N];
	void dfs123(int x,int t)
	{
		Belong[x]=t;
		for(auto y:G[x])
		{
			if(!vis[y] || Belong[y]) continue;
			dfs123(y,t);
		}
	}
	int GetAns()
	{
		int i,t=0; queue<int> q;
//		for(i=1;i<=n;i++) if(vis[i]) cerr<<i<<' '; cerr<<"\n";
		for(i=1;i<=n;i++) Belong[i]=0;
		for(i=1;i<=n;i++)
		{
			if(vis[i])
			{
				q.push(i);
				dist[i]=0;
				if(!Belong[i]) dfs123(i,++t);
				if(t>2) return INF;
			}
			else dist[i]=INF;
		}
		while(q.size())
		{
			int x=q.front();
			q.pop();
			for(auto y:G[x])
			{
				if(dist[y]>dist[x]+1)
				{
					dist[y]=dist[x]+1;
					q.push(y);
				}
			}
		}
		int Max=0; for(i=1;i<=n;i++) Max=max(Max,dist[i]);
//		for(i=1;i<=n;i++) if(vis[i]) cerr<<i<<' ';
//		cerr<<Max<<'\n'; cerr<<"\n\n\n\n";
		return Max;
	}
	void dfs(int x)
	{
		if(x>n) return (void)(ans=min(ans,GetAns()));
		vis[x]=0; dfs(x+1);
		if(cnt==m) return ;
		vis[x]=1; cnt++; dfs(x+1); cnt--;
	}
	void Init()
	{
		cnt=0,ans=INF;
		for(int i=0;i<=n+3;i++)
		{
			G[i].clear();
			vis[i]=0;
		}
	}
	int Solve()
	{
		int i,u,v; Init(); n=read(),m=read();
		for(i=1;i<=n-1;i++)
		{
			u=read(),v=read();
			G[u].push_back(v);
			G[v].push_back(u);
		}
		dfs(1); return ans;
	}
}


signed main()
{
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	int c=read(),T=read();
	while(T--)
	{
		if(c<=3) write(Sub123::Solve(),'\n');
		else write(SubK2::Solve(),'\n');
//		cerr<<"\n\n\n\n\n\n\n\n\n\n\n\n\n";
	}
	return 0;
}
