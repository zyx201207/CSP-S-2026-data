#include<bits/stdc++.h>
//#define int long long
using namespace std;
long long n,m,a[601000],sum[600100];
int ans;
int check(int x){
	int l=0,r=x,ans=x;
	while(l<=r){
		int mid=l+r>>1;
		if(m-(a[x]*(x-mid))+sum[x]-sum[mid]<0)l=mid+1;
		else r=mid-1,ans=mid;
	}
	return ans;
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
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
	for(int i=1;i<=n;i++){
		ans=max(ans,i-check(i));
	}
	cout<<ans;
	return 0;
}
