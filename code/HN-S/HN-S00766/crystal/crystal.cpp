#include <bits/stdc++.h>
using namespace std;
long long n,m,ans;
long long a[500005];
long long sum[500005];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cout.tie(0);cin.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++)
		sum[i]=sum[i-1]+a[i];
	ans=1;
	for(long long i=2;i<=n;i++){
		long long l=1,r=i;
		while(l<r){
			long long mid=(l+r)/2;
			long long s=(i-mid+1)*a[i]-(sum[i]-sum[mid-1]);
			if(s<=m) r=mid;
			else l=mid+1;
		}
		ans=max(ans,i-l+1);
	}
	cout<<ans<<"\n";
	return 0;
}
