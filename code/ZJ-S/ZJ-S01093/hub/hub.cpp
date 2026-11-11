#include<bits/stdc++.h>
using namespace std;
const int N=1000005;
int c,t;
int n,k;
int u,v;
vector<int>g[N];
int l,r,mid,ans;
int siz[N],dep[N];
void read(int &s)
{
	s=0;char c=getchar();int f=1;
	for(;c<48||c>57;c=getchar()) (c=='-')&&(f=-1);
	for(;c>47&&c<58;c=getchar()) s=(s<<1)+(s<<3)+(c^48);
	s*=f;
}
void dfs(int u,int fa)
{
	siz[u]=1;
	dep[u]=dep[fa]+1;
	for(int i=0;i<g[u].size();i++)
	{
		int v=g[u][i];
		if(v==fa) continue;
		dfs(v,u);
		siz[u]+=siz[v];
	}
}
int s[N];
void dp(int u,int fa)
{
	int sum=1e9;
	for(int i=0;i<g[u].size();i++)
	{
		int v=g[u][i];
		if(v==fa) continue;
		dp(v,u);
		sum=min(sum,s[v]);
	}
}
int d[20][20];
void floyd()
{
	for(int k=1;k<=n;k++)
	{
		for(int i=1;i<=n;i++)
		{
			if(i==k) continue;
			for(int j=i+1;j<=n;j++)
			{
				if(j==k) continue;
				d[i][j]=d[j][i]=min(d[i][j],d[i][k]+d[k][j]);
			}
		}
	}
}
bool check2(int x,int F)
{
	for(int i=1;i<=n;i++)
	{
		bool fl=0;
		if(F&(1<<(i-1))) continue;
		for(int j=1;j<=n;j++)
		{
			if(d[i][j]<=x&&(F&(1<<(j-1))))
			{
				fl=1;
				break;
			}
		}
		if(!fl) return 0;
	}
	return 1;
}
bool solve1(int x)
{
	for(int i=0;i<(2<<n);i++)
	{
		int cnt=0;
		for(int j=1;j<=n;j++) if(i&(1<<(j-1))) cnt++;
		if(cnt>k) continue;
//		cout<<x<<'\n';
//		cout<<check2(1,10)<<'\n';
		if(check2(x,i)) return 1;
	}
	return 0;
}
bool check(int x)
{
	if(c<=3) return solve1(x);
	else return 0;
}
int main()
{
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	read(c);read(t);
	for(;t;t--)
	{
		read(n);read(k);
		if(c<=3)
		{
			memset(d,0x3f,sizeof(d));
			for(int i=1;i<=n;i++) d[i][i]=0;
		}
		for(int i=1;i<=n;i++) g[i].clear();
		for(int i=1;i<n;i++)
		{
			read(u);read(v);
			g[u].push_back(v);
			g[v].push_back(u);
			if(c<=3) d[u][v]=d[v][u]=1;
		}
		if(c<=3) floyd();
		dfs(1,0);
		l=0,r=n;
		while(l<=r)
		{
			mid=(l+r)>>1;
			if(check(mid)) r=mid-1,ans=mid;
			else l=mid+1;
		}
		cout<<ans<<'\n';
	}
	return 0;
}
/*
take part in CSP for the 4th & the lst time.
goodbye, CSP.
*/