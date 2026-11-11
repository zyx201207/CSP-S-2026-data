#include<iostream>
#include<algorithm>
#include<cmath>
#include<bitset>

using namespace std;
#define ll long long
#define endl '\n'
const int N = 2e5 + 5;
int a[N];
bitset<N> used;
int main() {
	ios :: sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	int n, m, ans = 0; cin >> n >> m;
	for(int i = 1; i <= n; i++)
		cin >> a[i];
		
	used.set();
	for(int b = 29; b >= 0; b--) {
		int p = 1 << b, cnt = 0;
		for(int i = 1; i <= n; i++)
			cnt += used.test(i) && bool(a[i] & p);
		if(cnt >= m) {
			ans += p;
			for(int i = 1; i <= n; i++)
				if(!(a[i] & p))
					used.reset(i);
		}
	}
	cout << ans << endl;
	return 0;
}

