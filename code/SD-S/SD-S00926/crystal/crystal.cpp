#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 5e5 + 10;
int n;
ll a[N],m,sum[N];
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	
	cin >> n >> m;
	for(int i = 1;i <= n;++i) cin >> a[i];
	sort(a + 1,a + n + 1);
	for(int i = 1;i <= n;++i) sum[i] = sum[i - 1] + a[i];
	int ans = 1,p = 1;
	for(int i = 2;i <= n;++i)
	{
		while(p <= i && a[i] * (i - p) - (sum[i - 1] - sum[p - 1]) > m) ++p;
		ans = max(ans,i - p + 1);
	}
	cout << ans;
	return 0;
}
