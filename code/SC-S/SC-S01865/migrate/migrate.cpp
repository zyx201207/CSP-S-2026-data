#include<bits/stdc++.h>
using namespace std;
int c,t,r[2020202];
long long n,d,f[2020202];
constexpr long long inf=6e18;
queue<pair<int,int> > q;
long long mp[5050][5050];
namespace sub1{
	void bfs(int u)
	{
		int cnt=0,st=u;
		while(u<n)
		{
			int nx=r[u];
			if(nx==u) break;
			cnt++;
			while(u<nx) u++,mp[st][u]=cnt;
		}
		return ;
	}
	int tmp[440],vis[440];
	bool chk(int u,int to)
	{
		int len=0,st=u,cnt=1;
		for(int i=1;i<=n;i++) vis[i]=0;
		tmp[++len]=u,vis[u]=1;
		while(u<to)
		{
			if(u==r[u]) return 0;
			tmp[++len]=min(to,r[u]),u=min(to,r[u]),vis[u]=1;
			if(u==to) break;
		}
//		cout<<st<<" "<<to<<" "<<mp[st][to]<<'\n';
//		for(int i=1;i<=n;i++) cout<<vis[i]<<" ";cout<<"\n";
		for(int i=st+1;i<to;i++)
		{
			if(vis[i]==0&&mp[st][to]==mp[st][i]+mp[i][to]) cnt++;
		}
			
//		cout<<cnt<<"\n";
		if(cnt==2) return 1;
		return 0;
	}
	int main()
	{
		for(int i=1;i<=n+1;i++)
			for(int j=1;j<=n+1;j++) mp[i][j]=inf;
		for(int i=1;i<=n;i++) bfs(i);
		int ans=0;
		for(int i=1;i<=n;i++)
			for(int j=i+1;j<=n;j++)
				ans+=chk(i,j);
//		for(int i=1;i<=n;i++)
//			for(int j=1+i;j<=n;j++) if(chk(i,j)) cout<<i<<" "<<j<<"\n";
		cout<<ans<<"\n";
		return 0;
	}
}
namespace sub2{
	void main()
	{
		if(n<4) {cout<<"0\n";return ;}
		long long tmp=(f[2]-f[1]);
		if(tmp*2>d) {cout<<"0\n";return ;}
		cout<<max(0ll,n-((d/tmp)*2-1))<<"\n";
	}
}
void solve()
{
	cin>>n>>d;
	for(int i=1;i<=n;i++) cin>>f[i];f[n+1]=inf;
	for(int i=1;i<=n;i++) r[i]=upper_bound(f+1,f+n+1,f[i]+d)-(f+1);
	f[n+1]=inf;
	if(c<=10) {sub1::main();return ;}
	if(c>=11&&c<=12) {sub2::main();return ;}
	
}
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	int T;
	cin>>c>>T;
	while(T--) solve();
	return 0;
}