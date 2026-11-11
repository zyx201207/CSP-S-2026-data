#include<bits/stdc++.h>
using namespace std;
int t[5010][5010],w[5010],a[5010];
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	int c,n,m,d,q;
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=n;i++)
	{
		cin>>w[i];
	}
	for(int i=1;i<=n;i++)
	{
		int k;
		cin>>k;
		for(int j=1;j<=k;j++)
		{
			cin>>a[j]>>t[i][j];
		}
	}
	for(int i=1;i<=q;i++)
	{
		long long x,y;
		cin>>x>>y;
		cout<<w[x]+w[y]+t[1][x]+t[1][y];
	}
    return 0;
}
