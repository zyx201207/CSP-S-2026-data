#include <bits/stdc++.h>
#define ll long long
#define pll pair<long long,long long>
using namespace std;
const int N = 5e5+5;
ll a[N],n,m,ans = -2e9;
void C(){
	for(ll i = 1;i<=n;i++){
		ll cnt = 0,flag = 1;
		for(ll j = 1;j<=i;j++){
			cnt += a[i]-a[j];
			if(cnt > m){
				flag = 0;
				break;
			}
		}
		if(!flag){
			break;
		}
		ans = i;
	}cout << ans;
	return;
}
ll solve(ll x,ll y,ll z){
	return (x+y)*z/2;
}
void B(){
	ll p = a[2]-a[1];
	ll res = -2e9;
	for(ll i = 1;i<=n;i++){
		if(solve(p,(i-1)*p,i-1) <= m) res = i;
		else break;
	}cout << res << endl;
	return;
}

int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin >> n >> m;
	for(ll i = 1;i<=n;i++){
		cin >> a[i];
	}
	if(n <= 5000){
		C();
	}else{
		B();
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
