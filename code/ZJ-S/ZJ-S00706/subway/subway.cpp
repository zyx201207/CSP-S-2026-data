#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,p;
int w[10001];
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	scanf("%d %d %d %d %d",&c,&n,&m,&d,&p);
	for(int i=1;i<=m;i++)
	{
		scanf("%d",&w[i]);
	}
	for(int i=1;i<=n;i++)
	{
		int k;
		scanf("%d",&k);
		for(int j=1;j<=k;j++)
		{
			
		}
	}
	while(q--)
	{
		int x,y;
		int ans=0;
		scanf("%d %d",&x,&y);
		ans+=w[x];
		ans+=w[y];
		cout<<ans<<"\n";
	}
	return 0;
}