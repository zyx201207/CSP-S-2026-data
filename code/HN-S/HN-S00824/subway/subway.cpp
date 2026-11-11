#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 5e2+4;
int c,n,m,d,q;
int a[N][N],t[N][N],k[N],w[N],f[N][N];
struct edge
{
	int cnt,id;
};
vector<edge>b[N];
int main(void)
{
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)cin>>w[i];
	for(int i=1;i<=n;i++)
	{
		
		cin>>k[i];
		for(int j=1;j<=k[i];j++)
		{
			cin>>a[i][j]>>t[i][j];
			b[a[i][j]].push_back({i,j});
		}
	}
	for(int i=1;i<=m;i++)
	{
		for(int j=1;j<=m;j++)
		{
			f[i][j]=INT_MAX/2;
		}
		f[i][i]=0;
	}
	for(int i=1;i<=m;i++)
	{
		for(int j=1;j<=m;j++)
		{
			for(int x=0;x<int(b[i].size());x++)
			{
				for(int y=0;y<int(b[j].size());y++)
				{
					int h1=b[i][x].cnt,h2=b[j][y].cnt;
					if(h1==h2)for(int l=1;l<k[h1];l++)f[i][j]=min(f[i][j],min(f[i][l],f[l][j]));
					if(h1!=h2)
					{
						for(int l=1;l<=k[h1];l++)
						{
							int u=a[h1][l];
							for(int l2=1;l2<=k[h2];l2++)
							{
								int v=a[h2][l2];
								if(u==v)
								{
									int w=t[h1][l]+t[h2][l2];
									f[i][j]=min(f[i][j],f[i][u]+f[u][j]+w);
								}
							}
						}
					}
				}
			}
		}
	}
	while(q--)
	{
		int x,y;
		cin>>x>>y;
		cout<<f[x][y]+w[x]+w[y]<<endl;
	}
	for(int i=1;i<=m;i++)
	{
		for(int j=1;j<=m;j++)cout<<f[i][j]<<' ';
		cout<<endl;
	}
	return 0;
}
/*0 2 5 20 2
4 1 9 2 5
3 1 5 2 7 4 6
3 2 3 3 4 5 7
1 3 
1 2
*/
