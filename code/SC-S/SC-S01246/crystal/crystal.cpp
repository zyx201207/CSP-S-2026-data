#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500005],sum,d[500005];
int ans,lstans;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;++i){
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	for(int i=1;i<=n;++i){
		d[i]=d[i-1]+a[i];
	}
	for(int l=1,r=1;max(l,r)<=n;++l){
		for(;r<=n&&a[r]*(r-l+1)-d[r]+d[l-1]<=m;++r){}
		--r;
		lstans=r-l+1;ans=max(ans,lstans);
	}
	cout<<ans<<endl;
	return 0;
}