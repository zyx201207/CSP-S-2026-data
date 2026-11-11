#include <bits/stdc++.h>

using namespace std;

const int N = 2e5 + 5;

int read() {
	int res = 0, si = 1;
	char ch = getchar();
	while (ch < '0' || ch > '9') { if (ch == '-') si = -si; ch = getchar(); }
	while (ch >= '0' && ch <= '9') res = 10 * res + ch - '0', ch = getchar();
	return res * si;
}

int main() {
	return 0;
}
