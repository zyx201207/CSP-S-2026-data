#include<bits/stdc++.h>
using namespace std;
int m,n,c,d,q,w[500007],k[507],x,y,z;
long long ans,f[507][507];
vector<array<int,2> >a[500007];
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	scanf("%d%d%d%d%d",&c,&n,&m,&d,&q);
	for(int i=1;i<=m;i++) scanf("%d",&w[i]);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&k[i]);
		for(int j=1;j<=k[i];j++)
		{
			scanf("%d%d",&x,&y);
			a[x].push_back({i,y});
			z=max(z,x);
		}
	}
	for(int i=1;i<=z;i++)
	{
		for(auto p:a[i])
		{
			for(auto q:a[i])
			{
				if(p==q) continue;
				if(f[p[0]][q[0]]==0||p[1]+q[1]<f[p[0]][q[0]]) f[p[0]][q[0]]=p[1]+q[1];
			}
		}
	}
	for(int i=1;i<=n;i++)
	{
		for(int k=1;k<=n;k++)
		{
			for(int j=1;j<=n;j++)
			{
				if(k==i||k==j||i==j) continue;
				if((f[i][j]==0||f[i][j]>f[i][k]+f[k][j])&&f[i][k]&&f[k][j])
				{
					f[i][j]=f[i][k]+f[k][j];
					f[j][i]=f[i][j];
				}
			}
		}
	}
	while(q--)
	{
		scanf("%d%d",&x,&y);
		ans=0;
		for(auto p:a[x])
		{
			for(auto q:a[y])
			{
				if(ans==0||ans>f[p[0]][q[0]]+p[1]+q[1]) ans=f[p[0]][q[0]]+p[1]+q[1];
			}
		}
		printf("%lld\n",ans+w[x]+w[y]);
	}
	return 0;
}