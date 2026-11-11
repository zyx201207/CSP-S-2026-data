#include <bits/stdc++.h>
using namespace std;
double a[500005] = {0};
int    p[500005] = {0};
double minn = 100000086;
double sum_k = 0;
long long maxn = -100000000086;
int olo(double g) {
	if (g < sum_k) {
		return  0 - (g - sum_k);
	} else {
		return g - sum_k;
	}
}
int main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	int flag = 0;
	long long n, m;
	int ovo = 0;
	cin >> n >> m;
	
	
	for (int i = 0;i < n;i++) {
		cin >> a[i];
		if (a[i] > maxn) {
			maxn = a[i];
		}
		sum_k += a[i];
	}
	sum_k /= n;
	minn += sum_k;
	double mp = 0;
	for (int i = 0;i < n;i++) {
		if (olo(a[i]) < olo(minn)) {
			minn = a[i];
			ovo = i;
		}
	}
	flag++;
	int sum = 0;
	if (minn - (int)minn >= 0.5) {
		sum = (int)minn + 1;
	} else {
		sum = (int)minn;
	}
	for (int i = 0;i < n;i++) {
		p[i] = a[i];
	}
	int l = 1;

	long long mi = -1000000000086;
	int fe  = 500004;
	for (int i = 0;i < n;i++) {
		if (p[i] == p[ovo] && i != ovo) {
			flag++;
		}
	}
	while (m--) {
		for (int i = 0;i < n;i++) {
			if (p[i] < p[ovo] && p[i] > mi) {
				mi = p[i];
				fe = i;
			}
		}
		
		if (fe != 500004){
			p[fe]++;
		}
		
		if (p[fe] == p[ovo]) {
			flag++;
			mi = -1000000000086;
			fe = 500004;
		}
	}
	if (flag > n) {
		cout << maxn << endl;
		return 0;
	}
	cout << flag;
	return 0;
} 
