#include<bits/stdc++.h>
using namespace std;
int n,ans;
long long m,a[500005],sum[500005];
long long count(int fi,int las){
	return (las-fi+1)*a[las]-(sum[las]-sum[fi-1]);
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		sum[i]=sum[i-1]+a[i];
	}
	for(int i=1;i<=n,n-i+1>ans;i++){
		int l=1,r=n;
		while(l<r){
			int mid=(l+r+1)/2;
			if(count(i,mid)>m){
				r=mid-1;
			}
			else{
				l=mid;
			}	
		}
		ans=max(ans,l-i+1);
	}
	cout<<ans;
	return 0;
} 
