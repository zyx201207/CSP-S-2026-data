#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
const int N = 5e5 + 100;
#define ll long long
inline ll read(){
	ll x = 0 , f = 1;
	char ch = getchar();
	while(!isdigit(ch)){
		if(ch == '-')f = -1;
		ch = getchar();
	}
	while(isdigit(ch)){
		x = (x << 1) + (x << 3) + ch - '0';
		ch = getchar();
	}
	return x * f;
}
ll n,m,a[N],s[N];
bool check(ll x,ll t){
	ll sum = (t - x) * a[t];
	ll tot = s[t - 1] - s[x - 1];
	return (sum - m <= tot);
} 
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	n = read() , m = read();
	for(ll i = 1; i <= n; i ++)
		a[i] = read();
	sort(a + 1 , a + n + 1);
	s[0] = 0;
	for(ll i = 1 ; i <= n; i ++){
		s[i] = s[i - 1] + a[i]; 
	} 
	ll ans = 1;
	for(ll i = n; i >= 1; i --){
		ll l = 1 , r = i, res = 0;
		while(l <= r){
			ll mid = l + ((r - l) >> 1);
			if(check(mid,i)){
				res = mid;
				r = mid - 1;
			}
			else l = mid + 1;
		}
		if(i - res + 1 > ans){
			ans = i - res + 1; 
		}
	}
	cout << ans << "\n";
	return 0;
} 
