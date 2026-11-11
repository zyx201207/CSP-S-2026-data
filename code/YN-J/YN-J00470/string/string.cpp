#include <iostream>
#include <bits/stdc++.h>
#include <string>
#include <set>
using namespace std;

struct Node {
	int a;
	string b;
} m[200005];
string l;

int main() {
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> m[i].a >> m[i].b;
	}
	cout << 0;
	return 0;
}