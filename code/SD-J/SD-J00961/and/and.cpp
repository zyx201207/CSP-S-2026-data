#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 2e5 + 5;
int n, m, ans = (1LL << 31) - 1, nn;
int a[N];
int book[35];
bool useing[N];
struct node {
	bool flag[35];
	vector<int> w;
}tr[N];
void back(int x) {
	for(int i = 1; i <= n; ++i) {
		if(!tr[i].flag[x] && !useing[i]) { 
			for(auto v : tr[i].w) {
				book[v]--;
			}
			nn--;
			useing[i] = 1;
		}
	}
}
int main() {
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	cin >> n >> m;
	nn = n;
	for(int i = 1; i <= n; ++i) {
		cin >> a[i];
		int x = a[i], cnt = 0;
		while(x) {
			if(x & 1) {
				book[cnt]++;
				tr[i].flag[cnt] = 1;
				tr[i].w.push_back(cnt);
			}
			x >>= 1;
			cnt++;
		}
	}
//	for(int i = 0; i <= 30; ++i) {
//		cout << book[i] << " ";
//	}
	for(int i = 30; i >= 0; i--) {
		if(book[i] >= m) {
			for(int j = i; j >= 0; --j) {
				if(book[j] >= m) {
					back(j);
				}
			}
			for(int i = 1; i <= n; ++i) {
				if(!useing[i]) {
					ans &= a[i];
//					cout << i;
				}
			}
			break;
		}
	}
	if(ans == ((1LL << 31) - 1)) {
		cout << 0;
	}
	else cout << ans; 
	return 0;
} 
