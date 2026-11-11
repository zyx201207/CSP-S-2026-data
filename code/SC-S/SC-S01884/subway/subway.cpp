#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<cstring>
using namespace std;
int w[500005];
int cur[500005];
int id[500005][22];
int st[500005][22];
int kt[505];
long long  flo[1005][1005];
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	int c,n,m,d,q;
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)
	{
		scanf("%d",&w[i]);
	}
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&kt[i]);
		for(int j=1;j<=kt[i];j++)
		{
			int a,t;
			scanf("%d%d",&a,&t);
			id[a][++cur[a]]=i;
			st[a][cur[a]]=t;
		}
	}
	if(c<=11)
	{
		memset(flo,0x3f,sizeof(flo));
		for(int k=1;k<=m;k++)
		{
			for(int i=1;i<=m;i++)
			{
				if(i==k)flo[i][k]=0;
				else{
					for(int ji=1;ji<=cur[i];ji++)
					{	
						int jk=1;
						for(;jk<=cur[k];jk++)
						{
							if(id[i][ji]==id[k][jk])flo[i][k]=min(flo[i][k],0ll+st[i][ji]+st[k][jk]);
							if(id[k][jk]>=id[i][ji])break;
						}
					}
				}
				
			}
		}
		for(int j=1;j<=m;j++)
		{
			for(int i=1;i<=m;i++)
			{
				for(int k=1;k<=m;k++)
				{
					flo[i][k]=min(flo[i][k],flo[i][j]+flo[j][k]);
				}
			}
		}
	}

	while(q--)
	{
		int x,y;
		scanf("%d%d",&x,&y);
		if(c<=11)cout<<flo[x][y]+w[x]+w[y]<<endl;
	}
	return 0;
}