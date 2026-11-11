#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int MAXN = 5e5 + 5;
long long read(){long long r = 0,f = 1;char c = getchar();while(c == '-' || (c >= '0' && c <= '9')){if(c == '-'){f = -1;}else{r *= 10;r += int(c - '0');}c = getchar();}while(c >= '0' && c <= '9'){r *= 10;r += int(c - '0');c = getchar();}return r * f;}
ll n,m,ans = 0,l,r,sum = 0;
ll a[MAXN];
ll s[MAXN];
long long maxx(ll a,ll b){
	if(a > b) return a;
	else return b;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	n = read();
	m = read();
	for(ll i = 1;i <= n;i ++){
		a[i] = read();
	}
	sort(a + 1,a + 1 + n);
	s[0] = 0,a[0] = 0;
	for(ll i = 1;i <= n;i ++){
		s[i] = a[i] - a[i - 1];
	}
	l = 1,r = 2;
	while(r <= n){
		sum += (r - l) * (a[r] - a[r - 1]);
//		cout << endl;
//		cout << l << " " << r << " " << sum << endl;
		if(sum <= m){
//			if(r - l + 1 > ans) cout << l << " " << r << " " << sum << endl;
			ans = maxx(ans,r - l + 1);
			r ++;
			continue;
		}
		while(sum >= m && l <= r){
			sum -= (a[r] - a[l]);
			l ++;
		}
		if(l == r + 1){
			sum = 0;
			r = l + 1;
		}else{
			r ++;
		}
	}
	cout << ans;
	return 0;
}
