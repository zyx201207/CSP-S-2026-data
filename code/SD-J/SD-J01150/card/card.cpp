#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
inline void fast_io() {
	ios::sync_with_stdio(0);
	cin.tie(0);
} 
const ll N = 2e5 + 10;
ll n, m;
ll sn[N];
bool f[N];
vector<ll> ans(N);
vector<ll> a;
stack<ll> s;
int main() {
	fast_io();
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	cin >> n >> m;
	for(ll i = 1; i <= n; ++i) {
		cin >> sn[i];
	}
	for(ll op = 1; op <= n; ++op) {
		for(ll i = n; i >= op; --i) {
			s.push(sn[i]);
		}
		a.clear();
		memset(f, 0, sizeof(f));
		while(!s.empty()) {
			ll k = s.top();
			s.pop();
			ll pos = -1;
			//找第一个为打出牌的数 
			for(ll j = 0; j < a.size(); ++j) {
				if(a[j] == k) {
					pos = j;
					break;
				}
			}
			//没找到直接加 
			if(pos == -1) {
				a.push_back(k);
			}
			//找到就先清除再加 
			else {
				for(ll j = pos; j <= a.size() + 1; ++j) {
					a.pop_back();
				}
				a.push_back(k);
			}
			//验证 
//			cout << op << " : ";
//			for(ll i = 0; i < a.size(); ++i) {
//				cout << a[i] << ' ';
//			}
//			cout << endl;
		}
		//统计数 
		for(ll i = 0; i < a.size(); ++i) {
			if(f[i] == 0) {
				++ans[a[i]];
				f[i] = 1;
			}
		}
	}
	for(ll i = 1; i <= m; ++i) {
		cout << ans[i] << ' ';
	}
	return 0;
}

