#include<bits/stdc++.h>
#define pii pair<int, int>
#define int long long
#define ios ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;

const int N = 1e6 + 5;

int c, t;

void A(int t){
	while(t --){
		int n, k;cin >> n >> k;
		for(int i = 1;i <= n - 1;i ++){
			int u, v;cin >> u >> v;
		}
		if(n <= k + 4){
			cout << 1 << "\n";
		}else{
			cout << n - k - 3 << "\n";
		}
	}
}

signed main(){
	ios;
	freopen("hub.in", "r", stdin);
	freopen("hub.out", "w", stdout);
	cin >> c >> t;
	if(c == 13 || c == 14) A(t);
	return 0;
}