#include<bits/stdc++.h>
#define int long long
using namespace std;

const int N=510,M=5e5+10,D=23,INF=1e18;
int id,n,m,d,q;
int w0[M],tp,t[M][D];
int g[N][N];
int e[M][D],tot[M],w[M][D];

signed main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>id>>n>>m>>d>>q;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			g[i][j]=INF;
	for(int i=1;i<=n;i++)
		g[i][i]=0;
	
	for(int i=1;i<=m;i++)
		scanf("%lld",&w0[i]);
	for(int i=1;i<=n;i++)
	{
		int ttt;
		scanf("%lld",&ttt);
		for(int j=1;j<=ttt;j++)
		{
			scanf("%lld%lld",&tp,&t[i][j]);
			e[tp][++tot[tp]]=i;
			w[tp][i]=t[i][j];
		}
	}
	
//	for(int i=1;i<=m;i++)
//	{
//		for(int j=1;j<=tot[i];j++)
//			cout<<i<<": "<<e[i][j]<<" "<<w[i][e[i][j]]<<endl;
//		cout<<endl;
//	}
	
	for(int i=1;i<=m;i++)
	{
		for(int j=1;j<=tot[i];j++)
			for(int k=1;k<=tot[i];k++)
			{
				int ej=e[i][j],ek=e[i][k];
				g[ej][ek]=g[ek][ej]=min(g[ej][ek],w[i][ej]+w[i][ek]);
			}
	}
	
//	for(int i=1;i<=n;i++)
//	{
//		for(int j=1;j<=n;j++)
//			cout<<g[i][j]<<" ";
//		cout<<endl;
//	}
	
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			for(int k=1;k<=n;k++)
				g[i][j]=g[j][i]=min(g[i][j],g[i][k]+g[k][j]);
	
//	cout<<endl;
//	for(int i=1;i<=n;i++)
//	{
//		for(int j=1;j<=n;j++)
//			cout<<g[i][j]<<" ";
//		cout<<endl;
//	}
//	cout<<endl;
	
//	bool flag=false;
//	for(int i=1;i<=n;i++)
//		for(int j=1;j<=n;j++)
//			if(g[i][j]==INF)
//				flag=true;
//	if(flag)
//	{
//		cout<<"???"<<endl;
//		return 0;
//	}
	
//	for(int j=1;j<=tot[123];j++)
//		cout<<123<<": "<<e[123][j]<<" "<<w[123][e[123][j]]<<endl;
//	for(int j=1;j<=tot[123];j++)
//		cout<<131<<": "<<e[131][j]<<" "<<w[131][e[131][j]]<<endl;
//	cout<<g[14][15]<<endl;
	
	int x,y;
	while(q--)
	{
		scanf("%lld%lld",&x,&y);
		int ans=INF;
		for(int i=1;i<=tot[x];i++)
			for(int j=1;j<=tot[y];j++)
			{
				int ex=e[x][i],ey=e[y][j];
				ans=min(ans,w[x][ex]+w[y][ey]+w0[x]+w0[y]+g[ex][ey]);
//				cout<<x<<" "<<ex<<" ; "<<y<<" "<<ey<<endl;
//				cout<<w[x][ex]<<" "<<w[y][ey]<<" "<<w0[x]<<" "<<w0[y]<<" "<<g[ex][ey]<<endl;
			}
		printf("%lld\n",ans);
	}
	
	return 0;
}