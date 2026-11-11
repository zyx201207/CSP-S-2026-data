#include <iostream>
#include <algorithm>
#include <cstdio>
using namespace std;
typedef long long ll;

inline ll read() {
	ll num = 0, sign = 1;
	char ch = getchar();
	while (ch < '0' || '9' < ch)
		sign = ch == '-' ? -1 : 1, ch = getchar();
	while ('0' <= ch && ch <= '9')
		num = (num << 1) + (num << 3) + ch - '0', ch = getchar();
	return sign < 0 ? -num : num;
}

int c, t;
int n, k;

int main() {
	freopen("hub.in", "r", stdin);
	freopen("hub.out", "w", stdout);

	return 0;
}