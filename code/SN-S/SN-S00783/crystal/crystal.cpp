#include <bits/stdc++.h>
#define ll long long
using namespace std;
const ll N = 5e5 + 10;
ll n,m,B = 1,x,ans = 1,mx,op,a[N];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin >> n >> m;
	for (int i = 1;i <= n;i++) {
		cin >> a[i];
		if (i == 2) {
			op = a[i] - a[i - 1]; 
		}
		if (a[i] - a[i - 1] != op) B = 0;
	}
	sort(a + 1,a + n + 1);
	if (B) {
		long long ans1 = 1;
		for (int i = op;i <= m;i += op) {
			if (m <= 0) break;
			m -= i;
			ans1++; 
		}
		cout << ans1;
		return 0;
	}
	for (int i = 1;i <= n;i++) {
		ll nm = m,ans = 0;
		for (int j = i - 1;j >= 0;j--) {
			ans++;
			nm -= (a[i] - a[j]);
			if (nm < 0) {
				mx = max(mx,ans);
				break;
			}
		}
	}
	cout << mx;
	return 0;
}
