#include <bits/stdc++.h>
using namespace std;

long long read() {
	long long num = 0;
	char ch;
	int k = 1;
	ch = getchar();
	if (isdigit(ch)) {
		num = ch - '0';
	} else {
		k = -1;
	}
	ch = getchar();
	while (isdigit(ch)) {
		num = num * 10 + ch - '0';
		ch = getchar();
	}
	return num * k;
}

int main() {
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	
	return 0;
}