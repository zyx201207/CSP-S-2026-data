#include <bits/stdc++.h>
using namespace std;
const int maxn=5000005;
int c,n,m,d,q;
int w[maxn];
int k[maxn];
int a[501][500010];
int t[501][500010];
int dis[502][502];
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)
    {
    	cin>>w[i];//这部分根本不需要在最短路里出现！最后再加上 
	}
	for(int i=1;i<=n;i++)
	{
		cin>>k[i];
		cin>>a[i][1]>>t[i][1];
		for(int j=2;j<=k[i];j++)
		{
			cin>>a[i][j]>>t[i][j];
			for(int ll=1;ll<j;ll++)
			{
				dis[a[i][ll]][a[i][j]]=t[i][ll]+t[i][j];
				dis[a[i][j]][a[i][ll]]=t[i][ll]+t[i][j];
			}
		}
	}
	memset(dis,0x3f3f3f3f,sizeof(dis));
	for(int k=1;k<=n;k++)
	{
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=n;j++)
			{
				if(dis[i][k]+dis[k][j]<dis[i][j])//需要逆着写吗？ 
			    {
			    	dis[i][j]=dis[i][k]+dis[k][j]; 
				}
			}
		}
	}
	for(int i=1;i<=q;i++)
	{
		int x,y;
		cin>>x>>y;
		cout<<dis[x][y]+w[x]+w[y]<<endl;//注意一下需要用long long吗》 
	}
	return 0;
}
