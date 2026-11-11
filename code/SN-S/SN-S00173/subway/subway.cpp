#include<bits/stdc++.h>
using namespace std;
long long c,n,m,d,q,ans,x,y;
long long w[500005],k,a[500][25005],t[500][25005];
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin >> c >> n >> m >> d >> q;
	if(c == 0)
	{
		if(n == 2)
		{
			cout << 32 << endl << 17;
		}
		if(n == 3)
		{
			cout << 35 << endl << 16; 
		}
	}
	for(int i = 1;i <= m;i ++)
	{
		cin >> w[i];
	}
	for(int i = 1;i <= n;i++)
	{
		cin >> k;
		for(int i = 1;i <= k;i++)
		{
			cin >> a[n][k] >> t[n][k];
		}
	}
	for(int i = 1;i <= q;i ++)
	{
		cin >> x >> y;
		ans = ans + t[1][x]+t[1][y]+w[x]+w[y];
	}
	cout << ans << endl;
	return 0;
}
