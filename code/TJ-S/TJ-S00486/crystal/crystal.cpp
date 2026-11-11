#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
const LL N=500005;

LL n,m;
LL a[N];
LL s[N];

LL check(LL x){
	LL tmp=0;
	LL l=1,r=x,mid;
	while(l<=r){
		mid=l+(r-l)/2;
		if(a[x]*(x-mid+1)-(s[x]-s[mid-1])<=m){
			tmp=mid;
			r=mid-1;
		}
		else l=mid+1;
	}
	return x-tmp+1;
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(LL i=1;i<=n;i++) {
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	for(LL i=1;i<=n;i++) {
		s[i]=s[i-1]+a[i];
	}
	LL ans=0;
	for(LL i=1;i<=n;i++) {
		LL tmp=check(i);
		ans=max(ans,tmp);
	}
	cout<<ans;
	return 0;
}
