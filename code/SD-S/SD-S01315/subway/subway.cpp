#include<bits/stdc++.h>
using namespace std;
#define N 600		
#define M 500010	
#define D 25		
int Test_id;
int n,m,q;
int d;

long long w[M];

int k[N];

long long a[M][D][2];

long long T[N][N];
signed main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	memset(T,0x3f,sizeof(T));
	scanf("%d",&Test_id);
	scanf("%d%d%d%d",&n,&m,&d,&q);
	for(int i=1;i<=m;i++)
	{
		scanf("%lld",&w[i]);
	}
//	printf("???");
	for(int i=1;i<=n;i++)
	{
//		printf("%d %d\n",i,n);
		T[i][i]=0;
		scanf("%d",&k[i]);
		for(int j=1;j<=k[i];j++)
		{
			long long Sta,Tim;
			scanf("%lld%lld",&Sta,&Tim);
//			printf("	%lld\n",Sta);
			a[Sta][0][0]++;
			a[Sta][a[Sta][0][0]][0]=i;
			a[Sta][a[Sta][0][0]][1]=Tim;
//			printf("	%d %d\n",a[Sta][0][0],j);
		}
	}
	for(int i=1;i<=m;i++)
	{
		for(int j_a=1;j_a<=a[i][0][0];j_a++)
		{
			for(int j_b=j_a+1;j_b<=a[i][0][0];j_b++)
			{
				int S_a=a[i][j_a][0];
				int S_b=a[i][j_b][0];
				long long Tim=a[i][j_a][1]+a[i][j_b][1];
				T[S_b][S_a]=T[S_a][S_b]=min(T[S_a][S_b],Tim);
			}
		}
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			for(int k=1;k<=n;k++)
			{
				T[i][j]=min(T[i][k]+T[k][j],T[i][j]);
			}
		}
	}
	for(int i=1;i<=q;i++)
	{
		int x,y;
		scanf("%d%d",&x,&y);
		long long ans=0;
		ans=1e18;
		for(int j_x=1;j_x<=a[x][0][0];j_x++)
		{
			for(int j_y=1;j_y<=a[y][0][0];j_y++)
			{
				int S_a=a[x][j_x][0];
				int S_b=a[y][j_y][0];
				long long Tim=T[S_a][S_b];
				ans=min(ans,Tim+a[x][j_x][1]+a[y][j_y][1]);
			}
		}
		ans=ans+w[x]+w[y];
		printf("%lld\n",ans);
	}
	return 0;
	
}
