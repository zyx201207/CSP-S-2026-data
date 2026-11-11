//王子腾  SN-J00702  西安铁一中学 
#include <bits/stdc++.h>
#define ll long long
#define inf 0x3f3f3f3f3f3f3f3fLL
using namespace std;

const ll maxn = 5e5 + 5;
ll n , m;
ll a[maxn];
bool mark[maxn];
ll js[maxn];
deque <ll> dq;

int main () {
//	cout << "debug" << "\n";
	freopen("card.in" , "r" , stdin);
	freopen("card.out" , "w" , stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
//	cout << "debug" << "\n";
	cin >> n >> m;
	for (ll i = 1; i <= n; i++) {
		cin >> a[i];
	}
//	cout << "debug" << "\n";
	memset(mark , 0 , sizeof(mark));
	ll cnt = 0;
//	cout << "debug" << "\n";
	for (ll i = 1; i <= n; i++) {
		for (ll j = i; j <= n; j++) {
			if (!mark[a[j]]) {
//				cout << "debug" << "\n";
				dq.push_back(a[j]);
				cnt++;
				mark[a[j]] = true;
				cout << "deque: ";
				for (ll i = 0; i < cnt; i++) {
					cout << dq[i] << " ";
				}
				cout << "\n";
			} else {
//				cout << "debug" << "\n";
				while (dq[cnt - 1] != a[j]) {
					mark[a[cnt]] = false;
					dq.pop_back();
					cnt--;
				}
				dq.push_back(a[j]);
				cout << "deque: ";
				for (ll i = 0; i < cnt; i++) {
					cout << dq[i] << " ";
				}
				cout << "\n";
			}
		}
//		cout << "js: ";
		for (ll j = 0; j < cnt; j++) {
			js[dq[j]]++;
//			cout << js[dq[j]] << " ";
		}
//		cout << "\n";
	}
	for (ll i = 1; i <= m; i++) {
		cout << js[dq[i]] << " ";
	}
	cout << "\n";
	return 0;
}
