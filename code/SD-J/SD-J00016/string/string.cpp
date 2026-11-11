#include<iostream>
#include<algorithm>
#include<cmath>

using namespace std;
#define ll long long
#define endl '\n'
const int N = 2e5 + 5;
int a[N]; char c[N];
int main() {
	ios :: sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	int n; cin >> n;
	for(int i = 1; i <= n; i++)
		cin >> a[i] >> c[i];
	ll ans = 0;
	auto nxt = [&](int &idx, int &d, int add) -> void {
		int p = abs(add);
		d += p;
		if(d == a[idx])
			idx += add / p, d = 0;
		return ;
	};
	
	for(int l = 1, r = n, dl = 0, dr = 0; l < r;) {
		int d = min(a[l] - dl, a[r] - dr);
		ans += d * (c[l] != c[r]);
		nxt(l, dl, d), nxt(r, dr, -d); 
	}
	cout << ans << endl;
	return 0;
}

