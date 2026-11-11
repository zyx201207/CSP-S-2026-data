#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N = 550005;
const int M = 1505;
const int INF = 1e9;
const int mod = 998244353;
int n, m, a[N];
bool check(int mid){
	int sum = 0;
	for(int i = 1; i <= mid; i++){
		sum += a[i];
	}
	for(int i = mid; i <= n; i++){
		if(mid * a[i] - sum <= m){
			return 1;
		}
		sum += a[i + 1];
		sum -= a[i - mid + 1];
	}
	return 0;
}
void work(){
	cin >> n >> m;
	for(int i = 1; i <= n; i++){
		cin >> a[i];
	}
	sort(a + 1, a + 1 + n);
	int l = 1, r = n;
//	cout << LONG_LONG_MAX;
	while(l <= r){
		int mid = (r - l) / 2 + l;
		if(check(mid)){
			l = mid + 1;
		}else{
			r = mid - 1;
		}
	}
	cout << r;
	return ;
}
signed main(){
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int t = 1;
//	cin >> t;
	while(t--){
		work();
	} 
	return 0;
} 
//luogu uid 910628 Luna_From_Starry 球上神人共赏 
