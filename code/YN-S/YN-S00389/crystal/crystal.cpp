#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1e5 + 5, M = 1e8 + 5;
int a[N], b[M], num[N];
int ans;

signed main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	int n, m;
	cin >> n >> m;
	int minn = INT_MAX, sum = 0;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		//cout<<endl<<endl<<endl;
		//cout<<a[i];
		//cout<<endl<<endl<<endl;
	}
	sort(a, a + n + 1);
	for (int i = 1; i <= n; i++) {
		b[i] = a[i] - a[i - 1];
		//cout<<endl<<endl<<endl;
		//cout<<b[i];
		//cout<<endl<<endl<<endl;
	}
	sort(b, b + n + 1);
	for (int i = 1; i <= n; i++) {
		num[i] = num[i - 1] + b[i];
		//cout<<endl<<endl<<endl;
		//cout<<num[i];
		//cout<<endl<<endl<<endl;
	}
	int num1 = 1, num2 = 1, num3 = 0;
	while (num1 <= num2 && num2 <= n) {
		if (num3 <= m) {
			ans = min(num2 - num1 + 1, ans);
			num3 += b[num2 + 1] * (num2 - 1 + num1);
			//cout<<endl<<endl<<endl;
			//cout<<num3;
			//cout<<endl<<endl<<endl;
			num2++;
		} else {
			num3 -= num[num2] - num[num1 - 1];
			//cout<<endl<<endl<<endl;
			//cout<<num3;
			//cout<<endl<<endl<<endl;
			num1++;
		}
	}
	cout << ans;
	return 0;
}