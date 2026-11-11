#include <bits/stdc++.h>
using namespace std;

int n, m;
int a[200001];

int abc(int num, int i, int and_max){
	if (i == n - 1) {
		if (num == m) return and_max;
		return (and_max & a[i]);
	}
	if (num == m) return abc(num, i + 1, and_max);
	if (n - i == m - num) {
		if (num == 0) return abc(num + 1, i + 1, a[i]);
		return abc(num + 1, i + 1, and_max & a[i]);
	}
	if (num == 0) return max(abc(num + 1, i + 1, a[i]), abc(num, i + 1, 0));
	return max(abc(num + 1, i + 1, and_max & a[i]), abc(num, i + 1, and_max));
}

int main(){
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);

	cin >> n >> m;
	for (int i = 0; i < n; i++) cin >> a[i];
	cout << abc(0, 0, 0); 
	return 0;
}
