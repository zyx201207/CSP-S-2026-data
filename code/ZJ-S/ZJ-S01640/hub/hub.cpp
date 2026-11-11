#include<bits/stdc++.h>
#define int long long
using namespace std;
const int inf=0x3f3f3f3f3f3f3f3f;
int n,k,m;
vector<int> e[1000005];
bool flag[1000005];
int a[1000005],dep[1000005],fa[1000005],md[1000005];
int f[1000005],g[1000005];
void dfsinit(int pos,int fa)
{
	::fa[pos]=fa;
	dep[pos]=dep[fa]+1;
	for(int x:e[pos])
		if(x!=fa)
			dfsinit(x,pos);
}
void dfsinit2(int pos,int fa)
{
	md[pos]=0;
	for(int x:e[pos])
		if(x!=fa&&!flag[x])
			dfsinit2(x,pos),md[pos]=max(md[pos],md[x]+1);
}
bool check(int x)
{
	int ans=inf;
	f[x]=0,f[x+1]=1;
	for(int i=x+2;i<=m;i++)
		f[i]=max(f[i-1],i-x-max(x-md[a[i]],0ll));
	g[m-x+1]=0,g[m-x]=1;
	for(int i=m-x-1;i>=1;i--)
		g[i]=max(g[i+1],m-x+1-i-max(x-md[a[i]],0ll));
	for(int i=x;i<=m-x;i++)
		ans=min(ans,f[i]+g[i+1]);
	for(int i=1;i<=n;i++)
		if(!flag[i]&&md[i]>=x)
			ans++;
	return ans<=k;
}
void test()
{
	cin>>n>>k;
    for(int i=1;i<=n;i++)
        e[i].clear(),flag[i]=0;
	for(int i=1;i<n;i++)
	{
		int u,v;
		cin>>u>>v;
		e[u].push_back(v);
		e[v].push_back(u);
	}
	dfsinit(1,0);
	int rt=0;
	for(int i=1;i<=n;i++)
		if(dep[i]>dep[rt])
			rt=i;
	dfsinit(rt,0);
	for(int i=1;i<=n;i++)
		if(dep[i]>dep[rt])
			rt=i;
	m=0;
	while(rt)
		a[++m]=rt,rt=fa[rt];
	for(int i=1;i<=m;i++)
		flag[a[i]]=1;
	for(int i=1;i<=m;i++)
		dfsinit2(a[i],0);
	int l=1,r=m>>1,mid;
	while(l<=r)
	{
		mid=l+r>>1;
		if(check(mid))
			r=mid-1;
		else
			l=mid+1;
	}
	cout<<l<<"\n";
}
signed main()
{
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int c,t;
	cin>>c>>t;
	for(int i=1;i<=t;i++)
		test();
}