#include <iostream>
#include <vector>
#include <cstdio>
using namespace std;
int cid,T;
int n,m;
vector<int> g[1000005];
bool flag[1000005];
bool vis[1000005];
int ans=2e9;
void dfs2(int x,int fa)
{
	vis[x]=true;
	for(int i=0;i<g[x].size();i++)
	{
		int y=g[x][i];
		if(y==fa) continue;
		if(flag[y]==false) continue;
		dfs2(y,x);
	}
}
int mindis=2e9;
void dfs3(int x,int fa,int dis)
{
	if(flag[x])
	{
		mindis=min(mindis,dis);
		return;
	}
	for(int i=0;i<g[x].size();i++)
	{
		int y=g[x][i];
		if(y==fa) continue;
		dfs3(y,x,dis+1);
	}
}
void dfs(int x,int tot)
{
	if(x>n)
	{
		if(tot!=m) return;
		for(int i=1;i<=n;i++) vis[i]=false;
		int block=0;
		for(int i=1;i<=n;i++)
		{
			if(flag[i]==false) continue;
			if(vis[i]) continue;
			dfs2(i,0);
			block++;
		}
		if(block>2) return;
		int maxn=0;
		for(int i=1;i<=n;i++)
		{
			mindis=1e9;
			dfs3(i,0,0);
			maxn=max(maxn,mindis);
		}
		ans=min(ans,maxn);
		return;
	}
	flag[x]=true;
	dfs(x+1,tot+1);
	flag[x]=false;
	dfs(x+1,tot);
}
void work()
{
	for(int i=1;i<=n;i++) flag[i]=false;
	ans=2e9;
	dfs(1,0);
	cout<<ans<<endl;
}
int cnt=0;
int f1[1000005],f2[1000005];
void calc(int x,int fa,int mid)
{
	f1[x]=-1e9,f2[x]=1e9;
	for(int i=0;i<g[x].size();i++)
	{
		int y=g[x][i];
		if(y==fa) continue;
		calc(y,x,mid);
		f1[x]=max(f1[x],f1[y]+1);
		f2[x]=min(f2[x],f2[y]+1);
	}
	if(f1[x]+f2[x]<=mid) f1[x]=-1e9;
	if(f2[x]>mid) f1[x]=max(f1[x],0);
	if(f1[x]==mid) 
	{
		cnt++;
		f1[x]=-1e9,f2[x]=0;
	}
}
bool check(int mid)
{
	cnt=0;
	calc(1,0,mid);
	if(f1[1]>=0) cnt++; 
	if(cnt<=2) return true;
	return false;
}
void work2()
{
	int l=0,r=n;
	ans=n;
	while(l<=r)
	{
		int mid=(l+r)/2;
		if(check(mid)) ans=mid,r=mid-1;
		else l=mid+1;
	}
	cout<<ans<<endl;
}
int fat[1000005];
void init(int x,int fa)
{
	fat[x]=fa;
	for(int i=0;i<g[x].size();i++)
	{
		int y=g[x][i];
		if(y==fa) continue;
		init(y,x);
	}
}
int dep[1000005],maxdep[1000005];
int lim;
void solve(int x,int fa)
{
	if(flag[x]) return;
	flag[x]=true;
	dep[x]=dep[fa]+1;
	maxdep[x]=dep[x];
	for(int i=0;i<g[x].size();i++)
	{
		int y=g[x][i];
		if(y==fa) continue;
		solve(y,x);
		maxdep[x]=max(maxdep[x],maxdep[y]);
	}
	if(maxdep[x]-dep[x]>=lim) cnt++;
}
void cov(int x,int fa,int dis)
{
	if(dis>lim) return;
	flag[x]=true;
	for(int i=0;i<g[x].size();i++)
	{
		int y=g[x][i];
		if(y==fa) continue;
		cov(y,x,dis+1);
	}
}
bool tmp[1000005];
int tmpcnt=0;
bool check2(int mid)
{
	lim=mid;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++) {
			flag[j]=false;
			maxdep[j]=0;
			dep[j]=0;
		}
		cnt=0;
		solve(i,fat[i]);
		if(cnt==0) cnt=1;
		cov(i,0,0);
		bool chk=true;
		for(int k=1;k<=n;k++)
		{
			if(flag[k]==false) 
			{
				chk=false;
				break;
			}
		}
		if(cnt>m) chk=false;
		if(chk==true) return true; 
		tmpcnt=cnt;
		for(int j=1;j<=n;j++) tmp[j]=flag[j];
		for(int j=1;j<=n;j++)
		{
			cnt=tmpcnt;
			for(int k=1;k<=n;k++) flag[k]=tmp[k],dep[k]=0,maxdep[k]=0;
			if(flag[j]) continue;
			solve(j,fat[j]);
			if(cnt==tmpcnt) cnt++;
			cov(j,0,0);
			chk=true;
			for(int k=1;k<=n;k++)
			{
				if(flag[k]==false) 
				{
					chk=false;
					break;
				}
			}
			if(cnt>m) chk=false;
			if(chk==true) return true; 
		}
	}
	return false;
}
void work3()
{
	cnt=0,tmpcnt=0;
	for(int i=0;i<=n;i++)
	{
		flag[i]=false;
		tmp[i]=false;
		dep[i]=0;
		maxdep[i]=0;
	}
	init(1,0);
	int l=0,r=n;
	ans=n;
	while(l<=r)
	{
		int mid=(l+r)/2;
		if(check2(mid)) ans=mid,r=mid-1;
		else l=mid+1;
	}
	cout<<ans<<endl;
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin>>cid>>T;
	while(T--)
	{
		cin>>n>>m;
		for(int i=1;i<=n;i++)
		{
			g[i].clear();
		}
		for(int i=1;i<=n-1;i++)
		{
			int u,v;
			cin>>u>>v;
			g[u].push_back(v);
			g[v].push_back(u);
		}
		if(cid<=3)
		{
			work();
			continue;
		}
		if(cid==7||cid==11||cid==12)
		{
			work2();
			continue;
		}
		work3();
	}
	return 0;
}
