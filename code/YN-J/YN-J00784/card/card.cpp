#include <bits/stdc++.h>
using namespace std;

int ml(int m, int n) {
	return ml(m + 1, n - 1);
	//return ml(m-1,m+1);
}

struct node {
	char a[106];
};

bool cmp(int a, int b) {
	return a > b;
}

char mc(int x) {
	char c[106];
	int i = 1;
	while (x) {
		c[i] = x % 2;
		x = x / 2;
		i++;
	}
	return c[i];
}

int main() {
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	node k[106];
	int n, m, a[205], b[26];
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	sort(a + 1, a + n + 1);
	for (int i = 1; i <= m; i++) {
		k[i].a[i] = mc(a[i]);
	}
	//cout<<" ";
	cout << a[1];
	cout << a[2];
	return 0;
}