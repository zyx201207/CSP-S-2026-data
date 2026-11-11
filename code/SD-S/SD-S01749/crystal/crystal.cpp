#include<bits/stdc++.h>  //rp++
#define int long long
using namespace std;
int n,m,cost,ans = 1;
int a[500005];
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	for(int i = 1;i <= n;i++) scanf("%lld",&a[i]);
	sort(a + 1,a + n + 1);
	int l = 1,r = 1,cost = 0;
	while(l <= r && r <= n){
		ans = max(r - l + 1,ans);
		if(cost + (a[r + 1] - a[r]) * (r - l + 1) <= m){
			cost += (a[r + 1] - a[r]) * (r - l + 1);
			r++;
		}
		else{
			cost -= a[r] - a[l];
			l++;
		}
		if(l > r) r++;
		ans = max(r - l + 1,ans);
	}
	printf("%lld",ans);
	return 0;
}
