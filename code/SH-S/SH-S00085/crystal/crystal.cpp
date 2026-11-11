#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
const long long N=5e5+5;
long long a[N],sum[N];
long long n,m;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n>>m;
	for(long long i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(long long i=1;i<=n;i++){
		sum[i]=sum[i-1]+a[i];
	//	cout<<sum[i]<<" ";
	}
	//cout<<endl;
	long long ans=0;
	for(long long i=1;i<=n;i++){
		long long l=i,r=n,anss=0;
		while(l<=r){
			long long mid=(l+r)>>1;
			if(sum[mid]-sum[i-1]+m>=a[mid]*(mid-i+1)){
				anss=mid-i+1;
				l=mid+1;
			}
			else{
				r=mid-1;
			}
		}
		ans=max(ans,anss);
	}
	cout<<ans<<endl;
	return 0;
} 
