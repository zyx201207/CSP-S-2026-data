#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 5005,M=3e5;
ll n, m, a[M],b[M], ans = 1;
int main() {
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%lld%lld", &n, &m);
	for (int i = 1; i <= n; i++) {
		ll x;
		scanf("%lld", &x);
		if(x>0){
			a[x]++;
		}else{
			b[-x]++;
		}	
	}
	for (ll i = 0; i <= N; i++) {
		if (a[i] >= 2) {
			a[i] %= 2;
			a[i*2] += a[i] / 2;
			ans++;
		}
		if (b[i] >= 2) {
			b[i] %= 2;
			b[i/2] += b[i] / 2;
			ans++;
		}
	}
	for(ll i = 0;i <= N ;i++) {
		for(ll j=0;j<=N;j++){
			
			if(i!=j&&a[i]>0&&a[j]>0&&m>abs(i-j)){
				if(i<j){
					m=m+i-j;
					a[i]--;
					a[j]--;
					a[j*2]++;
					ans++;
				}else{
					m=m+j-i;
					a[i]--;
					a[j]--;
					a[i*2]++;
					ans++;
				}
			}
			if(i!=j&&b[i]>0&&b[j]>0&&m>abs(i-j)){
				if(i<j){
					m=m+i-j;
					b[i]--;
					b[j]--;
					b[j/2]++;
					ans++;
				}else{
					m=m+j-i;
					b[i]--;
					b[j]--;
					b[i/2]++;
					ans++;
				}
			}
		}
	}
	printf("%lld", ans);
	//5 8 2 -3 -1 2 2 7
}