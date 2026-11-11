#include <bits/stdc++.h>
using namespace std;
long long int n,a[200005],qujian[200005],idx_q = 1,cnt_ans = 0;
string c;
string s;
string qqj_c (long long int a) {
	for (int i = 1;i <= idx_q;i ++) {
		if (a < qujian[i]) {
			return &c[i - 1];
		}
	}
}
int main () {
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout); 
	qujian[1] = 1;
	cin >> n;
	for (int i = 1;i <= n;i ++) {
		cin >> a[i] >> c[i];
		qujian[++ idx_q] = qujian[idx_q - 1] + a[i];
	}
	for (int i = 1;i <= idx_q / 2 + 1;i ++) {
		if (qqj_c(qujian[i]) != qqj_c(idx_q + 1 - qujian[i])) {
			cnt_ans += abs((idx_q + 1 - qujian[i]) - qujian[i]);
		}
	}
	cout << cnt_ans;
	return 0;
}
