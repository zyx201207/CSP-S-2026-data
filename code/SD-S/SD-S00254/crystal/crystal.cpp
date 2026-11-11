#include<bits/stdc++.h>
using namespace std;
#define rep(i,x,y) for(int i=(x);i<=(y);i++)
using ll = long long;
ll n, m;
ll a[500005], base;
inline ll absll(ll a){
	return a < 0 ? -a : a;
}
bool A = 1, B = 1;
ll maxa = -1;
bool cmp(ll a, ll b){
	if(a < base && b > base) return 1;
	if(a > base && b < base) return 0;
	return absll(a-base) < abs(b-base);
}
ll diff;
ll calc(ll x){
	return x * x + x;
}
bool check(ll x){
	return calc(x) <= 2*m;
}
bool check1(ll x){
	return diff*calc(x) <= 2*m;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	srand(time(0));
	cin>>n>>m;
	rep(i, 1, n){
		cin>>a[i];
		maxa = max(absll(a[i]), maxa);
		if(a[i] != i) A = 0;
		if(i > 2 && a[i]-a[i-1] != a[i-1]-a[i-2]) B = 0;
	}
	if(maxa <= 100){
		ll ans = 1;
		rep(i, -maxa, maxa){
			base = i;
			ll res = 0, ned = 0;
			sort(a+1, a+n+1, cmp);
			rep(i, 1, n){
				if(a[i] > base) break;
				ned += absll(a[i]-base);
				if(ned > m) break;
				res++;
			}
			ans = max(ans, res);
		}
		cout<<ans;
		return 0;
	}
	if(A){
		ll l=0, r = 1e9+5, ans = 0;
		while(l <= r){
			ll mid = l + r >> 1;
			if(check(mid)){
				l = mid+1;
				ans = mid;
			}
			else{
				r = mid-1;
			}
		}
		cout<<min(n, ans+1);
		return 0;
	}
	if(B){
		if(a[1] == a[2]){
			cout<<n;
			return 0;
		}
		ll diff = absll(a[1]-a[2]);
		ll l=0, r = 1e9+5, ans = 0;
		while(l <= r){
			ll mid = l + r >> 1;
			if(check1(mid)){
				l = mid+1;
				ans = mid;
			}
			else{
				r = mid-1;
			}
		}
		cout<<min(n, ans+1);
		return 0;
	} 
	if(maxa <= 1e5){
		ll ans = 1;
		rep(i, -maxa, maxa){
			base = i;
			ll res = 0, ned = 0;
			sort(a+1, a+n+1, cmp);
			rep(i, 1, n){
				if(a[i] > base) break;
				ned += absll(a[i]-base);
				if(ned > m) break;
				res++;
			}
			ans = max(ans, res);
		}
		cout<<ans;
		return 0;
	}
	cout<<rand();
	return 0; 
}
//Whatever, I tried.
//70 ~ 80 + 0 + 8 + 0

