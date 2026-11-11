#include<bits/stdc++.h>
using namespace std;
#define int long long
char input[1<<20],*pf,*pe;
#define gc() (pf==pe&&(pe=(pf=input)+fread(input,1,1<<20,stdin),pf==pe)?EOF:*pf++)
int rdi()
{
	int n=0,c=gc();
	for(;!isdigit(c);c=gc());
	for(;isdigit(c);n=n*10+c-48,c=gc());
	return n;
}
const int N=535;
const int M=5e5+35;
int w[M];
struct node
{
	int id,t;
};
vector<node>g[M];
int f[N][N];
const int inf=1e17+35;
signed main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cout.tie(0);
	int c=rdi(),n=rdi(),m=rdi(),d=rdi(),q=rdi();
	int cc=c;
	int dd=d;
	swap(cc,dd);
	for(int i=1;i<=m;i++)
	{
		w[i]=rdi();
	}
	for(int i=1;i<=n;i++)
	{
		int k=rdi();
		for(int j=1;j<=k;j++)
		{
			int a=rdi();
			g[a].push_back({i,rdi()});
		}
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			f[i][j]=inf;
		}
		f[i][i]=0;
	}
	for(int i=1;i<=m;i++)
	{
		for(node u:g[i])
		{
			for(node v:g[i])
			{
				f[u.id][v.id]=f[v.id][u.id]=min(f[u.id][v.id],u.t+v.t);
			}
		}
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			for(int k=1;k<=n;k++)
			{
				f[j][k]=min(f[j][k],f[j][i]+f[i][k]);
			}
		}
	}
	for(int i=1;i<=q;i++)
	{
		int x=rdi(),y=rdi();
		int ans=inf;
		for(node u:g[x])
		{
			for(node v:g[y])
			{
				ans=min(ans,u.t+f[u.id][v.id]+v.t);
			}
		}
		cout<<ans+w[x]+w[y]<<'\n';
	}
	return 0;
}
//lpy