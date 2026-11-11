#include<bits/stdc++.h>
using namespace std;
long long n,m,d,q,w[500010],k[510],a[510][500010],t[510][500010];
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>n;
	cin>>n>>m>>d>>q;
	for(long long i=1;i<=m;i++)
		cin>>w[i];
	for(long long i=1;i<=n;i++)
	{
		cin>>k[i];
		if(k[i]==1)
			i--,n--;
		else
			for(long long j=1;j<=k[i];j++)
			{
				cin>>a[i][j]>>t[i][j];
				x[a[i][j]][i]=1;
			}
	}
	while(q--)
	{
		cin>>x>>y;
		long long ans=w[x]+w[y];
	}
	return 0;
}
