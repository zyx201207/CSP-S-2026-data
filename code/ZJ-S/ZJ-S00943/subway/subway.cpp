#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N=1005,C=500005;
LL F[N][N];
int n,w[N],D,m,o,Q,a[C],b[C];
int read()
{
	int ret=0,f=1;char c=getchar();
	while(!isdigit(c)){if(c=='-')f=-f;c=getchar();}
	while(isdigit(c))ret=(ret<<3)+(ret<<1)+(c&15),c=getchar();
	return ret*f;
}
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	o=read(),m=read(),n=read(),D=read(),Q=read();
	for(int i=1;i<=n;i++)w[i]=read();
	memset(F,63,sizeof F);
	for(int i=1;i<=n;i++)
		F[i][i]=0ll;
	for(int i=1;i<=m;i++)
	{
		int x=read();
		for(int j=1;j<=x;j++)a[j]=read(),b[j]=read();
		for(int i=1;i<=x;i++)
		for(int j=i+1;j<=x;j++)F[a[i]][a[j]]=F[a[j]][a[i]]=min(F[a[i]][a[j]],1ll*b[i]+b[j]);
	}
	for(int k=1;k<=n;k++)
	for(int i=1;i<=n;i++)
	for(int j=1;j<=n;j++)if(i!=k&&j!=k&&i!=j)F[i][j]=min(F[i][j],F[i][k]+F[k][j]);
	while(Q--)
	{
		int x=read(),y=read();
		printf("%lld\n",F[x][y]+w[x]+w[y]);
	}
}