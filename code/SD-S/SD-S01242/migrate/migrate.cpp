#include<bits/stdc++.h>
using namespace std;

int c,t,n;
long long tt,s,d,a[5010],ans;
int dist[5010][5010];

void dfs(int l,int r,int wz,int dis)
{
	if (tt>2) return;
	if (wz==r&&dis==dist[l][r]) tt++;
	if (dis>dist[l][r]) return;
	
	for (int i=1;i<=r-l;i++)
	{
		if (wz+i>r) break;
		
		if (a[wz+i]-a[wz] <= d)
		{
			dfs(l,r,wz+i,dis+1);
		}
		else break;
	}
	
	return;
}

int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	
	scanf("%d%d",&c,&t);
	while (t--)
	{
		
		scanf("%d%lld",&n,&d);
		for (int i=1;i<=n;i++)
		{
			scanf("%lld",&a[i]);
		}
		
		
		ans=0;
		
		for (int i=1;i<=n-1;i++)
		{
			s=a[i];
			for (int j=i+1;j<=n;j++)
			{
				tt=0;
				dist[i][j]=1;
				if (d>=a[j]-s&&dist[i][j-1]) dist[i][j]=dist[i][j-1];
				else if (d<a[j]-s) dist[i][j]++,s=a[j];
				
				if (dist[i][j]<j-i)
				{
					dfs(i,j,i,0);
					if (tt==2) ans++;
				}
			}
		}
		
		
		cout<<ans<<"\n";
	}
	
	return 0;
}
