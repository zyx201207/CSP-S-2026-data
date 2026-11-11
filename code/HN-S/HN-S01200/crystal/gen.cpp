#include <bits/stdc++.h>
#define pii pair<int, int>
#define pll pair<ll, ll>
#define fi first
#define se second
using namespace std;
using ll = long long;
const int N = 4.5e5 + 5, P = 5e4;
int n;
int a[N];
int main() {
//	freopen("1.in", "r", stdin);
	freopen("crystal.in", "w", stdout);
	srand(unsigned(time(0)));
	ll a = rand();
	srand(unsigned(time(0)));
	ll b = rand();
	ll c = a * b % N;
	ll n = c + P;
	srand(unsigned(time(0)));
	ll d = rand() % P + 1;
	int e = rand() & 1;
	cout << n;
	d = 16;
	ll m = rand() * (ll)rand() * rand();
	cout << " " << m << "\n";
	for (int i = 1; i <= n; i ++) {
		cout << (d * (ll)i) << " ";
	}
	cout << endl;
	return 0;
}

