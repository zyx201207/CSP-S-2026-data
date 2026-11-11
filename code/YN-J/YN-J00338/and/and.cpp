#include <bits/stdc++.h>
using namespace std;
int n, m;
vector<int> vec;

int andh(int i) {
	int h = vec[i];
	for (int j = i + 1; j < i + m; j++) {
		h = h & vec[j];
	}
	return h;
}

int main() {
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	cin >> n >> m;
	vec.resize(20000);
	for (int i = 0; i < n; i++) {
		cin >> vec[i];
	}
	int maxx = 0;
	for (int i = 0; i < n; i++) {
		maxx = max(maxx, andh(i));
	}
	cout << maxx;
	return 0;
}