#include<bits/stdc++.h>
#define N 500005
typedef long long ll;
using namespace std;

ll n,m;
ll a[N];
ll d[N];
ll add[N] = {0};
ll p;
ll ans = 0;

int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	p = 0;
	for(int i = 1 ; i <= n ; i++){
		scanf("%lld",&a[i]);
	}
	sort(a+1,a+1+n);
	for(int i = 2 ; i <= n ; i++){
		d[i] = a[i] - a[i - 1];
	}
	ll l = 1,r = 1,cnt = 1;
	while(r < n){
		while(p + d[r + 1] * cnt <= m && r < n){
			p += d[r + 1] * cnt;
			cnt++;
			r++;
			ans = max(ans,r-l+1);
		}
		do{
			p -= (a[r] - a[l]);
			cnt--;
			l++;
		}while(p - (a[r] - a[l]) > m);
	}
	printf("%lld",ans);
	
	return 0;
}
