#include<bits/stdc++.h>
using namespace std;
//不开long long见祖宗 
#define int long long
const int N = 200010;
int n, m, ans;
bool vis[110];
vector<int> a, b;
signed main() {
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	
	ios::sync_with_stdio(0);
	cin.tie(nullptr), cout.tie(nullptr);
	
	cin >> n >> m;
	a.resize(n + 100);
	for(int i = 0; i < n; i++) {
		cin >> a[i];
	}
	sort(a.begin(), a.end(), greater<int>());
	for(int i = 29; i >= 0; i--) {
		b.clear();
		for(int j = 0; j < a.size(); j++) {
			int num = a[j];
			if(num & (1 << i)) {
				b.push_back(num);
			}
		}
		if(b.size() >= m) {
			vis[i] = true;
			a.clear();
			for(int j = 0; j < b.size(); j++) {
				a.push_back(b[j]);
			}
		}
	}
	for(int i = 29; i >= 0; i--) {
		if(vis[i]) {
			ans += (1 << i);
		}
	}
	cout << ans;
	return 0;
}
//cyx你还记得我吗 
//求球让我过吧 
