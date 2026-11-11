#include<bits/stdc++.h>
#include<cstdio>
using namespace std;

const int maxn=505,maxm=5e5+5;
int c,n,m,d,q;
long long w[maxm];
int k[maxn],a[maxn][maxm];
long long t[maxn][maxm],ans;
bool sta[maxm][3];
int stanum[maxm];
int stalist[maxm][maxn];
long long shiftmin=2000000001;
int shinum[maxn];
int shilist[maxn][maxn];
long long shift[maxn][maxn];
bool qui[maxn];
void dfs(int now,long long pay,int end)
{
	if(now==end)
	{
		ans=min(ans,pay);
		return;
	}
	qui[now]=1;
	for(int i=1;i<=shinum[now];i++)
	{
		if(!qui[shilist[now][shinum[now]]])
		{
			dfs(shilist[now][shinum[now]],pay+shift[now][shilist[now][shinum[now]]],end);
		}
	}
	qui[now]=0;
	return;
}

int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	scanf("%d%d%d%d%d",&c,&n,&m,&d,&q);
	for(int i=1;i<=m;i++)
	{
		scanf("%lld",&w[i]);
	}
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&k[i]);
		for(int j=1;j<=k[i];j++)
		{
			scanf("%d%lld",&a[i][j],&t[i][a[i][j]]);
			if(n==2)sta[a[i][j]][i]=1;
			else 
			{
				stanum[a[i][j]]++;
				stalist[a[i][j]][stanum[a[i][j]]]=i;
			}
		}
	}
	if(n==2)
	{
		for(int i=1;i<=m;i++)
		{
			if(sta[i][1]&&sta[i][2])shiftmin=min(shiftmin,t[1][i]+t[2][i]);
		}
	}
	else
	{
		for(int i=1;i<=m;i++)
		{
			for(int j=1;j<=stanum[i];j++)
			{
				for(int j2=j+1;j2<=stanum[i];j2++)
				{
					shinum[stalist[i][j]]=stalist[i][j2];
					shinum[stalist[i][j2]]=stalist[i][j];
					shilist[stalist[i][j]][shinum[stalist[i][j]]]=stalist[i][j2];
					shilist[stalist[i][j2]][shinum[stalist[i][j2]]]=stalist[i][j];
					if(shift[stalist[i][j]][stalist[i][j2]]!=0)shift[stalist[i][j]][stalist[i][j2]]=min(t[stalist[i][j]][i]+t[stalist[i][j2]][i],shift[stalist[i][j]][stalist[i][j2]]);
					else shift[stalist[i][j]][stalist[i][j2]]=t[stalist[i][j]][i]+t[stalist[i][j2]][i];
				}
			}
		}
	}
	while(q--)
	{
		int st,ed;
		scanf("%d%d",&st,&ed);
		if(n==2)
		{
			ans=0;
			if(sta[st][1]&&sta[st][2])
			{
				if(sta[ed][1]&&sta[ed][2])
				{
					ans=min(t[1][st]+t[1][ed],t[2][st]+t[2][ed]);
					ans=ans+w[st]+w[ed];
					printf("%lld",ans);
				}
				else if(sta[ed][1])
				{
					ans=min(t[1][st],t[2][st]+shiftmin);
					ans=ans+w[st]+w[ed]+t[1][ed];
					printf("%lld",ans);
				}
				else
				{
					ans=min(t[2][st],t[1][st]+shiftmin);
					ans=ans+w[st]+w[ed]+t[2][ed];
					printf("%lld",ans);
				}
			}
			
			else if(sta[st][1])
			{
				if(sta[ed][1]&&sta[ed][2])
				{
					ans=min(t[1][st]+t[1][ed],t[1][st]+shiftmin+t[2][ed]);
					ans=ans+w[st]+w[ed];
					printf("%lld",ans);
				}
				else if(sta[ed][1])
				{
					ans=w[st]+w[ed]+t[1][st]+t[1][ed];
					printf("%lld",ans);
				}
				else
				{
					ans=w[st]+w[ed]+t[1][st]+shiftmin+t[2][ed];
					printf("%lld",ans);
				}
			}
			
			else
			{
				if(sta[ed][1]&&sta[ed][2])
				{
					ans=min(t[2][st]+t[2][ed],t[2][st]+shiftmin+t[1][ed]);
					ans=ans+w[st]+w[ed];
					printf("%lld",ans);
				}
				else if(sta[ed][2])
				{
					ans=w[st]+w[ed]+t[2][st]+t[2][ed];
					printf("%lld",ans);
				}
				else
				{
					ans=w[st]+w[ed]+t[2][st]+shiftmin+t[1][ed];
					printf("%lld",ans);
				}
			}
		}
		
		else
		{
			ans=1000000000000000007;
			for(int i=1;i<=stanum[st];i++)
			{
				for(int j=1;j<=stanum[ed];j++)dfs(stalist[st][stanum[st]],t[stalist[st][stanum[st]]][st]+t[stalist[ed][stanum[ed]]][ed],stalist[ed][stanum[ed]]);
			}
			ans=ans+w[st]+w[ed];
			printf("%lld\n",ans);
		}
	}
	return 0;
}
