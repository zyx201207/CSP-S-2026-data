#include <iostream>
using namespace std;
string a;
long long x;
string y;
long long ans = 0;

int main() {
	cin.tie(nullptr);
	freeopen("string","r",stdin);
	freeopen("string","w",stdout);
	long long n;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> x >> y;
		for (int i = 1; i <= x; i++) {
			a += y;
		}
	}
	long long len = a.length();
	for (int i = 0; i < (len / 2); i++) {
		if (a[i] != a[len - i]) {
			ans++;
		}
	}
	cout << ans - 1;
	return 0;
}
