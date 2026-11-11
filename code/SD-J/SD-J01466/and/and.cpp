#include<bits/stdc++.h>
#define endl '\n'
#define udmap unordered_map
#define udset unordered_set
using namespace std;
typedef long long LL;
typedef unsigned long long uLL;

const int N = 2e5 + 10;
const int INF = 0x3f3f3f3f;
int n, m, ans = -1;
int a[N], mx = -1;
vector<int> b(25, 2); 

int ans2 = 0;
int vis[N];
void dfs(int x, int s) {
	if(x > m) {
		if(ans < s) {
			ans = s;
		}
	} else {
		for(int i = 1; i <= n; i++) {
			if(!vis[i]) {
				vis[i] = true;
				dfs(x + 1, s & a[i]);
				vis[i] = false;
			}
		} 
	}
}
bool find(int x) {
	for(int i = 1; i <= 20; i++) {
		if(x == b[i]) return true;
	}
	return false;
}

int main() {
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> n >> m;
	bool is = true, is2 = true;
	for(int i = 2; i <= 20; i++) {
		b[i] = b[i - 1] * 2;
	}
	for(int i = 1; i <= 20; i++) {
		b[i]--;
	}
	for(int i = 1; i <= n; i++) {
		cin >> a[i];
		mx = max(mx, a[i]);
		if(!find(a[i])) is = false; 
		if(a[i] >= 4) is2 = false;
	}
	
	if(n <= 20 || m == 2) {
		dfs(1, INT_MAX);
		cout << ans << '\n';
	} else if(m == 1) {
//		cout << "m == 1\n";
		cout << mx;
	} else if(m == n) {
//		cout << "m == n\n";
		int ans = a[1];
		for(int i = 1; i <= n; i++) {
			ans &= a[i];
		}
		cout << ans;
	} else if(is) {
//		cout << "A\n";
		sort(a + 1, a + n + 1);
		cout << a[n - m + 1];
	} else if(is2) {
//		cout << "a[i] < 4\n";
		vector<int> cnt(5, 0);
		for(int i = 1; i <= n; i++) {
			cnt[a[i]]++;
		}
		if(m <= cnt[3]) {
			cout << 3;
		} else if(m <= cnt[3] + cnt[2]) {
			cout << 2;
		} else if(m <= cnt[3] + cnt[1]) {
			cout << 1;
		} else {
			cout << 0;
		}
	}
	return 0;
}

