#include<bits/stdc++.h>
#define ll long long
using namespace std;
int n;
ll m;
ll a[500005],sum[500005];
inline int f(int x){
	int l=0,r=x;
	while(l<r){
		int mid=(l+r)>>1;
		if(a[x]*mid-(sum[x]-sum[x-mid])<=m) l=mid+1;
		else r=mid-1;
	}
	return r;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> m;
	for(int i=1;i<=n;i++){
		cin >> a[i];
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		sum[i]=sum[i-1]+a[i];
	}
	int ans=0;
	for(int i=1;i<=n;i++){
		ans=max(ans,f(i));
	}
	cout << ans << '\n';
	return 0;
}
