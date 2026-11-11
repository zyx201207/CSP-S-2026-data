#include<bits/stdc++.h>
using namespace std;
long long n;
long long a[500010];
long long f[500010];
long long m;
long long ans=INT_MIN;
int rf(int p,long long num){
	int l=1;
	int r=p;
	int mid;
	int ans;
	while(l<r-1){
		mid=(l+r)/2;
		if(num-f[mid]-(a[p]-a[mid])*mid>=0){
			l=mid;
		}
		else{
			ans=mid;
			r=mid;
		}
	}
	if(num-f[mid]-(a[p]-a[mid])*mid>0){
		return ans+1;
	}
	else{
		return ans;
	}
}
bool cmp(long long a1,long long b1){
	return a1<b1;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(long long i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a,a+n+1,cmp);
	for(long long i=1;i<=n;i++){
		f[i]=f[i-1]+((a[i]-a[i-1])*(i-1));
		if(f[i]<=m){
			ans=i;
		}
		else{
			long long lesd=f[i]-m;
			long long cnt=i-rf(i,lesd);
			ans=max(cnt,ans);
		}
	}
	cout<<ans;
	return 0;
} 
