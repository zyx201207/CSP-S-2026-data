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

int c, T, n, k;

int main() {
	freopen("hub.in", "r", stdin);
	freopen("hub.out", "w", stdout);
	cin.tie(nullptr); cout.tie(nullptr);
	ios::sync_with_stdio(false);
	cin >> c >> T;
	while (T--) {
		cin >> n >> k;
		for (int i=1,u,v; i<n; i++) cin >> u >> v;
		cout << n%k+((n+1)%k!=0) << '\n';
	}
	return 0;
}

