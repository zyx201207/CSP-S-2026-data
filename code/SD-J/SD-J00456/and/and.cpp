#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 2e6+10;
ll a[N] , f[N];
ll maxm = -1 , n , m;

void dfs(ll num , ll cnt){
	if (cnt == m) {
		ll sm = f[0];
		for (ll i = 1 ; i < m ; i++){
			sm = sm & f[i];
		}
		maxm = max(maxm , sm);
		return;
	}
	if (num <= n-m) dfs(num+1 , cnt);
	f[cnt] = a[num];
	dfs(num+1,cnt+1);
}

int main(){
	freopen("and.in", "r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> m;
	for (ll i =0;i < n ; i++){
		cin >> a[i];
	}
	dfs(0,0);
	cout << maxm;
	return 0;
}
