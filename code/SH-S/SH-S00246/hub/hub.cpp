#include<bits/stdc++.h>
using namespace std;
bool vis[1000005];
int n,K,z=0,anc[1000005];
int CD[25][25],dis[1000005];
queue<int>CQ;
vector<int>g[1000005],vp;
int ufind(int x)
{
	if(anc[x]==x) return x;
	return anc[x]=ufind(anc[x]);
}
void umerge(int x,int y)
{
	x=ufind(x),y=ufind(y);
	if(x!=y) anc[x]=y;
}
void dfsp(int now,int pre)
{
	for(auto nxt:g[now])
	{
		if(nxt==pre) continue;
		dis[nxt]=dis[now]+1,dfsp(nxt,now);
	}
	if(dis[now]>dis[z]) z=now;
}
void solvebf()
{
	for(int i=1;i<=n;i++)
	{
		for(int j=0;j<=n+2;j++) vis[j]=0;
		CQ.push(i),vis[i]=1,CD[i][i]=0;
		while(!CQ.empty())
		{
			int u=CQ.front();CQ.pop();
			for(auto v:g[u]) if(!vis[v]) CD[i][v]=CD[i][u]+1,vis[v]=1,CQ.push(v);
		}
	}
	int ans=n+5;
	for(int i=0;i<(1ll<<n);i++)
	{
		if(__builtin_popcount(i)!=K) continue;
		for(int j=0;j<=n+2;j++) vis[j]=0;
		for(int j=1;j<=n;j++) anc[j]=j;
		for(int j=0;j<n;j++) if((i>>j)&1) vis[j+1]=1;
		for(int j=1;j<=n;j++)
		{
			if(!vis[j]) continue;
			for(auto v:g[j]) if(vis[j]&&vis[v]) umerge(j,v); 
		}
		int tc=0;vp.clear();
		for(int j=1;j<=n;j++) if(vis[j]&&anc[j]==j) tc++;
		if(tc==2)
		{
			int res=0;
			for(int j=1;j<=n;j++)
			{
				int fps=n+5;
				for(int k=1;k<=n;k++) if(vis[k]) fps=min(fps,CD[j][k]);
				res=max(res,fps);
			}
			ans=min(ans,res);
		}
	}
	cout<<ans<<"\n";
}
void solve()
{
	cin>>n>>K;
	for(int i=0;i<=n+2;i++) g[i].clear();
	for(int i=1;i<=n-1;i++)
	{
		int u,v;cin>>u>>v;
		g[u].push_back(v),g[v].push_back(u);
	}
	if(n<=10)
	{
		solvebf();
		return;
	}
	else if(K<=2)
	{
		z=0,dis[1]=0,dfsp(1,-1);
		int st=z;
		dis[z]=0,z=0,dfsp(st,-1);
		int ed=z;
		if(K==1) cout<<(dis[ed]+1)/2<<"\n";
		else if(K==2) cout<<(dis[ed]+2)/3<<"\n";
		return;
	}
}
int main()
{
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0); 
	int cid,t;cin>>cid>>t;
	while(t--) solve();
	return 0;
}
/*
k<=2
*/
