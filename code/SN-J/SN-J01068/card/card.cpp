// orz
// 没时间了 写不完了
#include <bits/stdc++.h>
#define ll long long
using namespace std;

ll n, m, tc=0;
vector<ll> a[300005];
ll ed[300005];
ll ans[300005];

int main(){
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	// input
	cin >> n >> m;
	for(int i=1; i<=n; i++){
		ll tmp;
		cin >> tmp;
		a[tmp].push_back(i);
	}
	
	// solve
	for(int i=1; i<=m; i++){
		ed[i] = a[i][(int)a.size() - 1];
	}
	
	// temp -> print
	for(int i=1; i<=m; i++){
		if(i == 0){
			cout << 0 << ' ';
			tc--;
			continue;
		}
		if((ll)a[i].size() > 1){
			tc += ll(a[i].size()) - 1;
		}
		cout << i + tc << ' ';
	}
	cout << '\n';
	
	// emd
	return 0;
}
