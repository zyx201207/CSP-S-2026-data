#include<bits/stdc++.h>
#define ll long long
using namespace std;
int n,cnt;
ll m,a[500005],dif[500005],sum[500005];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i = 1;i <= n;i++) scanf("%lld",&a[i]);
	sort(a+1,a+n+1);
	for(int i = 1;i <= n;i++){
		dif[i] = a[n] - a[i];
		sum[i] = sum[i-1] + dif[i];
	}
	for(int i = 1;i <= n;i++){
		int l = 1,r = i,ans = 0;
		while(l <= r){
			int mid = (l+r)/2;
			ll len = i-mid+1;
			ll res = sum[i]-sum[mid-1] - len*dif[i];
			if(res <= m) r = mid-1,ans = len;
			else l = mid+1;
		}
		cnt = max(cnt,ans);
	}
	cout<<cnt;
	return 0;
}