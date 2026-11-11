#include<bits/stdc++.h>
using namespace std;
const int N = 2e5 + 5;
int a[N];
int main() {
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n,m;
	cin >> n >> m;
	for(int i = 1; i <= n; i ++) cin >> a[i];
	int mx = -1e9;
	for(int i = 1; i <= n - m + 1; i ++) {
		int sum = a[i];
		for(int j = i + 1; j <= i + m; j ++) {
			sum = sum & a[j];
		}
		mx = max(mx,sum);
	}
	cout << mx;
	return 0;
}
