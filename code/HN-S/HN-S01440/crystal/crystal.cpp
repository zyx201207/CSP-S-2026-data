#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
const ll N = 5e5 + 10;
ll n,m;
ll a[N];
int main() {
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>> n >> m;
	for(int i = 1; i <= n; i++) {
		cin>> a[i];
	}
	sort(a + 1, a + n + 1);
	ll res = 0 , ans = 0 , temp = 0 , last = 1;
	for(int i = 1; i <= n; i++) {
		if(i >= 1) res += temp * (a[i] - a[i - 1]);
		if(res <= m) {
			temp ++;
			ans = max(temp ,ans);
		}
		else {
			while(last <= n && res > m) {
				res -= (a[i] - a[last]);
				temp --;
				last++;
			}
			temp++;
		}
	} 
	cout<< ans << '\n';
	return 0;
} 
