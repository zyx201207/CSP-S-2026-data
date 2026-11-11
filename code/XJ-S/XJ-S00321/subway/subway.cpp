#include<bits/stdc++.h>
using namespace std;

typedef unsigned long long int ulli;
ulli c,n,m,d,q,k,a[505][500005],t[505][500005],w[500005],x[100005],y[100005];

int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	int i,j;
	cin>>c>>n>>m>>d>>q;
	for (i=1; i<=m; i++)
		cin >> w[i];
	for (i=1; i<=n; i++)
	{
		cin >> k;
		for (j=1; j<=k; j++)
		{
			cin >> a[i][j] >> t[i][j];
		}
	}
	for (i=1; i<=q; i++)
		cin >> x[i] >> y[i];
	/* TODO (#1#): ≤ªª·¡À */
	return 0;
}
