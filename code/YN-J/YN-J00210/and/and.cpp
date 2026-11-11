#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 5;
int a[N];
int n, m;
int book[32];

//int book0(int x){
//	int i=1;
//	while(x){
//		book[i]+=!(x%2);
//		boo
//	}
//}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	if (m == 1) {
		int ma = -1;
		for (int i = 1; i <= n; i++) {
			ma = max(a[i], ma);
		}
		cout << ma;
	} else if (m == n) {
		int ans = a[1];
		for (int i = 1; i <= n; i++) {
			ans &= a[i];
		}
		cout << ans;
	} else if (m == 2) {
		int ans = -1;
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				if (i == j)
					continue;
				ans = max(ans, a[i] & a[j]);
			}
		}
		cout << ans;
	}
//	else if(m==n-1){
//		for(int i=1;i<=n;i++){
//
//		}
//	}
//	else{
//
//	}
	return 0;
}