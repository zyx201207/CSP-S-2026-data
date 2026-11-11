#include<bits/stdc++.h>
using namespace std;
int n,m,p,q,x,y,z,a[500005],c[505][500005];
long long r,b[505][505];
vector <pair<int,int> > e[500005];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	scanf("%d%d%d%d%d",&n,&n,&m,&p,&q);
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			if(i!=j)b[i][j]=1e18;
	for(int i=1;i<=m;i++)
		scanf("%d",&a[i]);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&x);
		for(int j=1;j<=x;j++)
		{
			scanf("%d%d",&y,&z);
			e[y].push_back({i,z});
			c[i][y]=z;
		}
	}
	for(int i=1;i<=m;i++)
		for(int j=0;j<e[i].size();j++)
			for(int k=j+1;k<e[i].size();k++)
			{
				x=e[i][j].first;
				y=e[i][k].first;
				b[x][y]=min(b[x][y],1ll*e[i][j].second+e[i][k].second);
				b[y][x]=b[x][y];
			}
	for(int k=1;k<=n;k++)
		for(int i=1;i<=n;i++)
			for(int j=1;j<=n;j++)
			{
				b[i][j]=min(b[i][j],b[i][k]+b[k][j]);
				b[j][i]=b[i][j];
			}
	for(int i=1;i<=q;i++)
	{
		scanf("%d%d",&x,&y);
		r=1e18;
		for(int j=0;j<e[x].size();j++)
			for(int k=0;k<e[y].size();k++)
				r=min(r,b[e[x][j].first][e[y][k].first]+c[e[x][j].first][x]+c[e[y][k].first][y]);
		printf("%lld\n",r+a[x]+a[y]);
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
