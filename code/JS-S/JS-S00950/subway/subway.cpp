#include<bits/stdc++.h>
using namespace std;

long long c,n,m,d,q;
long long a[500005],t[505][5005],x[100005],y[100005];

int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin >> c >> n >> m >> d >> q;
	for(int i = 1;i <= m;i++)
	{
		cin >> a[i];
	}
	for(long long i = 1;i <= n;i++)
	{
		cin >> t[i][1];
		for(long long j = 2;j <= 1LL + t[i][1] * 2LL;j++)
		{
			cin >> t[i][j];
		}
	}
	for(long long i = 1;i <= q;i++)
	{
		cin >> x[i] >> y[i];
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
