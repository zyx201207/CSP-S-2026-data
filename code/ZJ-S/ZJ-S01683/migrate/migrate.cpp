#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

typedef long long LL;

namespace FastIO
{
	char buf[1<<20],*p1=buf,*p2=buf;
	#define gc() (p2==p1&&(p2=(p1=buf)+fread(buf,1,1<<20,stdin),p2==p1)?EOF:*p1++)
	inline LL read()
	{
		LL x=0,f=1; char c=gc();
		while (c<'0'||c>'9') if (c=='-') f=-1,c=gc(); else c=gc();
		while (c>='0'&&c<='9') x=x*10+c-'0',c=gc();
		return x*f;
	}
}
using FastIO::read;

const int INF=0x3f3f3f3f;
const int N=5e5+10;

LL a[N],n,d;
int cnt=0,best;

void dfs(int u,int ed,int dist)
{
	if (cnt>2||dist>best) return ;
	if (u>=ed)
	{
		best=dist;
		cnt++;
		return ;
	}
	for (int i=ed;i>=u+1;i--)
		if (a[i]-a[u]<=d) dfs(i,ed,dist+1);
}
int check(int n,int m)
{
	cnt=0,best=INF;
	dfs(n,m,0);
	cnt=0;
	dfs(n,m,0);
	return cnt;
}
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c=read(),t=read();
	while (t--)
	{
		n=read(),d=read();
		for (int i=1;i<=n;i++)
			a[i]=read();
		int ans=0;
		for (int l=1;l<=n;l++)
			for (int r=l+1;r<=n;r++)
				if (check(l,r)==2) ans++;
		printf("%d\n",ans);
	}
	return 0;
}
