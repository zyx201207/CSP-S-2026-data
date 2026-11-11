#include<bits/stdc++.h>//8:30~9:15 T1
using namespace std;
#define int long long
const int N = 2 * 1e5 + 5;
int n, m, maxx, sf;
int a[N];
void solve(){
	int ans = -1;
	for(int i = 1; i <= n; i++){
		for(int j = i + 1; j <= n; j++){
			ans = max(ans, (a[i] & a[j]));
		}
	}
	cout << ans;
	return ;
}
void to2(){
	int ans = 0;
	for(int i = 1; i <= n; i++){
		ans = (ans & a[i]);	
		cout << 1;
	}
	cout << ans;
	return ;
}
signed main(){
	freopen("and.in", "r", stdin);
	freopen("and.out", "w",stdout);
	sf = 1;
	cin >> n >> m;
	for(int i = 1; i <= n; i++){
		cin >> a[i];
		maxx = max(a[i], maxx);
	}
	if(m == 1)cout << maxx;
	else if(m == 2)solve();
	else if(m == n)to2();
	else cout << n - 1;
	return 0;
}
