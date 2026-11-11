#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q,w[500005],cnt[500005];
long long sum=100000000000000,e[505][505];
struct Node
{
	long long l,t;
}a[500005][21];
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	memset(e,0x3f,sizeof(e));
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)
		cin>>w[i];
	for(int i=1,k;i<=n;i++)
	{
		cin>>k;
		for(int j=1,z,t;j<=k;j++)
		{
			scanf("%d%d",&z,&t);
			a[z][++cnt[z]].l=i;
			a[z][cnt[z]].t=t;
		}
	}
	for(int i=1;i<=m;i++)
	{
		if(cnt[i]>1)
		{
			for(int j=1;j<cnt[i];j++)
			{
				for(int k=j+1;j<=cnt[i];j++)
				{
					e[a[i][j].l][a[i][k].l]=min(e[a[i][j].l][a[i][k].l],a[i][j].t+a[i][k].t);
					e[a[i][k].l][a[i][j].l]=min(e[a[i][k].l][a[i][j].l],e[a[i][j].l][a[i][k].l]);
				}
			}
		}
	}
	for(int i=1;i<=n;i++)
		e[i][i]=0;
	/*for(int i=1;i<=m;i++)
	{
		for(int j=1;j<=cnt[i];j++)
		{
			cout<<a[i][j].l<<" "<<a[i][j].t<<" ";
		}
		cout<<endl;
	}*/
	for(int i=1;i<=n-1;i++)
	{
		for(int j=i+1;j<=n;j++)
		{
			if(i!=j)
			{
				for(int k=1;k<=n;k++)
				{
					if(e[i][k]+e[k][j]<e[i][j])
					e[i][j]=e[i][k]+e[k][j];
					e[j][i]=e[i][k]+e[k][j];
				}				
			}

		}
	}
	/*for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
			cout<<e[i][j]<<" ";
		cout<<endl;
	}*/
	for(int i=1,u,v;i<=q;i++)
	{
		scanf("%d%d",&u,&v);
		for(int j=1;j<=cnt[u];j++)
		{
			for(int k=1;k<=cnt[v];k++)
			{
				sum=min(sum,w[u]+w[v]+a[u][j].t+a[v][k].t+e[a[u][j].l][a[v][k].l]);
			}
		}
		cout<<sum<<endl;
		sum=100000000000000;
	}
	
	return 0;
}
