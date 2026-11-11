#include<bits/stdc++.h>
#define pb push_back
#define LL long long
#define LOCAL
using namespace std;
const int N=5e2+10,M=5e5+10,D=25;
const LL INF=1e18;
LL c,n,m,d,q;
LL w[M];
LL dis[N][N];
vector<LL> sta[M],f[M];
LL rd()
{
	LL s=0,g=1;char c=getchar();
	while(!isdigit(c)){if(c=='-')g=-1;c=getchar();}
	while(isdigit(c)){s=(s<<3)+(s<<1)+(c-'0');c=getchar();}
	return s*g;
}
void wt(LL x)
{
	if(x<0){putchar('-');x=-x;}
	if(x>9){wt(x/10);}
	putchar(x%10+'0');
	return ;
}
int main()
{
	#ifdef LOCAL
		freopen("subway.in","r",stdin);
		freopen("subway.out","w",stdout);
	#endif
	c=rd();n=rd();m=rd();d=rd();q=rd();
	for(int i=1;i<=m;i++)
	{
		w[i]=rd();
	}
	for(int i=1;i<=n;i++)
	{
		LL k=rd();
		for(int j=1;j<=k;j++)
		{
			LL a=rd(),t=rd();
			sta[a].pb(i);
			f[a].pb(t);
		}
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			if(i==j)dis[i][j]=0;
			else dis[i][j]=INF;
		}
	}
	for(int i=1;i<=m;i++)
	{
		for(int j=0;j<sta[i].size();j++)
		{
			LL u=sta[i][j];
			for(int k=0;k<sta[i].size();k++)
			{
				LL v=sta[i][k];
				dis[u][v]=min(dis[u][v],f[i][j]+f[i][k]);
			}
		}
	}
	for(int k=1;k<=n;k++)
	{
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=n;j++)
			{
				dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
			}
		}
	}
	while(q--)
	{
		LL x=rd(),y=rd(),ans=INF;
		for(int i=0;i<sta[x].size();i++)
		{
			LL u=sta[x][i];
			for(int j=0;j<sta[y].size();j++)
			{
				LL v=sta[y][j];
				if(dis[u][v]!=INF)
				{
					ans=min(ans,f[x][i]+dis[u][v]+f[y][j]+w[x]+w[y]);
				}
			}
		}
		wt(ans),puts("");
	}
	#ifdef LOCAL
		fclose(stdin);
		fclose(stdout);
	#endif
	return 0;
}
