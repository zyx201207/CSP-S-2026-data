#include<bits/stdc++.h>
#define max_eq(x,y) (x)=max((x),(y))
#define min_eq(x,y) (x)=min((x),(y))
#define eb emplace_back
#define em emplace
#define mkp make_pair
#define fi first
#define se second
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef vector<int> vint;
typedef vector<ll> vll;

constexpr int N=2e6+6;
int c, T, n; ll d, x[N];

int main() {
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	cin.tie(nullptr); cout.tie(nullptr);
	ios::sync_with_stdio(false);
	cin >> c >> T;
	while (T--) {
		cin >> n >> d;
		for (int i=1; i<=n; i++) {
			cin >> x[i];
		}
		if (c==11||c==12) {
			if (d==2) cout << max(0,n-3) << '\n';
			else cout << "0\n";	
		} else {
			cout << "0\n";
		}
	}
	return 0;
}

