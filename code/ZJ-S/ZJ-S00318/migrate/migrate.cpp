#include<bits/stdc++.h>
using namespace std;
const int N=2005;
long long x[N],d;
int n,min_de[N],cnt[N];
void dfs(int u,int de)
{
	if(de<min_de[u])
	{
		min_de[u]=de;
		cnt[u]=1;
	}
	else if(de==min_de[u])
	{
		cnt[u]++;
	}
	if(de>min_de[u])
	{
		return;
	}
	if(u==n)
	{
		return;
	}
	int l,r,i;
	l=u+1;
	r=upper_bound(x+u+1,x+n+1,x[u]+d)-x-1;
	for(i=r;i>=l;i--)
	{
		dfs(i,de+1);
	}
	return;
}
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int c,T,i,j,ans;
	cin>>c>>T;
	while(T--)
	{
		cin>>n>>d;
		for(i=1;i<=n;i++)
		{
			cin>>x[i];
		}
		x[n+1]=0x3f3f3f3f3f3f3f3f;
		ans=0;
		for(i=1;i<n;i++)
		{
			memset(cnt,0,sizeof(cnt));
			memset(min_de,0x3f,sizeof(min_de));
			dfs(i,0);
			for(j=i+1;j<=n;j++)
			{
				if(cnt[j]==2)
				{
					ans++;
				}
			}
		}
		cout<<ans<<"\n";
	}
	return 0;
}