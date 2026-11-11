#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m;
int a[500005],qz[500005];
int ans;
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		qz[i]=qz[i-1]+a[i];
		//cout<<a[i]<<" ";
	}
	int l=1,r=1;
	while(r<n){
		while(qz[r]-qz[l-1]+m>=a[r]*(r-l+1)&&r<n)r++;
		ans=max(ans,r-l);
		//cout<<l<<" "<<r<<'\n';
		while(qz[r]-qz[l-1]+m<a[r]*(r-l+1)&&l<r)l++;
	}
	cout<<ans;
	return 0;
}
