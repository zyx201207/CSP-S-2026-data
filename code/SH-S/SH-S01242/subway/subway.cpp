#include<bits/stdc++.h>
using namespace std;
#define int long long
namespace IO
{
	char buf[1<<16],*p1,*p2,ibuf;
	#define getchar() (p1==p2&&(p2=(p1=buf)+fread(buf,1,sizeof(buf),stdin)),p1==p2?EOF:*p1++)
	int rd(int x=0,int f=1)
	{
		for(;!isdigit(ibuf);ibuf=getchar())if(ibuf=='-')f=-1;
		for(;isdigit(ibuf);ibuf=getchar())x=x*10+(ibuf^48);
			return x*f;
	}
}
using IO::rd;
#define pii pair<int,int>
#define a first
#define b second
vector<pii>v[500050];
int w[500050];
int f[505][505];
void add(int x,int y,int t)
{
	f[y][x]=f[x][y]=min(f[x][y],t);
}
signed main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(false);
	cout.tie(0);
	int c=rd(),n=rd(),m=rd(),d=rd(),q=rd();
	for(int i=1;i<=m;i++)w[i]=rd();
	for(int i=0;i<n;i++)
	{
		int k=rd();
		for(int j=0;j<k;j++)
		{
			int x=rd(),t=rd();
			v[x].push_back({i,t});
		}
	}
	for(int i=0;i<n;i++)for(int j=0;j<n;j++)f[i][j]=(i==j?0:(int)1e18);
	for(int i=1;i<=m;i++)for(pii P:v[i])for(pii Q:v[i])add(P.a,Q.a,P.b+Q.b);
	for(int k=0;k<n;k++)for(int i=0;i<n;i++)for(int j=0;j<n;j++)f[i][j]=min(f[i][j],f[i][k]+f[k][j]);
	while(q--)
	{
		int x=rd(),y=rd();
		int ans=1e18;
		for(pii P:v[x])for(pii Q:v[y])ans=min(ans,f[P.a][Q.a]+P.b+Q.b);
		cout<<ans+w[x]+w[y]<<'\n';
	}
}