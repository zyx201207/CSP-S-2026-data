#include <iostream>
using namespace std;
const int N = 100005;
int c,n,m,d,q,w[5*N],k[505],x[N],y[N];
int a[505][5*N],t[505][5*N];
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin >> c >> n >> m >> d >> q;
	for (int i = 1;i <= m;i++)
		cin >> w[i];
	for (int i = 1;i <= n;i++)
	{
		cin >> k[i];
		for (int j = 1;j <= k[i];j++)
			cin >> a[i][j] >> t[i][j];
	}
	for (int i = 1;i <= q;i++)
		cin >> x[i] >> y[i];
	return 0;
}
