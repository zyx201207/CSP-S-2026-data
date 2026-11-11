#include <bits/stdc++.h>
#define int long long int
#define st string
#define re return
using namespace std;
const int one = 500007;
const int two = 10001;
int n, m, a[one], cnt[one];
signed main(){
	freopen ("card.in", "r", stdin);
	freopen ("card.out", "w", stdout);
	
	cin >> n >> m;
	for (int i = 0; i < n; i++) scanf ("%lld", &a[i]);
	for (int i = 0; i < n; i++) {
		stack <int> des{};
		bool xnt[one]{};
		//cout << "times:" << i + 1 << endl;
		for (int j = i; j < n; j++) {
			//cout << "a[j]:" << a[j] << endl;
			if (!xnt[a[j]]) {
				des.push(a[j]);
				xnt[a[j]] = true;
			}
			else {
				int x{};
				while (x != a[j]) {
					x = des.top();
					des.pop();
					xnt[x] = false;
				}
				des.push(a[j]);
				xnt[a[j]] = true;
			}
		}
		int x{};
		while (!des.empty()) {
			x = des.top();
			des.pop();
			cnt[x]++;
			//cout << x << " ";
		}
		//cout << endl;
	}
	for (int i = 1; i <= m; i++) cout << cnt[i] << " ";
	cout << endl;
	
	fclose (stdin);
	fclose (stdout);

	re 0;
}
