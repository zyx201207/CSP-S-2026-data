#include <bits/stdc++.h>
using namespace std;
long long num[200100], qian[200100];
char cnt[200100];

int main() {
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >>  num[i] >> cnt[i] ;
		qian[i] = num[i] + qian[i - 1];
	}
	int l = qian[n] / 2, r = qian[n] / 2 + 1, sum = 0;
	while (l > 0 && r <= qian[n]) {
		int idx1, idx2;
		for (int i = 1; i <= n; i++) {
			if (qian[i] >= l) {
				idx1 = i;
				break;
			}
		}
		for (int i = 1; i <= n; i++) {
			if (qian[i] >= r) {
				idx2 = i;
				break;
			}
		}
		if (cnt[idx1] != cnt[idx2]) {
			sum++;
		}
		r++;
		l--;
	}
	cout << sum;
	return 0;
}
