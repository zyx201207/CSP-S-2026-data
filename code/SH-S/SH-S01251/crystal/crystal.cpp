#include<bits/stdc++.h>
using namespace std;
long long f[500009],k[500009],sum[500009],sum_anss[500009];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	long long n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>f[i];
	sort(f+1,f+1+n);
	f[0]=f[1];
	for(int i=1;i<=n;i++) k[i]=f[i]-f[i-1];
	for(int i=1;i<=n;i++) sum[i]=sum[i-1]+k[i];
	for(int i=1;i<=n;i++) sum_anss[i]=sum_anss[i-1]+sum[i];
	long long ans=1;
	for(int i=2;i<=n;i++){
		long long left=0,right=i;
		while(left+1<right){
			long long mid=(left+right)/2;
			if(sum[i]*(i-mid+1)-sum_anss[i]+sum_anss[mid-1]<=m) right=mid;
			else left=mid;
		}
		ans=max(ans,i-right+1);
	}
	cout<<ans;
	return 0;
} 
