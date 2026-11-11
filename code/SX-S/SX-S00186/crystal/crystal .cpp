#include <bits/stdc++.h>
using namespace std;

struct jntm {
	long s;
	long sum = 0;

};

bool cmp(jntm x, jntm y) {
	if (x.s > y.s) {
		return 0;
	}

	else
		return 1;

};

int main() {
	freopen("crystal .in", "r", stdin);
	freopen("crystal .out", "w", stdout);
	long long n;
	long long m;
	cin >> n >> m;
	jntm a[n + 3];


	for ( long long i = 1; i <= n; i++) {
		cin >> a[i].s;

	}
	sort(a + 1, a + n + 1, cmp);
//	cout << a[1].s << 'x';
	for (long long i = 1; i <= n; i++) {
//		if (n <= 10000){
		if (i > 1)
			a[i].sum = (a[i].s - a[i - 1].s) * (i - 1) + a[i - 1].sum;
		else
			a[1].sum = 0;
		if (a[i].sum > m) {
			cout << i - 1;
			return 0;
		}
		if (a[i].sum == m) {
			cout << i;
			return 0;
		}
	}
//		else{
//			cout<<m*2/((a[2].s-a[1].s)*())
//		}




	cout << n;
	return 0;
}
