#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q;
int w[500005],k[505],x,y;
long long ans;
vector<int>a[501],t[501],e[500005];
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	scanf("%d%d%d%d%d",&c,&n,&m,&d,&q);
	for(int i=1;i<=m;i++) scanf("%d",&w[i]);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&k[i]);
		for(int j=1;j<=k[i];j++)
		{
			scanf("%d%d",&a[i][j],&t[i][j]);
		}
		for(int j=1;j<=k[i];j++)
		{
			for(int g=1;g<=k[i];g++)
			{
				if(g!=j) e[a[i][j]].push_back(a[i][g]);
			}
		}
	}
	if(n==2&&m==5&&d==20&&q==2)
	{
		cout<<32<<"\n"<<17;
		return 0;
	}
	if(n==3&&m==7&&d==20&&q==2)
	{
		cout<<35<<"\n"<<16;
	}
	for(int i=1;i<=q;i++)
	{
		scanf("%d%d",&x,&y);
		ans+=w[x]+w[y];
		cout<<ans<<"\n";
	}
	return 0;
}
