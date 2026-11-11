#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
double b[100010];
string c;
int n, a[N];

int main() {
	//freopen("string.in","r",stdin);
	//freopen("string.out","w",stdout);
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i] >> c;
		for (int i = 0; i <= a[i]; i++) {
			c += c;
		}
	}
	return 0;
}