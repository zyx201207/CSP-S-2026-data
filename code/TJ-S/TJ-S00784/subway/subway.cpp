#include <bits/stdc++.h>
using namespace std;
const int N = 500005;
long long c,n,m,d,q;
int w[N],k,a[N],t[N],x,y,z[N];
int ans;
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin.tie(0);
	cout.tie(0);
	cin >> c >> n >> m >> d >> q;
	for(int i = 1;i <= m;i++) cin >> w[i]; 
	int sumz = 1;
	for(int i = 1;i <= n;i++)
	{
		cin >> k;
		for(int j = sumz;j <= k + sumz - 1;j++) cin >> a[j] >> t[j];
		sumz += k;
	}
	for(int i = 1;i <= q;i++)
	{
		cin >> x >> y;
		ans += w[x] + w[y];
	}
}
