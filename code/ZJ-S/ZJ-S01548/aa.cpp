#include <bits/stdc++.h>
using namespace std;

using i32 = int; using i64 = long long;

#define For(i, l, r) for (i32 i = (l); i <= (r); i++)
#define Fep(i, l, r) for (i32 i = (l); i >= (r); i--)

int a[1 << 22][22];

int main() {
	
	i32 p = (1 <<22) - 1;
	i32 sum = 1;
	For(i, 1, 4e7) {
		a[i & p][i >> 22] = sum;
		sum += a[i & p][i >> 22];
	}
	cout << sum <<'\n';

	cerr << "TIMES:\t" << 1.0 * (clock()) / CLOCKS_PER_SEC << '\n';

	return 0;
}