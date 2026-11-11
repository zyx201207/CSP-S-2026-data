#include<bits/stdc++.h>
#define ll long long
using namespace std;
int n;
ll m;
ll A[500005];
ll sum[500005];
int ans;
void solve() {
	scanf("%d%lld",&n,&m);
	for(int i=1; i<=n; i++) {
		scanf("%lld",&A[i]);
	}
	sort(A+1,A+n+1);
	for(int i=1; i<=n; i++) {
		A[i]=A[i]-A[1];
		sum[i]=sum[i-1]+A[i];
	}
	for(int i=1; i<=n; i++) {
		int l=1,r=i;
		while(l<r){
			int mid=(l+r)/2;
			if(A[i]*(i-mid+1)-(sum[i]-sum[mid-1])<=m){
				r=mid;
			}else{
				l=mid+1;
			}
		}
		ans=max(ans,i-r+1);
	}
	printf("%d",ans);
	return;
}
int main() {
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	solve();
	return 0;
}