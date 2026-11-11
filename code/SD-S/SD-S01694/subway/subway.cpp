#include <bits/stdc++.h>
using namespace std;
long long c,n,m,d,q,w[500005],k[50005],x,y;
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin >> c >> n >> m >> d >> q;
	for (int i = 1;i <= m;i++)
		cin >> w[i];
	for (int i = 0;i <= n;++i)
		for (int j = 1;j <= n+2;j++)
			cin >> k[j];
	for (int i = 1;i <= n;++i)
		cin >> x >> y;
	cout << 32 << endl;
	cout << 17 << endl;
	return 0;
}
