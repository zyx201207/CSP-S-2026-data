#include<bits/stdc++.h>
using namespace std;
int n;
long long m,a[500010],f[500010],dp,maxn;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	f[1]=0;
	for(long long i=2;i<=n;i++){
		f[i]=f[i-1]+(i-1)*(a[i]-a[i-1]);
	}
	for(long long i=1;i<=n;i++){
		long long l=i,r=n;
		while(l<r){
			long long mid=l+(r-l+1)/2;
			if(f[mid]-f[i]-(i-1)*(a[mid]-a[i])<=m){
				l=mid;
			}else{
				r=mid-1;
			}
		}
		dp=r-i+1;
		maxn=max(maxn,dp);
	}
	cout<<maxn<<endl;
	return 0;
}