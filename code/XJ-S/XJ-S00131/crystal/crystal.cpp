#include<bits/stdc++.h>
using namespace std;
long long n,m; 
long long arr[500005];
long long qz[500005];
long long ans=1; 
long long fd(long long xb){
	long long l=1,r=xb,mid;
	while(l<r){
		mid=(l+r)>>1;
		long long d=xb-mid;
		long long sum=qz[xb-1]-qz[xb-d-1];
		long long c=d*arr[xb]-sum;
		if(c>m){
			l=mid+1;
		}else{
			r=mid;
		}
	}
	return xb-l+1;
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(long long i=1;i<=n;i++){ 
		cin>>arr[i];
	} 
	sort(arr+1,arr+1+n);
	for(long long i=1;i<=n;i++){
		arr[i]+=1e12+1;
		qz[i]=qz[i-1]+arr[i];		
	}
	for(long long i=1;i<=n;i++){
		long long tmp=fd(i);
		ans=max(ans,tmp);
	}
	cout<<ans;
	return 0;
}

