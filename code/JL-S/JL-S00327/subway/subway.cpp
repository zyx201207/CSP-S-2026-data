#include <bits/stdc++.h>
using namespace std;
int c,n,m,d,q;
int w[500001];
int k[501][500001];//di i tiaoxianlu di j gezhantai
int g1[501];
int g2[501];
int x,y;
int ans=0;
int minn=9999999;
struct node
{
	int d[21];
};
node a[500001];//di x geditiezhan di  j  tiaoxianlu
void bfs(int x1,int y1)
{
	if(x1==y1) 
	{
		minn=min(ans,minn);
		return;
	}
	for(int i=1;i<=20;i++)
	{
		if(a[x1].d[i]!=0)
		{
			for(int j=1;j<=m;j++)
			{
				if(k[a[x1].d[i]][j]!=0)
				{
					ans=ans+k[x1][a[x1].d[i]]+k[a[x1].d[i]][j];
					bfs(j,y1);
					ans=ans-k[x1][a[x1].d[i]]+k[a[x1].d[i]][j];
				}
			}
		}
	}
}
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	//memset(h,0,sizeof(h));
	for(int i=1;i<=m;i++)
	{
		cin>>w[i];
		for(int j=1;j<=20;j++)
		{
			a[i].d[j]=0;
		}
	}
	int kk;
	for(int i=1;i<=n;i++)
	{
		cin>>kk;
		for(int j=1;j<=kk;j++)
		{
			cin>>x>>y;
			k[i][x]=y;
			a[x].d[j]=i;
		}
	}
	for(int i=1;i<=q;i++)
	{
		memset(g1,0,sizeof(g1));
		memset(g2,0,sizeof(g2));
		ans=0;
		cin>>x>>y;
		for(int j=1;j<=20;j++)
		{
			if(a[x].d[j]!=0) g1[j]=1;
			if(a[y].d[j]!=0) g2[j]=1;
		}
		for(int j=1;j<=500;j++)
		{
			if(g1[j]==1&&g2[j]==1)
			{
				//cout<<j<<endl;
				ans=ans+w[x]+w[y];
				ans=ans+k[j][x]+k[j][y];
				//cout<<k[j][x]<<" "<<k[j][y]<<endl;
				minn=min(ans,minn);
				ans=0;
				break;
				//continue;
			}
			else
			{
				ans=ans+w[x]+w[y];
				//ans=ans+k[j1][x1]+a[j1][x2]+a[j2][x3]+a[j2][x4]+a[j3][y];
				bfs(x,y);
			}
		}
	}
	cout<<minn;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
