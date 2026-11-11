#include<bits/stdc++.h>
using namespace std;

const int maxn = 200005;

struct node {
	int num;
	char c;
}a[maxn];

int n;
long long ans;

int main() {
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	cin >> n;	
	for (int i = 1; i <= n; i++) {
		cin >> a[i].num >> a[i].c;
	}
	int left = 1, right = n;
	while (left < right) {
		int t = min(a[left].num, a[right].num);
		if (a[left].c != a[right].c) {
			ans += t;
		}
		a[left].num = a[left].num - t, a[right].num = a[right].num - t;
		if (a[left].num == 0) {
			left++;
		}
		if (a[right].num == 0) {
			right--;
		}
	}
	cout << ans << endl;
	return 0;
}