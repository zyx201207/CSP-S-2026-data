#include <bits/stdc++.h>
using namespace std;
long long n,m;
long long a[500005];
long long prea[500005];
int f(int l,int r,int u){
	if(a[r]+m<a[u]) return u;
	while(l<r){
		int mid=(l+r)/2;
		long long g=(u-mid)*a[u];
		if(m+(prea[u-1]-prea[mid-1])<g) l=mid+1;
		else r=mid;
	}
	return l;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++) prea[i]=prea[i-1]+a[i];
	int ans=1;
	for(int i=1;i<=n;i++){
		int k=f(1,i-1,i);
		ans=max(ans,i-k+1);
	}
	cout<<ans;
	return 0;
}
