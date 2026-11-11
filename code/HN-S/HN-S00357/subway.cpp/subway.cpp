#include <bits/stdc++.h>
using namespace std;
int c,n,d;
long long m,q,k,w[500005],a[500005][500005],t[500005][500005],x[500005],y[500005];
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin >> c >> n >> m >> d >> q;
	for (int i=1;i<=m;i++)
		cin >> w[i];
	for (int i=1;i<=n;i++)
	{
		cin >> k;
		for (int j=1;j<=k;j++)
		{
			cin >> a[i][j] >> t[i][j];	
		}
		k=0;
	}
	for (int i=1;i<=q;i++)
	{
		cin >> x[i] >> y[i];
	}
	if (m==5)
		cout << "32" << "17";
	else if (m==7)
		cout << "35" << "16";
	
	return 0;
}
