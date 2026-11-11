#include <iostream>
#include <cstring>
#include <string>
using namespace std;
typedef long long ll;
ll n;
ll a[200005];
char b[200005];
ll out = 0;
string h;

void lr(int i) {
	for (ll j = 0; j < a[i]; j++) {
		h += b[i];
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	cin >> n;
	ll y = 0;
	for (ll i = 0; i < n; i++) {
		cin >> a[i] >> b[i];
		lr(i);
		y += a[i];
	}
	ll j = y - 1;
	for (ll i = 0; i <= j; i++, j--) {
		if (h[i] != h[j]) {
			out += 1;
		}
	}
	cout << out;
	return 0;
}

//#include <iostream>
//#include <cstring>
//#include <string>
//using namespace std;
//typedef long long ll;
//ll n;
//ll a[200005];
//char b[200005];
//ll out = 0;
//
//int main() {
//	ios::sync_with_stdio(false);
//	cin.tie(0);
//	cout.tie(0);
////	freopen("string.in", "r", stdin);
////	freopen("string.out", "w", stdout);
//	cin >> n;
//	ll y = 0;
//	for (ll i = 0; i < n; i++) {
//		cin >> a[i] >> b[i];
//		y += a[i];
//	}
//	char r, l;
//	ll p, q;
//	p = 0;
//	q = n - 1;
//	ll i = 0, j = y - 1;
//	while (p <= q) {
//		l = (i + 1 < a[p] ? b[p] : b[p + 1]);
//		r = (j - 1 > a[q] ? b[q] : b[q - 1]);
//		if (l == b[p + 1]) {
//			p += 1;
//		}
//		if (r == b[q - 1]) {
//			q -= 1;
//		}
//		if (l != r) {
//			out += 1;
//		}
//		i++;
//		j--;
//	}
//	cout << out;
//	return 0;
//}