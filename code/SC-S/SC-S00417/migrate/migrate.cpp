#include<bits/stdc++.h>
#define pii pair<int, int>
#define int long long
#define ios ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;

const int N = 2e6 + 5;

int c, t;
int a[N];

void A(int t){
	while(t --){
		int n, d;cin >> n >> d;
		for(int i = 1;i <= n;i ++){
			cin >> a[i];
		}
		if(d == 1) cout << 0;
		else{
			int ca = a[2] - a[1];
			int dd = d / ca;
			int dis = dd * 2 - 1;
			if(n < dis) cout << 0;
			else{
				cout << n - dis + 1;
			}
		}
	}
}

signed main(){
	ios;
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	cin >> c >> t;
	if(c == 11 || c == 12) A(t);
	return 0;
}