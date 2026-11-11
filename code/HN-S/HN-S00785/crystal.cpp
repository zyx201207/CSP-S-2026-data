#include<bits/stdc++.h>
using namespace std;
int n;
long long m,a[500005],sum[500005];
long long get(int l,int r){
	return a[r]*(r-l+1)-(sum[r]-sum[l-1]);
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++)sum[i]=sum[i-1]+a[i];
	int ans=1;
	for(int l=1,r=1;l<=n;l++){
		if(r<l)r=l;
		while(r<n&&get(l,r+1)<=m)r++;
		ans=max(ans,r-l+1);
	}
	cout<<ans;
	return 0;
}
