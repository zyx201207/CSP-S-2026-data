#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll n,m,a[500005];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	for(int i = 0;i < n;i++){
		scanf("%lld",a + i + 1);
	}
	sort(a + 1,a + n + 1);
	ll sum = 0,right = 1,ans = 1,left = 0;
	for(;right <= n;right ++){
		while(m < sum + (a[right] - a[right - 1]) * (right - left - 1)){
			sum -= a[right - 1] - a[left++];
		}
		ans = max(ans,right - left);
		sum += (a[right] - a[right - 1]) * (right - left - 1);
	}
	printf("%lld",ans);
	return 0;
}
