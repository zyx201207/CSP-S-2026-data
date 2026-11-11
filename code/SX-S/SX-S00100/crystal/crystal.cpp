#include <bits/stdc++.h>
using namespace std;
long long a[1000000], c[1000000];
long long sum = 0;
long long js = 0, zjs = 0;

int main() {
	freopen("crystal .in", "r", stdin);
	freopen("crystal .out", "w", stdout);
	long long n, m;
	cin >> n >> m;
	cin >> a[0];
	for (int i = 1; i < n; i++) {
		cin >> a[i];
		c[i] = a[i] - a[i - 1];
	}
	for (int i = 1; i < n; i++) {
		js++;
		sum = sum  + c[i] * js;
		if (sum > m) {
			zjs = max(zjs, js );
			js = 0;
			i = i - js + 2;
			sum = c[i];
		}
	}
	cout << zjs;
	return 0;
}
