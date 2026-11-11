#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500005],b[500005],ans;
bool check(long long x,long long y){
	if (b[x]-b[y]-(y-x)*(a[n]-a[y])<=m) return true;
	return false;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for (long long i=1;i<=n;i++) scanf("%lld",a+i);
	sort(a+1,a+n+1);
	for (long long i=n-1;i>0;i--){
		b[i]=b[i+1]+a[n]-a[i];
	}
	for (long long i=2;i<=n;i++){
		long long l=1,r=i;
		while(l<r){
			long long mid=(l+r)>>1;
			if (check(mid,i)) r=mid;
			else l=mid+1;
		}
		ans=max(ans,i-l+1);
	}
	cout<<ans<<endl;
	return 0;
} 
