#include<bits/stdc++.h>
using namespace std;
int n,ans;
long long m,a[500010],sum[500010];
int work(int x){
	int l=1,r=x;
	while(l<r){
		int mid=(l+r)/2;
		if((x-mid)*a[x]-sum[x-1]+sum[mid-1]<=m) r=mid;
		else l=mid+1;
	}
	return x-l+1;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++) sum[i]=sum[i-1]+a[i];
	for(int i=1;i<=n;i++){
		int t=work(i);
		ans=max(ans,t);
	}
	cout<<ans;
	return 0;
}