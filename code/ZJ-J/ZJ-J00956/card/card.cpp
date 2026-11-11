#include<bits/stdc++.h>
using namespace std;
int n,m,st=0,dep=1;
int c[3000005],game[3000005],test[3000005],tj[30000005],ls[30000005];
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&c[i]);
	}
	for(int i=1;i<=n;i++)
	{
		memset(game,0,sizeof(game));
		memset(test,0,sizeof(test));
		memset(ls,0,sizeof(ls));
		dep=1;
		for(int j=i;j<=n;j++)
		{
			game[j]=c[j];
		}
		for(int j=i;j<=n;j++)
		{
			if(j>=2)
			{
				for(int k=1;k<j;k++)
				{
					if(st==1) {
						ls[test[k]]--;
						test[k]=0;
						continue;
					}
					if(game[j]==test[k])
					{
						st=1;
						dep=k+1;
					}
				}
				if(st==1){
					st=0;
					continue;
				}
			}
			test[dep++]=game[j];
			ls[game[j]]++;
		}
		for(int j=1;j<=m;j++)
		{
			if(ls[j]>=1) tj[j]++;
		}
	}
	for(int i=1;i<=m;i++)
	{
		if(tj[i]!=0) printf("%d ",tj[i]);
	}
	return 0;
}
