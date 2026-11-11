#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 5e5 + 100;
int a[N], ans2, ans;
ll n, m, qz[N];
int main(){
	ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	cin >> n >> m;
	int tmp = 0;
	for(int i = 1; i <= n; i++) cin >> a[i];
	sort(a + 1, a + n + 1);
	for(ll i = 1; i < n; i++){
		if(a[i] == a[i + 1]){
			tmp++;
		}else{
			ans2 = max(ans2, tmp + 1);
			tmp = 0;
		}
	}
	ans2 = max(ans2, tmp + 1);
	for(int i = 1; i <= n; i++){
		ll val = (i - 1) * (a[i] - a[i - 1]);
		qz[i] = qz[i - 1];
		qz[i] += val;
	}
	for(int i = 1; i <= n; i++){
		if(qz[i] <= m) ans++;
		else break;
	}
	cout << max(ans, ans2);
    return 0;
}
