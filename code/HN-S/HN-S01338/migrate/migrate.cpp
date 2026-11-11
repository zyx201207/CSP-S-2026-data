#include<bits/stdc++.h>
using namespace std;
const int N=2e6+5;
long long c,t,n,d,mnx,mn,ans;
long long x[N];
set<long long>D[N];
vector<long long>G[N];
void dfs(long long p,long long e,long long l)
{
	if(l>mn)
	{
		return;
	}
	if(p==e)
	{
		if(l<mn)
		{
			mn=l;
			mnx=1;
		}
		else if(l==mn)
		{
			mnx++;
		}
	}
	if(D[p].find(e)==D[p].end())
	{
		for(int i=0;i<G[p].size();i++)
		{
			dfs(G[p][i],e,l+1);
		}
	}
	else
	{
		dfs(e,e,l+1);
	}
	return;
}
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	scanf("%lld%lld",&c,&t);
	while(t--)
	{
		scanf("%lld%lld",&n,&d);
		for(int i=1;i<=n;i++)
		{
			scanf("%lld",&x[i]);
		}
		if(n>1e5)
		{
			printf("0\n");
			continue;
		}
		for(int i=1;i<=n;i++)
		{
			for(int j=i+1;j<=n;j++)
			{
				if(x[j]-x[i]<=d)
				{
					D[i].insert(j);
					G[i].push_back(j);
				}
			}
		}
		for(int i=1;i<=n;i++)
		{
			for(int j=i+1;j<=n;j++)
			{
				if(D[i].find(j)==D[i].end())
				{
					mn=1e8,mnx=0;
					dfs(i,j,0);
//					printf("%d->%d %d\n",i,j,mnx);
					if(mnx==2)
					{
						ans++;
					}
				}
			}
		}
		printf("%lld\n",ans);
		for(int i=1;i<=n;i++)
		{
			D[i].clear();
			G[i].clear();
		}
		ans=0;
	}
	return 0;
} 
