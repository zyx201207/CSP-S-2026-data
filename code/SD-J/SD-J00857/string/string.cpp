#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	
	int n, num = 0;
	cin >> n;
	int a[n];
	char c[n];
	cin >> a[0] >> c[0];
	for (int i = 1; i < n; i++) {
		cin >> a[i] >> c[i];
		a[i] += a[i - 1];
	}
	int head = 1;
	int head_i = 0, tail_i = n - 1;
	while (head <= a[n - 1] - head + 1) {
		if (c[head_i] != c[tail_i]) num++;
		head++;
		if (head > a[head_i]) head_i++;
		if (a[n - 1] - head + 1 <= a[tail_i - 1]) tail_i--;
	}
	cout << num << endl;
	return 0;
}
