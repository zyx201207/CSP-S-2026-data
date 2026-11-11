#include <bits/stdc++.h>
using namespace std;
struct note {
	int num;
	char s;
};
note con[200015];
long long int sum[200015];
int main () {
	freopen("string.in" , "r" , stdin);
	freopen("string.out" , "w" , stdout);
	int n;
	cin >> n;
	string s = "";
	for (int i = 1; i <= n; i++) {
		cin >> con[i].num >> con[i].s;
		sum[i] = 1LL * (sum[i - 1] + con[i].num);
	}
	long long int mid = sum[n] / 2 + 1;
	int l = 1, r = n;
	long long int havel;
	long long int haver;
	if (sum[n] % 2 == 0) {
		mid = sum[n] / 2;
		while (l < r) {
			int md = (l + r) / 2;
			if (sum[md] >= mid) r = md;
			else l = md + 1;
		}
		l = r;
		r = r + 1;
		havel = mid - sum[l - 1];
		haver = sum[r] - mid;
	}
	else {
		mid = sum[n] / 2 + 1;
		while (l < r) {
			int md = (l + r) / 2;
			if (sum[md] >= mid) r = md;
			else l = md + 1;
		}
		r = r;
		l = r;
		havel = mid - sum[l - 1] - 1;
		haver = sum[r] - mid;
	}
	long long int ans = 0;
	while (l > 0 && r <= n) {
			if (havel == 0) {
				havel = sum[l] - sum[l - 1];
				l--;
			}
			if (haver == 0) {
				haver = sum[r] - sum[r - 1];
				r++;
			}
			if (con[l].s == con[r].s) {
				if (sum[l] < sum[r]) {
					sum[r] -= sum[l];
					l--;
				}
				else if (sum[l] > sum[r]) {
					sum[l] -= sum[r];
					r++;
				}
			}
			else {
				if (havel > haver) {
					sum[l] -= haver;
					ans += haver;
					r++;
				}
				else if (havel < haver){
					sum[r] -= havel;
					ans += havel;	
					l--;
				}
				else {
					ans += havel;
					l--;
					r++;
				}
			}
			havel = sum[l] - sum[l - 1];
			haver = sum[r] - sum[r - 1];
		}
		cout << ans << "\n";
	return 0;
}