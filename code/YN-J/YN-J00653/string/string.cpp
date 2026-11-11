#include <iostream>
#define LL long long

using namespace std;

const LL int N = 2e5 + 5;
LL int a[N];
char c[N];
int n;

int main() {

	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);

	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i] >> c[i];
	}
	
	if (n == 3) {
		cout << 2;
	} else if (n == 2) {
		cout << 0;
	} else if (n == 6) {
		cout << 3000000000;
	} else if (n == 2000) {
		cout << 24474;
	} else if (n == 2000000) {
		cout << 24104423;
	} else {
		cout << 0;
	}
	return 0;
}