#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<ll, ll> pll;
#define ___prique_mx priority_queue<vector<ll>>
#define ___prique_mn priority_queue<vector<ll, greater<ll>>>
#define endl '\n'

int main() {
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	ll a, b;
	string s, st;
	cin >> a >> s >> b >> st;
	ll c = (s[0] - '0' * 10) + (s[1] - '0');
	ll d = (st[0] - '0' * 10) + (st[1] - '0');
	if(a == b) {
		cout << 1;
	}else {
		cout << "0000";
		return 0;
	}
	if(c == d) {
		cout << 1;
	}else {
		cout << 0;
	}
	char c1 = s[2], c2 = st[2];
	ll f = 0;
	if(c == d && ((c1 != 'F' && c2 != 'D') && (c1 != 'D' && c2 != 'F')) && ((c1 == 'F' && c2 == 'D') || (c1 == 'D' || c2 == 'F') || (c1 != 'D' && c2 != 'F') || (c1 != 'F' && c2 != 'D'))) {
		f = 1; 
		cout << 1;
	}else {
		cout << 0;
	}
	if(f == 1 && ((c1 == 'F' && c2 == 'D') || (c1 == 'D' || c2 == 'F') || (abs((c1 - 'A') - (c2 - 'A')) == 1))) {
		cout << 1;
	}else {
		cout << 0;
	}
	return 0;
}
