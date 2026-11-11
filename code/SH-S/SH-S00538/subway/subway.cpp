#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
using namespace std;
int c,n,m,d,q;//n地铁线路数，m地铁站数
struct node
{
	int to,w;
};
int no[500005];
int k[500005];
vector<int>a[505];
vector<int>t[505];
int f[5005][5005];
int tot;
void AAA()
{
	tot=m;
	memset(f,0x3f,sizeof f);
	for (int i=1;i<=n;i++)
	{
		cin>>k[i];
		tot++;
		for (int j=1;j<=k[i];j++)
		{
			int x,y;
			cin>>x>>y;
			f[tot][x]=y;
			f[x][tot]=y;
		}
	}
	int N=n+m;
//	for (int i=1;i<=n;i++)
//	{
//		for (int j=1;j<=k[i];j++)
//		{
////			g[++tot].push_back({a[i][j],t[i][j]});
////			g[a[i][j]].push_back({tot,t[i][j]});
//			f[++tot][a[i][j]]=t[i][j];
//			f[a[i][j]][tot]=t[i][j];
//		}
//	}
	for (int k=1;k<=N;k++)
	{
		for (int i=1;i<=N;i++)
		{
			for (int j=1;j<=N;j++)
			{
				f[i][j]=min(f[i][j],f[i][k]+f[k][j]);
			}
		}
	}
	while (q--)
	{
		int l,r;
		cin>>l>>r;
		cout<<no[l]+no[r]+f[l][r]<<endl;
	}
}
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout); 
	cin>>c>>n>>m>>d>>q;
	for (int i=1;i<=m;i++)
	{
		cin>>no[i];
	}
	AAA();
	
	return 0;
}
