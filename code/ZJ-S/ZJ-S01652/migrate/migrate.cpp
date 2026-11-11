#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=511;
ll c,T,n,d,x[N],a[N],f[N][N],ans=0;
bool g[N][N];
queue<ll> pre;
vector<ll> e[N];
inline ll read()
{
	ll flag=1,tmp=0;
	char ch=getchar();
	while(ch<48||ch>57)
	{
		if(ch=='-')flag=-1;
		ch=getchar();
	}
	while(ch>=48&&ch<=57)
	{
		tmp=tmp*10+ch-'0';
		ch=getchar();
	}
	return flag*tmp;
}
void init()
{
	for(int i=1;i<=n;i++)
	{
		//a[i]=rng();
		for(int j=1;j<=n;j++)g[i][j]=f[i][j]=0;
		e[i].clear();
	}
	ans=0;
}
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	mt19937 rng(time(0));
	c=read(),T=read();
	while(T--)
	{
		n=read(),d=read();
		init();
		for(int i=1;i<=n;i++)x[i]=read();
		for(int i=1;i<=n;i++)
			for(int j=i+1;j<=n;j++)
			{
				if(x[i]+d>=x[j]&&!g[i][j])
				{
					g[i][j]=g[j][i]=1;
					e[i].push_back(j),e[j].push_back(i);
				}
			}
		for(int i=1;i<=n;i++)
			for(int j=1;j<=n;j++)
			{
				if(!g[i][j]||i==j||x[i]>x[j])continue;
				for(int k=0;k<e[i].size();k++)
				{
					ll s=e[i][k];
					//cout<<s<<endl;
					if(s==j||x[s]>x[i]||!g[s][j])continue;
					for(int d=0;d<e[j].size();d++)
					{
						ll t=e[j][d];
						//cout<<t<<endl;
						if(t==i||x[t]<x[j]||!g[i][t]||g[s][t])continue;
						if(!f[s][t])
						{
							f[s][t]=1;
							ans++;
						}
						else if(f[s][t]==1)
						{
							f[s][t]++;
							ans--;
						}
					}
				}
			}
		printf("%lld\n",ans);
	}
	return 0;
}