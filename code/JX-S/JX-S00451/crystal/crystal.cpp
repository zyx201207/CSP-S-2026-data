#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,a[1000000],s[1000000],suf[1000000],suff[1000000],ans=1;
int calc(int l,int r){
	return suff[l+1]-suff[r+1]-(r-l)*suf[r+1];
}
bool check(int l,int r){
	if(calc(l,r)<=m) return 1;
	return 0;
}
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++) s[i]=a[i]-a[i-1];
	for(int i=n;i>=1;i--) suf[i]=suf[i+1]+s[i];
	for(int i=n;i>=1;i--) suff[i]=suff[i+1]+suf[i];
	for(int i=1;i<=n;i++){
		int l=0,r=i;
		while(l+1!=r){
			int mid=(l+r)/2;
			if(check(mid,i)) r=mid;
			else l=mid;
		}
		if(check(1,i)) ans=max(ans,i);
		else ans=max(ans,i-r+1);
	}
	cout<<ans;
	return 0;
}

