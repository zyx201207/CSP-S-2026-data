#include<bits/stdc++.h>
using namespace std;
long long a[500010];
long long sum[500010];
int main(){
	freopen("crystal.in","r",stdin); 
	freopen("crystal.out","w",stdout); 
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	long long n,m;cin>>n>>m;
	for(long long i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(long long i=1;i<=n;i++){
		sum[i]=sum[i-1]+a[i]; 
	}
	long long ans=0;
	for(long long i=1;i<=n;i++){
		long long l=1,r=i,res=i;
		while(l<=r){
			long long mid=(l+r)/2;
			long long d=(i-mid+1)*a[i]-(sum[i]-sum[mid-1]);
			if(d<=m){
				res=mid;r=mid-1;
			}else{
				l=mid+1;
			}
		}
		ans=max(ans,i-res+1);
	}
	cout<<ans;return 0;
}
