#include <iostream>
#include <cstdio>
#include <vector>
#include <cmath>
using namespace std;
typedef long long LL;
LL read()
{
	char c=getchar();
	LL f=1,x=0;
	while(c<'0'||c>'9')
	{
		if(c=='-') f=-1;
		c=getchar();
	}
	while(c>='0'&&c<='9')
	{
		x=(x<<1)+(x<<3)+(c^'0');
		c=getchar();
	}
	return x*f;
}
void print(LL x)
{
	if(x<0)
	{
		putchar('-');
		x=-x;
	}
	if(x>9) print(x/10);
	putchar(x%10+'0');
}
const int N=2e6+5;
int n,f[N],g[N][2];
LL d,ans,a[N];
vector<int> e[N];
int main()
{
//	freopen("migrate6.in","r",stdin);
//	freopen("cdo.out","w",stdout);
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int _,T;
	_=read(),T=read();
	while(T--)
	{
		n=read(),d=read();
		for(int i=1;i<=n;i++) a[i]=read(),e[i].clear();
		
		f[n+1]=n;
		for(int i=n;i>=1;i--)
		{
			int x=f[i+1];
			while(x>i&&a[x]-a[i]>d) x--;
			f[i]=x;
			if(x!=i) e[x].push_back(i);
		}
		//cout<<"f:";for(int i=1;i<=n;i++) cout<<f[i]<<' ';cout<<endl;
		ans=0;
		for(int u=1;u<=n;u++)
		{
			g[u][0]=g[u][1]=0;
			int vx=max(0,f[u-1]-max(u,f[u-2])),vy=max(0,f[u]-max(u,f[u-1]));
			for(auto it=e[u].begin();it!=e[u].end();it++)
			{
				int v=*it;
				ans+=vx;
				if(f[v-1]<u-1) ans+=1ll*vx*g[v][0];
				ans+=1ll*vy*g[v][1];
				
				if(f[u]==f[u-1])
				{
					if(f[u-2]==f[u-1]||f[v-1]>=u-1) g[v][0]=0;
					g[v][1]=g[v][0]+(f[u-2]!=f[u-1]),g[v][0]=0;
				}
				else g[v][0]++;
				
				g[u][0]+=g[v][0],g[u][1]+=g[v][1];
			}
		}
		print(ans),putchar('\n');
	}
	return 0;
}
/*
0 1
5 2
1 2 3 4 5
*/