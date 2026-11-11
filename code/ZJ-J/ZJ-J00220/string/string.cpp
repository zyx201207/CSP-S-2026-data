#include<bits/stdc++.h>
using namespace std;
const int N = 2e5 + 10;
struct Node {
	int x;
	char c;
};
Node a[N];
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	int n;
	cin >> n;
	for(int i = 1; i <= n; i++) {
		cin >> a[i].x >> a[i].c;
	}
	int l = 1, r = n;
	long long ans = 0;
	while(l <= r) {	
		if(a[l].c != a[r].c) {
			if(a[l].x < a[r].x) {
				a[r].x -= a[l].x;
				ans += a[l].x;
				l++;
			}
			else if(a[l].x == a[r].x) ans += a[l].x, l++, r--;
			else if(a[l].x > a[r].x) {
				a[l].x -= a[r].x;
				ans += a[r].x;
				a[r].x = 0;
				r--;
			}
		}
		else {
			if(a[l].x == a[r].x) a[l].x = a[r].x = 0, l++, r--;
			else if(a[l].x < a[r].x) a[r].x -= a[l].x, l++;
			else a[l].x -= a[r].x, r--;
		}    
	}
	cout << ans << endl;
	return 0;
}
