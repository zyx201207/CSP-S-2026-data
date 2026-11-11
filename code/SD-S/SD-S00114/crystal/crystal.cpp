#include <bits/stdc++.h>
#define int long long
using namespace std;
const int maxn = 5e5 + 5; 

int n, m;
int a[maxn];
int ans = -1;
bool flag1 = true;
bool flag2 = true;

signed main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);

	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	cin >> n >> m;
	for(int i = 1; i <= n; i++) {
		cin >> a[i];
		if(a[i] != i) flag1 = false;
	}
	
	if(flag1) {
		int sss = 0;
		for(int i = 1; i <= n; i++) {
			sss += i;
			if(sss > m) {
				cout << i;
				return 0;
			}
		}
	}
	
	sort(a + 1, a + 1 + n);
	
	for(int i = 3; i <= n; i++) {
		if(a[i] - a[i - 1] != a[i - 1] - a[i - 2]) flag2 = false;
	}
	
	if(flag2) {
		int cnt = a[n] - a[n - 1];
		int sss = 0;
		for(int i = 1; i <= n; i++) {
			sss += i * cnt;
			if(sss > m) {
				cout << i;
				return 0;
			}
		}
	}
	
	for(int i = 2; i <= n; i++) {
		int sum = 0;
		for(int j = i - 1; sum <= m && j >= 1; j--) {
			sum += a[i] - a[j];
			ans = max(ans, i - j + 1);
		} 
	}
	
	
	cout << ans;
	
	return 0;
}
