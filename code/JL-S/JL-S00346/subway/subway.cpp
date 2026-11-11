#include<bits/stdc++.h>
using namespace std;
long long int w[505],a[505][10005],t[505][10005],k[100005];
long long c,n,m,d,q,x,y;
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	scanf("%lld %lld %lld %lld %lld",&c,&n,&m,&d,&q);
	for(int i=1;i<=m;i++)
	{
		cin>>w[i];
	}
	for(int i=1;i<=n;i++)
	{
		cin>>k[i];
		for(int j=1;j<=k[i];j++)
		{
			cin>>a[i][j]>>t[i][j];
		}
	}
	for(int i=1;i<=q;i++)
	{
		cin>>x>>y;
		cout<<w[x]+w[y]+t[i][i+1]+t[i+1][i+1]<<"\n";
	}
}

