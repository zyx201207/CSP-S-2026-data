#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll N = 5e5+5;
ll n, m, a[N], s[N];
int f(ll x, ll y){
	return x*a[y]-s[y]+s[y-x];
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	freopen("crystal4.in","r", stdin);
	freopen("crystal.out", "w", stdout);
	cin>>n>>m;
	for(int i = 1;i <= n;i++) cin>>a[i];
	sort(a+1, a+1+n);
	for(int i = 1;i <= n;i++){
		s[i] = s[i-1]+a[i];
	}
	ll ans = 0;
	for(int i = 2;i <= n;i++){
		ll l = 1, r = i, mid;
		while(l>=1&&r<=i&&l<=r){
			mid = (l+r)>>1;
			int get = f(mid, i);
			if(get<=m){
				l = mid+1;
				ans = max(ans, mid); 
			}else{
				r = mid-1;
			}
		}
	}
	cout<<ans;
	//fclose(stdin);
	//fclose(stdout);
	return 0;
} 
