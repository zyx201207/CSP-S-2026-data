#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>
#include <cstdio>
#include <queue>

using namespace std;
struct op
{
	int a,t;
}xl[505][100005];
int w[500005];
int k[505];
int ans;
int zzd[5005][5005];
int pzzd[5005];
//void dfs(int nw,int ed,int &ans)
//{
//	ans+=w[nw]
//}
struct opp
{
	int zi,zj;//zzd «µ⁄i∫≈œﬂ£¨j’æ 
}idzzd[5005];
int cnt;
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	int c,n,m,d,q;
	scanf("%d%d%d%d%d",&c,&n,&m,&d,&q);
	for(int i=1;i<=m;i++)
	{
		scanf("%d",&w[i]);
	}
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&k[i]);
		for(int j=1;j<=k[i];j++)
		{
			scanf("%d%d",&xl[i][j].a ,&xl[i][j].t );
			zzd[xl[i][j].a][++pzzd[xl[i][j].a]]=i;
			if(pzzd[xl[i][j].a]==2)
			{
				idzzd[++cnt].zi =i;
				idzzd[cnt].zj=j;
			}
		}
	}
	if(c!=0)
	{
		
		while(q--)
		{
			
			int x,y;
			scanf("%d%d",&x,&y);
			if(n==1)
			{
				ans=w[x]+w[y]+xl[1][x].t+xl[1][y].t;
			}
			else if(n==2)
			{
				int zii=idzzd[1].zi ,zjj=idzzd[1].zj;
				int f=0;int xxx=0,yyy=0;
				for(int i=1;i<=n;i++)
				{
					int xx=0,yy=0;
					for(int j=1;j<=k[i];j++)
					{
						if(xl[i][j].a ==x)
						{
							xx=1;
							xxx=i;
						}
						if(xl[i][j].a ==y)
						{
							yy=1;
							yyy=i;
						}
					}
					if((xx&&yy)||xl[zii][zjj].a==x||xl[zii][zjj].a==y)
					{
						ans=w[x]+xl[i][x].t+w[y]+xl[i][y].t ;
						f=1;
						break;
					}
				}
				if(f==0)
				{
					ans=w[x]+xl[xxx][x].t +xl[1][zjj].t+xl[2][zjj].t +xl[yyy][y].t +w[y];
				}
			}
			else
			{
//				for(int i=1;i<=n;i++)
//				{
//					for(int j=1;j<=k[i];j++)
//					{
//						if(xl[i][j].a==x)
//						{
//							
//						}
//					}
//				}
				if(cnt==1)
				{
					
					if(x==xl[idzzd[1].zi ][idzzd[1].zj ].a )
					{
						ans=w[x];
						int yyy=0;
						for(int i=1;i<=n;i++)
						{
							
							for(int j=1;j<=k[i];j++)
							{
								if(xl[i][j].a ==y)
								{
									yyy=i;
								}
							}
							
						}
						ans+=xl[yyy][x].t+w[y]; 
					}
				}
				
				
			}
			printf("%d\n",ans);
		}
	}
	cout<<endl;
	return 0;
}

