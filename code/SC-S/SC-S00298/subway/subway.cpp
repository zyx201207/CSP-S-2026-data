#include <iostream>
#include <cstdio>
using namespace std;

const int MAXN=1e6+501,INF=1e9+1;
int c,n,m,d,q;
int W[MAXN];
int M[MAXN][MAXN];

int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	int m2=m*2;
	int all=m2+n;
	for(int i=1;i<=all;i++)
		for(int j=1;j<=i;j++)
		{
			if(i==j)M[i][j]=M[j][i]=0;
			else M[i][j]=M[j][i]=INF;
		}
	for(int i=1;i<=m;i++)
	{
		cin>>W[i];
		M[m+i][i]=M[i][m+i]=W[i];
	}
	for(int i=1;i<=n;i++)
	{
		int k;
		cin>>k;
		for(int j=1;j<=k;j++)
		{
			int a,t;
			cin>>a>>t;
			M[a][m2+i]=M[m2+i][a]=t;
		}
	}
	for(int i=1;i<=all;i++)
	{
		for(int k=1;k<=all;k++)
		{
			if(i==k)continue;
			for(int j=1;j<=all;j++)
			{
				if(i==j||j==k)continue;
				M[i][j]=M[j][i]=min(M[i][j],M[i][k]+M[k][j]);
			}
		}
	}
	for(int i=1;i<=q;i++)
	{
		int x=0,y=0;
		cin>>x>>y;
		if(x<=y)cout<<M[x+m][y+m]<<endl;
		else cout<<M[m+y][m+x]<<endl;
	}
	return 0;
}