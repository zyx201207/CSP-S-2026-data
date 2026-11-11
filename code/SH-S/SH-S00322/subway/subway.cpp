#include<bits/stdc++.h>
using namespace std;
const int N=500005,M=505,D=25;
int f[M][M][D],w[M],k[N];
int c,n,m,d,q,belongto[M][D];
void init()
{
	int i,j,l,ti,tj,tl;
	for(l=1;l<=m;l++)
	{
		for(i=1;i<=m;i++)
		{
			for(j=1;j<=m;j++)
			{
				int flag1=0,flag2=0,num=0;
				for(tl=1;tl<=belongto[l][0];tl++)
				{
					for(ti=1;ti<=belongto[i][0];ti++)
						if(belongto[i][ti]==belongto[l][tl])
							flag1=1;
					for(tj=1;tj<=belongto[j][0];tj++)
						if(belongto[j][tj]==belongto[l][tl])
							flag2=1;
					if(flag1&&flag2)
					{
						num=belongto[l][tl];
						break;
					}
				}
				f[i][j][num]=min(f[i][j][num],f[i][l][num]+f[l][j][num]);
			}
		}
	}
}
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	int i,j,s,t,u,we;
	memset(f,0x3f,sizeof(f));
	scanf("%d %d %d %d %d",&c,&n,&m,&d,&q);
	for(i=1;i<=m;i++)
		scanf("%d",&w[i]);
	for(i=1;i<=n;i++)
	{
		scanf("%d",&k[i]);
		for(j=1;j<=k[i];j++)
		{
			scanf("%d %d",&u,&we);
			belongto[u][++belongto[u][0]]=i;
			f[u][u][i]+=we;
		}
	}
	init();
	while(q--)
	{
		int minv=INT_MAX;
		scanf("%d %d",&s,&t);
		for(i=1;i<=n;i++)
			minv=min(minv,f[s][t][i]);
		printf("%d\n",w[s]+minv+w[t]);
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
