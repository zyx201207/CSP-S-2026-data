#include <bits/stdc++.h>
#define endl '\n'
#define int long long
using namespace std;
int a[500010],dif[500010],sum[500010];
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin.tie(nullptr)->sync_with_stdio(false);
	int n,m;
	cin >> n >> m;
	for (int i = 1;i <= n;i++)
		cin >> a[i];
	sort(a + 1,a + n + 1);
	for (int i = 1;i < n;i++)
		dif[i] = a[i + 1] - a[i];
	for (int i = 1;i < n;i++)
		sum[i] = sum[i - 1] + dif[i];
	int l = 1,r = n,ans = 0;
	while (l <= r){
		int mid = (l + r) >> 1,res = 0,num = 0;
		for (int i = 1;i < mid;i++)
			res += dif[i] * i;
		num = res;
		for (int i = 1;i <= n - mid;i++){
			res -= sum[i + mid - 2] - sum[i - 1];
			res += dif[i + mid - 1] * (mid - 1);
			num = min(num,res);
		}
		if (num > m)
			r = mid - 1;
		else
			l = mid + 1,ans = mid;
	}
	cout << ans << endl;
	return 0;
}

