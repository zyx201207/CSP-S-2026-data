#include<bits/stdc++.h>
using namespace std;
long long w[50005],t[50005][50005],a[500010],k[510];
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	int c,n,m,q,d;
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)
	{
		cin>>w[i];
	}
	for(int i=1;i<=n;i++)
	{
		cin>>k[i];
		for(int j=1;j<=k[i];j++)
		{
			cin>>a[j]>>c;
		}
	}
	while(q--)
	{
		int x,y;
		cin>>x>>y;
		cout<<w[x]+w[y];
	}
	return 0;
}
