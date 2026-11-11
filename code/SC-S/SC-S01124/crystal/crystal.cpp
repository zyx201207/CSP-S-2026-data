#include<bits/stdc++.h>
using namespace std;
long long n,ans=1,m,a[500005],ca[500005];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=n-1;i>=1;i--){
		ca[i]=a[n]-a[i];
		ca[i]+=ca[i+1];
	}
	long long r=n,l=n-1;
	while(l>=1){
		long long sum=(ca[l]-ca[r+1])-(a[n]-a[r])*(r-l+1);
		if(sum<=m){
			ans=max(ans,r-l+1);
			l--;
		}else{
			r--;
		}
	}
	cout<<ans;
	return 0;
}