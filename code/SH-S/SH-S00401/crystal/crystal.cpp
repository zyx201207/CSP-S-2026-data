#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n , m , ans , cnt , sum , l;
ll a[500009];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> m;
	for(ll i = 1; i <= n; i++){
		cin >> a[i];
	} 
	sort(a+1,a+n+1);
	sum = 1 , l = 1;
	for(ll i = 2; i <= n; i++){
		cnt += (a[i] - a[i-1]) * sum;
		while(cnt > m && l < i){
			cnt -= a[i] - a[l];
			sum--;
			l++;
		}
		sum++;
		ans = max(ans , sum);
	}
	cout << ans << '\n';
	return 0;
}
