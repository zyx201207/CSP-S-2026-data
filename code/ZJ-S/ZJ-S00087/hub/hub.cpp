#include<bits/stdc++.h>
using namespace std;
int n,k;
vector<int> mp[2050001];
int be,ed;
int dep[2050001];
int vis[2050001],num;
int hev[2050001];
int sa[2050001];
void dfs1(int x,int fa)
{
	dep[x]=dep[fa]+1;
	if(dep[x]>dep[be])be=x;
	for(int i=0;i<mp[x].size();i++)
	{
		int v=mp[x][i];
		if(v==fa)continue;
		dfs1(v,x);
	}
}
void dfs2(int x,int fa)
{
	dep[x]=dep[fa]+1;
	if(dep[x]>dep[ed])ed=x;
	for(int i=0;i<mp[x].size();i++)
	{
		int v=mp[x][i];
		if(v==fa)continue;
		dfs2(v,x);
	}
}
void dfs3(int x,int fa)
{
	for(int i=0;i<mp[x].size();i++)
	{
		int v=mp[x][i];
		if(v==fa)continue;
		dfs3(v,x);
		if(vis[v]==1)
		{
			vis[x]=1;
			hev[++num]=x;
			break;
		}
	}
}
int sum=0;
void dfs4(int x,int fa,int cnt)
{
	for(int i=0;i<mp[x].size();i++)
	{
		int v=mp[x][i];
		if(v==fa || vis[v]==1) continue;
		dep[x]=max(dep[x],dep[v]+1);
	}
	if(dep[x]>=cnt)sum++;
}
bool ck(int cnt)
{
	memset(dep,0,sizeof dep);
	memset(sa,0,sizeof sa);
	int i,j,l,r,maxx=0;
	sum=2;
	sa[cnt+1]=1;
	sa[num-cnt]=1;
	for(i=cnt+2;i<=num-cnt-1;i++)
	{
		dfs4(hev[i],0,cnt);
		if(dep[hev[i]]>=cnt)sa[i]=1;
		else sum++;
	}
	for(i=cnt+1;i<num-cnt;i=r)
	{
		int zs=0;
		l=i;
		r=i+1;
		while(sa[r]==0)r++;
		for(j=l+1;j<=r-1;j++)
		{
			if(dep[hev[j]]+abs(j-l)<=cnt||dep[hev[j]]+abs(j-r)<=cnt)continue;
			int ka=dep[hev[j]]+abs(j-l)-cnt;
			int kb=dep[hev[j]]+abs(j-r)-cnt;
			if(ka<kb)
			{
				l+=ka;
			}
			else
			{
				r-=kb;
			}
		}
		maxx=max(maxx,r-l-1);
	}
	return sum-maxx<=k;
}
int main()
{
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	int c,t;
	cin>>c>>t;
	while(t--)
	{
		num=1;
		cin>>n>>k;
		int i;
		for(i=1;i<=n;i++)
		{
			mp[i].clear();
		}
		for(i=1;i<=n-1;i++)
		{
			int x,y;
			cin>>x>>y;
			mp[x].push_back(y);
			mp[y].push_back(x);
		}
		be=0,ed=0;
		memset(dep,0,sizeof dep);
		memset(vis,0,sizeof vis);
		dfs1(1,0);
		memset(dep,0,sizeof dep);
		dfs2(be,0);
		hev[1]=ed;
		vis[ed]=1;
		dfs3(be,0);
		int l=1,r=(num-1)/2,ans=(num-1)/2;
		if(k>=n)ans=0;
		while(l<=r)
		{
			int mid=(l+r)/2;
			if(ck(mid))
			{
				ans=min(ans,mid);
				r=mid-1;
			}
			else
			{
				l=mid+1;
			}
		}
		cout<<ans<<"\n";
	}
	return 0;
}
/*
use UTF-8 to open it
现在是17：46，记录一下我的感受吧
高三回来居然还有手感，15分钟切了T1，30分钟切了T2
T1：
观察到连续的水晶取一定不劣，双指针秒了
T2：
对线路做n^3的那个最短路，枚举询问的每个线路距离再加常数即可
T3：
只有一点模糊的思路，枚举首位，每次取最后三个位置向右拓展，这个双径对一定被她们拓展出来的
T4：
也是一点思路，两个基地至少都要有一部分在直径上
估计100+100+40(n^2)+?(?)=240
对于退役选手还算行吧
还是想冲一冲NOIP一等，执念太重了
哎QAQ，打个CSP这么费劲，我还有什么用呢？
乖乖回去首考吧，冲个420寒假还能放松一下
再见了CSP
freopen(".in","r",stdin);
freopen(".out","w",stdout);
feropen("hub.in","r",stdin);
feropen("hub.out","w",stdout);
有人看到的话帮忙放一下迷惑行为大赏，谨以此铭记我过去的青春
*/