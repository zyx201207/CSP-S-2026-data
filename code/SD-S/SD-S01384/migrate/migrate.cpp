#include<bits/stdc++.h>
#define int long long 
//注意到 u,v 的一条路径一定是每次飞到最右端点
//现在在找另一条路径
//连接所有的可行端点，对每个节点分别跑一次拓扑排序
//nm，m在 n^2
//满足条件的路径可能相差多少？
//满足条件的路径只能有一个位置不同
//若存在两个位置不同，我就能找到第三条路径
//而考虑 u,v 间的一条最短路是每次能跳就跳远
//另一条只能和这个差一个点
//能否枚举异常点计数？
//分别找到异常点最右端能跳到的点和最左端能跳到的点 
//若相同，则只需要 
//我们去将每个点与其最右端能跳到的点连边
//如果两点间仅有一条路径，怎么办？
//我们去找异常点对
//异常点对的交集最大为 1 
using namespace std;
int read()
{
	int x=0,flag=1;
	char c=getchar();
	for(;!isdigit(c);c=getchar())if(c=='-')flag=-1;
	for(;isdigit(c);c=getchar())x=(x<<3)+(x<<1)+c-'0';
	return x*flag;
}
const int N = 5e4+6;
int L[N],R[N];
int a[N];
vector<int> g[N];
int in[N];queue<int> q;
struct node{
	int l,r;
};
int f[N],cnt[N];
int n,d;
vector<node> s,s2;
int ans=0;
void cal(int x)
{
	for(int i=x-1;i<=n;i++)g[i].clear(),in[i]=0;
	for(int i=x;i<=n;i++)
	{
		for(int j=i+1;j<=R[i];j++)g[i].push_back(j),++in[j];
	}
	while(q.size())q.pop();
	q.push(x);
	for(int i=x;i<=n;i++)f[i]=1e9,cnt[i]=0;
	f[x]=0;cnt[x]=1;
	while(q.size())
	{
		int u=q.front();q.pop();
		for(int v:g[u])
		{
			if(f[v]>f[u]+1)f[v]=f[u]+1,cnt[v]=cnt[u];
			else if(f[v]==f[u]+1)cnt[v]+=cnt[u];
			--in[v];
			if(!in[v])q.push(v);
		}
	}
	for(int i=x;i<=n;i++)if(cnt[i]==2)++ans;
}
void solve()
{
	n=read(),d=read();ans=0;
	for(int i=1;i<=n;i++)
	{
		a[i]=read();
	}
	int l=1;
	for(int i=1;i<=n;i++)
	{
		while(a[i]-a[l]>d)++l;
		L[i]=l;
	}
	int r=n;
	for(int i=n;i>=1;--i)
	{
		while(a[r]-a[i]>d)--r;
		R[i]=r;
	}
	for(int i=1;i<=n;i++)cal(i);
	printf("%lld\n",ans);
	
 } 
 void solve2()
 {
 	n=read(),d=read();ans=0;
	for(int i=1;i<=n;i++)
	{
		a[i]=read();
	}
	printf("0\n");
 }
 main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c=read(),t=read();
	while(t--)
	{
		if(c<=10)solve();
		if(c==11||c==12)solve2();
	}
	return 0;
}
