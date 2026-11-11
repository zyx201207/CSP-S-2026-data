#include <bits/stdc++.h>
using namespace std;

struct node {
	int num = 0;
	char zf;
} a[200005];

int main() {
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	int n;
	cin >> n;
	long long sum = 0;
	cin >> a[1].num >> a[1].zf;
	int ans = 1;
	for (int i = 2; i <= n; i++) {
		int x;
		char y;
		cin >> x >> y;
		if (y == a[ans].zf)
			a[ans].num += x;
		else {
			ans++;
			a[ans].num = x;
			a[ans].zf = y;
		}
	}
	int bj = 0;
	int bjs = 0;
	int js = 1;
	for (int i = 1; i <= n; i++) {
		if (a[i].zf == a[n].zf) {
			bj = max(a[i].num, a[n].num);
			bjs = min(a[i].num, a[n].num);
			sum += (bj - bjs);
		} else {
			bj = max(a[i].num, a[n].num);
			sum += bj;
			bjs = bj - min(a[i].num, a[n].num);
			if (a[i].num > a[n].num)
				n--;
			else
				i++;
		}
		int sb = (bj - bjs);
		if (sb == 0)
			n--;
		if (sb != 0) {
			if (a[i].num > a[n].num) {
				while (sb > 0) {
					if (sb >= a[n - js].num) {
						sb -= a[n - js].num;
						a[n - js].num = 0;
						n--;
					} else {
						a[n - js].num -= sb;
						sb = 0;
					}
				}
			} else {
				while (sb > 0) {
					if (sb >= a[i + js].num) {
						sb -= a[i + js].num;
						a[i + js].num = 0;
						i++;
					} else {
						a[i + js].num -= sb;
						sb = 0;
					}
				}
			}
		}
	}
	cout << sum;
	return 0;
}