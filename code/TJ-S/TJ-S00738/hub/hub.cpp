#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define pb push_back
#define mk make_pair
#define ppcnt __builtin_popcount
bool ST;
int n,k;
vector<int> g[1000010];
namespace Solve1
{
	bool tag[20],vis[20];
	int dep[20],d[20];
	void dfs(int x,int fa)
	{
		vis[x]=1;
		for(int i=0;i<g[x].size();++i)
		{
			int y=g[x][i];
			if(vis[y]||!tag[y])continue;
			dfs(y,x);
		}
	}
	void dfs2(int x,int fa)
	{
		dep[x]=dep[fa]+1;
		for(int i=0;i<g[x].size();++i)
		{
			int y=g[x][i];
			if(y==fa)continue;
			dfs2(y,x);
		}
	}
	void solve()
	{
		int ans=0x3f3f3f3f;
		for(int s=(1<<k)-1;s<(1<<n);++s)
		{
			if(ppcnt(s)!=k)continue;
			for(int i=1;i<=n;++i)tag[i]=(s>>(i-1))&1,vis[i]=0;
			int cnt=0;
			for(int i=1;i<=n;++i)
			{
				if(vis[i]||!tag[i])continue;
				dfs(i,0);
				cnt++;
			}
			if(cnt>2)continue;
			for(int i=1;i<=n;++i)d[i]=0x3f3f3f3f;
			for(int i=1;i<=n;++i)
			{
				if(!tag[i])continue;
				dep[0]=-1;
				dfs2(i,0);
				for(int j=1;j<=n;++j)d[j]=min(d[j],dep[j]);
			}
			int res=0;
//			cerr<<s<<"\n";
//			for(int i=1;i<=n;++i)cerr<<tag[i]<<" ";
//			cerr<<"\n";
			for(int i=1;i<=n;++i)if(!tag[i])res=max(res,d[i]);
			ans=min(ans,res);
		}
		cout<<ans<<"\n";
	}
}
namespace Solve2
{
	void solve()
	{
		if(n==k)
		{
			cout<<"0\n";
			return;
		}
//		cerr<<n<<" "<<k<<"\n";
		n=n/2+2;
//		cerr<<n<<"\n";
		if(k>=n-3)
		{
			cout<<"1\n";
			return;
		}
		if(k>=n-5)
		{
			cout<<"2\n";
			return;
		}
		n-=k;
		if(n%4==0)cout<<n/4+1<<"\n";
		else if(n%4==1)cout<<n/4+1<<"\n";
		else if(n%4==2)cout<<n/4+2<<"\n";
		else if(n%4==3)cout<<n/4+2<<"\n";
	}
}
bool ED;
int main()
{
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	std::ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	int C,T;
	cin>>C>>T;
	while(T--)
	{
		cin>>n>>k;
		for(int i=1;i<n;++i)
		{
			int u,v;
			cin>>u>>v;
			g[u].pb(v);
			g[v].pb(u);
		}
		if(n<=18)Solve1::solve();
		else if(C==13||C==14)Solve2::solve();
		for(int i=1;i<=n;++i)g[i].clear(),g[i].shrink_to_fit();
	} 
//	cerr<<"\nTime used: "<<1.0*clock()/CLOCKS_PER_SEC*1000<<"ms\n";
//	cerr<<"Memory used: "<<abs(&ED-&ST)/1024.0/1024.0<<"mb\n";
	return 0;
}
/*
直接二进制枚举有15pts
性质也是easy的，有10pts 
*/
