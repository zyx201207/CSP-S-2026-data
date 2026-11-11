#include<bits/stdc++.h>
using namespace std;
int n,m,maxn=-1e9,cnt=0;
int a[200005];
bool vis[200005];
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	for(int i=1;i<=n;i++)
	{
		memset(vis,0,sizeof(vis));
		cnt=a[i];
		vis[i]=1;
		if(m>1)
		{
			for(int j=1;j<=n;j++)
			{
				if(vis[j]==0)
				{
					cnt&=a[j];
					vis[j]=1;
				}
				if(m>2)
				{
					for(int x=1;x<=n;x++)
					{
						if(vis[x]==0)
						{
							cnt&=a[x];
							vis[x]=1;
						}
						if(m>3)
						{
							for(int y=1;y<=n;y++)
							{
								if(vis[y]==0)
								{
									cnt&=a[y];
									vis[y]=1;
								}
								if(m>4)
								{
									for(int z=1;z<=n;z++)
									{
										if(vis[z]==0)
										{
											cnt&=a[z];
											vis[z]=1;
										}
										if(m>5)
										{
											for(int i1=1;i1<=n;i1++)
											{
												if(vis[i1]==0)
												{
													cnt&=a[i1];
													vis[i1]=1;
												}
												if(m>6)
												{
													for(int y1=1;y1<=n;y1++)
													{
														if(vis[y1]==0)
														{
															cnt&=a[y];
															vis[y1]=1;
														}
													}
												}
											}
										}
									}
								}
							}
						}
					}
				}
			}	
		}
		maxn=max(maxn,cnt);
	}	
	cout<<maxn;
	return 0;
}
