#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#define ll long long
using namespace std;
const int N=5e5+5;
int n;
ll m,a[N];
ll pre[N],ans;
ll calc(int l,int r) {
	ll len=r-l+1;
	ll need=len*a[r],now=pre[r]-pre[l-1];
	ll ret=need-now;
	return ret;
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1; i<=n; i++) cin>>a[i];
	sort(a+1,a+n+1);
	for(int i=1; i<=n; i++) pre[i]=pre[i-1]+a[i];
	int l=1;
	for(int r=1; r<=n; r++) {
		while(l<=r&&calc(l,r)>m) l++;
		ll ans1=r-l+1;
		ans=max(ans,ans1);
	}
	cout<<ans<<endl;
	return 0;
}
