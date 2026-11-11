#include <bits/stdc++.h>
#include <cstdio>
using namespace std;
int a[100001];

int main() {
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	int n;
	cin >> n;
	int v = n;
	int m = n - 1;
	for (int i = 1; i <= v; i++) {
		cin >> a[i];
	}
	int cnt = 0;
	for (int i = 1; i <= v; i++) {
		if (a[v] == a[m]) {
			a[v]++;
		} else {
			a[m]++;
		}
	}
	for (int j = 1; j <= 3; j++) {
		if (a[v] > a[m]) {
			break;
		} else {
			cout << "0";
		}
	}
	cout << "2";
	return 0;
}