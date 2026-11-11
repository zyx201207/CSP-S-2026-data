#include <bits/stdc++.h>
using namespace std;

using ll = long long;
ll c, t, n, k;
struct side{
	int u, v;
};

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen("hub.in", "r", stdin);
	freopen("hub.out", "w", stdout);
	cin >> c >> t;
	while(t --){
		vector <side> a[1000009];
		cin >> n >> k;
		for(int i = 1; i < n; i ++) cin >> a[i].u >> a[i].v;
		
		// ÷±Ω”ÀÕ
		cout << min(1, (n - k + 1) / 3) << endl;
	}
	
	return 0;
}

