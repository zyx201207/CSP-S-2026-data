#include<bits/stdc++.h>
using namespace std;
//Oct31==Dec25?
long long n,m,a[500005],sum[500005],ans;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=n;i>=1;i--){
		sum[i]=sum[i+1]+(a[n]-a[i]);
	}
	for(long long i=1;i<=n;i++){
		long long l=1,r=i;
		while(l<r){
			long long mid=(l+r)/2;
			if(sum[mid]-sum[i]>m+(a[n]-a[i])*(i-mid+1)){
				l=mid+1;
			}else{
				r=mid;
			}
		}
		ans=max(ans,i-r+1);
	}
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
