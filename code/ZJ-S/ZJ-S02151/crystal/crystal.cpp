#include<bits/stdc++.h>
#define int long long
#define N 501000
using namespace std;
void hey() {
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
}
int n,m;
int a[N],s[N];
int cal(int x,int y) {
	return a[y]*(y-x+1)-(s[y]-s[x-1]);
}
int check(int x) {
	int l=1,r=x;
	while(l<r) {
		int mid=(l+r)>>1;
		if(cal(mid,x)>m) l=mid+1;
		else r=mid-1;
	}
	if(cal(l,x)>m) return 0;
	return x-l+1;
} 
signed main() {
	hey();
	scanf("%lld %lld",&n,&m);
	for(int i=1;i<=n;i++) {
		scanf("%lld",&a[i]);
	}
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++) {
		s[i]=s[i-1]+a[i];
	}
	int ans=-1;
	for(int i=1;i<=n;i++) {
		ans=max(ans,check(i));
	}
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
