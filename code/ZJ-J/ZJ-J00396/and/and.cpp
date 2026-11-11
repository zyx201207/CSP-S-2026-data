#include<bits/stdc++.h>
using namespace std;
const int mx=2e5+10;
int n,m;
int a[mx];
bool vis[mx];
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
		vis[i]=true;
	}
	int ans=0;
	for(int k=30;k>=0;k--)
	{
		int cnt=0;
		for(int i=1;i<=n;i++)
		{
			if(vis[i] && (a[i]>>k)&1)
			{
				cnt++;
			}
		}
		if(cnt>=m)
		{
			ans+=(1<<k);
			for(int i=1;i<=n;i++)
			{
				if(vis[i] && !((a[i]>>k)&1))
				{
					vis[i]=false;
				}
			}			
		}
	}
	printf("%d\n",ans);
	return 0;
}