#include<bits/stdc++.h>
#define ll long long
#define endl "\n"
#define fi first
#define se second
using namespace std;
ll a[500005];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int n; scanf("%d",&n);
	ll m; scanf("%lld",&m);
	for(int i = 1;i <= n;i++)	scanf("%lld",&a[i]);
	sort(a+1,a+n+1);
	int l = 1,r = 1,ans=1;
	ll sum = 0;
	while(r<=n){
		r++,sum+=(a[r]-a[r-1])*(r-l);
		while(sum>m){
			l++,sum-=a[r]-a[l-1];
		}
		ans=max(ans,r-l+1);
	}
	printf("%d",ans);
	return 0;
}