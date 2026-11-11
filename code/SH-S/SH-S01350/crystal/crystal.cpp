#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll a[500005];
int n;
ll m,dlt;
bool check(int num){
	for (int bg = 1;bg+num-1 <= n;bg++){
		ll g = a[bg+num-1];
		ll used = 0;
		for (int i = bg;i < bg+num-1;i++){
			used += g-a[i];
			if (used > m)break;
		}
		if (used <= m)return true;
	}
	return false;
} 
void fff(){
	sort(a+1,a+n+1);
	int l = 1,r = n;
	while (l < r){
		int mid = (l+r+1)/2;
		if (check(mid)){
			l = mid;
		}else{
			r = mid-1;
		}
	}
	cout << l;
}
void f(){
	ll ans = -1;
	for (ll i=1;i<=n;i++){
		if (i*(i+1)/2 <= m)ans = i+1;
	}
	cout << ans;
}
void ff(){
	ll ans = -1;
	for (ll i=1;i<=n;i++){
		if ((0+(i-1)*dlt)*i/2 <= m)ans = i;
	}
	cout << ans;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin >> n >> m;
	for (int i=1;i<=n;i++)cin >> a[i];
	bool A = true,B = 1;
	sort(a+1,a+n+1);
	
	dlt = a[2] - a[1];
	a[0] = a[1] - dlt;
	for (int i=1;i<=n;i++){
		if (a[i] != i)A = false;
		if (a[i] - a[i-1] != dlt)B = false;
	}
	if (A){
		f();
	}else if(B){
		ff();
	}else fff();
	fclose(stdin);
	fclose(stdout);
	return 0;
}
