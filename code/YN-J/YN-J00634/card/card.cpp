#include <bits/stdc++.h>
using namespace std;
int a[500009];
bool b[500009];
int c[500009];
int ans[500009];
int top;

void push(int x) {
	c[++top] = x;
}

void dele(int x) {
	while (c[top] != x) {
		cout << c[top];
		top--;
	}
}

int main() {
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	int n, m;
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	int d = n, e = 1;
	while (d--) {
		top = 0;
		memset(b, false, sizeof(b));
		memset(c, 0, sizeof(c));
		for (int i = e; i <= n; i++) {
			if (!b[a[i]]) {
				push(a[i]);
				b[a[i]] = true;
			} else {
				dele(a[i]);
			}
		}
		for (int i = 1; i <= top; i++) {
			ans[c[i]]++;
		}
		e++;
	}
	for (int i = 1; i <= m; i++) {
		cout << ans[i] << " ";
	}
	return 0;
}