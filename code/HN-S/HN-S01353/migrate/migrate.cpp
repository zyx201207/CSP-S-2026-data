#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int c, T;
	cin >> c >> T;
	while(T--) {
		int n, d;
		cin >> n >> d;
		ll head = 0, next = 0;
		cin >> head;
		next = head;
		ll leave = 0;int duan = 0, ci = 0;
		for (int i = 1; i <= n; i++) {
			ll x;
			cin >> x;
			leave = x - head;
			if (x - next > d) duan = i;
			next = x;
			if (duan == 0 && leave == x) {
				ci++;
				head = x;
			}else{
				if (duan == 0 && leave > x) {
					head = next;
				}
			}
		}
	}
	return 0;
}
