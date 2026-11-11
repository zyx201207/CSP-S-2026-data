#include <bits\stdc++.h>
using namespace std;
int a[500050], b[300050];
int c[500050];

int main() {
//	freopen("card.in", "r", stdin);
//	freopen("card.out", "w", stdout);
	memset(c, 0, sizeof c);
	memset(b, 0, sizeof b);
	int n, m;
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		b[a[i]] = i;
	}
	for (int i = 1; i <= n; i++) {
		cout << c[b[1]] << " " << c[b[3]] << endl;
		c[i]++;
		cout << c[b[3]] << endl;
		if (b[a[i]] != i)
			c[b[a[i]]]++;
		else
			c[i + 1] += c[i];
	}
	cout << c[b[3]] << endl;
	for (int i = 1; i <= 3; i++) {
		cout << c[b[a[i]]] << " ";
	}
	cout << c[b[3]] << endl;
	return 0;
}