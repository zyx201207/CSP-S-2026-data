#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 2e5 + 5;
int n, m;
ll a[N];
int bj[N];
int main(){
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout); 
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> m;
	for(int i = 1;i <= n;i++){
		cin >> a[i];
		bj[i] = 31;
	}
	ll ans = 0;
	int qis = 31;
	for(int i = 30;i >= 0;i--){
		int tj = 0;
		ll x = (1 << i);
		for(int j = 1;j <= n;j++){
			if(bj[j] <= qis){
				if((a[j] & x) != 0){
					tj ++;
					bj[j] = i;
				}
			}
		}
		if(tj >= m){
			ans ^= x;
			qis = i;
		}
	}
	cout << ans;
	return 0;
}

