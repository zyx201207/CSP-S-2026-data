#include <bits/stdc++.h>
using namespace std;
long long c,n,m,d,q,w[100000],a,b,z[100000],t[1000000],k;
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)
	{
		cin>>w[i];
	}
	for(int i=1;i<=n;i++)
	{
		cin>>k;
		for(int j=1;j<=k;j++)
		{
			cin>>z[j]>>t[j];
		}
	}
	cin>>a>>b;
	return 0;
}