#include<bits/stdc++.h>
using namespace std;
long long m,a[500005],s[500005];
int n;
long long mon(int u,int l){
	return 1ll*l*a[u]-s[u]+s[u-l];
}
long long check(int l){
	long long minn=9e18;
	for(int i=l;i<=n;i++){
		minn=min(minn,mon(i,l));
	}
	return minn;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++) s[i]=s[i-1]+a[i];
	int l=1,r=n,mid;
	while(l<r){
		mid=(l+r+1)/2;
		if(check(mid)>m) r=mid-1;
		else l=mid;
	}
	cout<<l;
	return 0;
} 
