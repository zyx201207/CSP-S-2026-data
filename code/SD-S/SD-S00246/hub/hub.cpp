#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

inline int read() {
	int k = 0, f = 1;
	char c = getchar();
	while (c < '0' || c > '9') {
		if (c == '-') f = -1;
		c = getchar();
	}
	while (c >= '0' && c <= '9') {
		k = k * 10 + (c - '0');
		c = getchar();
	}
	return k * f;
}


int main() {
	freopen(".in", "r", stdin);
	freopen(".out", "w", stdout);
	
	pust("我好fw，我对不起所有人"); 
	
	return 0;
}
