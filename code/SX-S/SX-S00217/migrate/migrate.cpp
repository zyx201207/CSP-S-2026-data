#include <bits/stdc++.h>
using namespace std;

template <typename T> inline T read() {
	T x = 0; bool f = 1; char ch = getchar();
	while (ch < '0' || '9' < ch) { if (ch == '-') f = 0; ch = getchar(); }
	while ('0' <= ch && ch <= '9') x = x * 10 + (ch ^ 48), ch = getchar();
	return f ? x : -x;
}

typedef long long ll;

int n; ll sum;

int main() {
	freopen("test1.in", "r", stdin);
	freopen("test1.out", "w", stdout);

	return 0;
}
