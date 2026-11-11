#include <bits/stdc++.h>
#define ll long long
using namespace std;

const int N = 500010;
int n;
ll m, a[N];
ll ans = 0;

int main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m;
	for(int i = 1;i <= n;++ i) {
		cin >> a[i];
	}	
		
	sort(a + 1, a + n + 1);
	
	for(int i = 1;i < n;++ i)
		ans += a[n] - a[i];
		
	int pl = n;	
	for(int i = n;i >= 1;-- i) {
		if(m >= ans) {
			cout << pl;
			return 0;
		}
		
		else {
			ans -= (1ll * (a[i] - a[i - 1]) * (i - 1));
			pl --;
		}
	}
	
	return 0;
}
