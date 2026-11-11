#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
#define dbug(x) (void)(cerr<< #x << " = " << x << endl)


constexpr int N = 5e5 + 86;
ll n , m , a[N] , sum[N] , ans;

inline bool check(ll l , ll r){
	ll cost = a[r] * (r - l + 1) - (sum[r] - sum[l - 1]);
	return (cost <= m);
}


int main(){

	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	freopen("crystal.in" , "r" , stdin);
	freopen("crystal.out" , "w" , stdout);

	cin >> n >> m;
	for(ll i = 1;i <= n;i++) cin >> a[i];
	sort(a + 1 , a + n + 1);
	for(ll i = 1;i <= n;i++){
		sum[i] = sum[i - 1] + a[i];
	}
	for(ll i = 1 , l , r , pos, mid;i <= n;i++){
		l = i , r = n , pos = l;
		while(l <= r){
			mid = l + r >> 1;
			if(check(i , mid)){
				pos = mid;
				l = mid + 1;
			}else{
				r = mid - 1;
			}
		}
		ans = max(ans , (pos - i + 1));
	}
	cout << ans;
	return 0;
}
