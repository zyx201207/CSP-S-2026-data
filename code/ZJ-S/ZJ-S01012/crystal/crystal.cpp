#include<bits/stdc++.h>
using namespace std;
long long ans,a[500007],back[500007],n,m;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(long long i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(long long i=n;i>=1;i--){
		back[i]=back[i+1]+a[i];
	}
	for(long long i=n;i>=1;i--){
		long long j;
		for(j=i;j>=1&&a[i]*(i-j)-(back[j]-back[i])<=m;j--) ;
		ans=max(ans,i-j);
	}
	cout<<ans;
}
