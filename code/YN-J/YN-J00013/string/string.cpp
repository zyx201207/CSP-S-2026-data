#include <bits/stdc++.h>
using namespace std;
int n;
int a[1000], step = 0;
char c[1000];
string sum;
int main() {
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a[i] >> c[i];
		for (int x = 1; x <= a[i]; x++) {
			sum += c[i];
		}
	}
	string sumx = sum;
	reverse(sumx.begin(), sumx.end());
	for (int j = 1; j < n; j++) {
		if (sum != sumx) {
			sum[j] = sumx[j];
			step++;
		}
	}
	cout << step;
	return 0;
}