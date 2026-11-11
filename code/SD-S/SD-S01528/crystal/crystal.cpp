#include <bits/stdc++.h>
using namespace std;
#define LL long long

LL a[500005],sum[500005],m;
int n,ans=1;

int main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++) sum[i]=sum[i-1]+a[i];
	for(int i=1;i<=n;i++){
		int l=1,r=i;
		while(l<=r){
			int mid=(l+r)/2;
			if((i-mid+1)*a[i]-(sum[i]-sum[mid-1])<=m){
				ans=max(ans,i-mid+1);
				r=mid-1;
			}else{
				l=mid+1;
			}
		}
	}
	cout<<ans<<'\n';
	return 0;
}

