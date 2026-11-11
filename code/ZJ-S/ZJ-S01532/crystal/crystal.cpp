#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=5e5+5;
int n,m,a[N],d[N],b[N],s[N];
bool check(int x){
	for(int i=1;i<x;i++) b[i]=b[i-1]+i*d[i];
	if(b[x-1]<=m) return 1;
	for(int i=x;i<n;i++){
		b[i]=b[i-1]+x*d[i]-(s[i-1]-s[i-x]);
		if(b[i]<=m) return 1;
	}
	return 0;
}
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	for(int i=1;i<=n;i++) scanf("%lld",a+i);
	sort(a+1,a+n+1);
	for(int i=1;i<n;i++) d[i]=a[i+1]-a[i],s[i]=s[i-1]+d[i];
	int l=1,r=n,ans=1;
	while(l<=r){
		int mid=l+r>>1;
		if(check(mid)) l=mid+1,ans=mid;
		else r=mid-1;
	}
	printf("%lld",ans);
	return 0;
}
