#include<bits/stdc++.h>
using namespace std;
long long a[500005];
long long sum[500005];
int n;
long long m;
int fnnd(int x){
	int l=1,r=x;
	int ans=x;
	while(l<=r){
		int mid=(l+r)/2;
		if(a[x]*(x-mid+1)-sum[x]+sum[mid-1]<=m){
			r=mid-1;
			ans=mid;
		}
		else{
			l=mid+1;
		}
	}
	return ans;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++){
		sum[i]=sum[i-1]+a[i];
	}
	int ans=0;
	for(int i=1;i<=n;i++){
		int x=fnnd(i);
		ans=max(ans,i-x+1);
	}
	cout<<ans;
	return 0;
}
