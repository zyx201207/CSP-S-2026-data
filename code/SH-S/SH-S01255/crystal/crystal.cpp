#include <iostream>
#include <cstdio>
#include <climits>
#include <algorithm>
#define ll long long
using namespace std;
const ll INF=2e18;
const int N=5e5+5;
int n;
ll m,a[N],s[N];
ll qsum(int l,int r) {
	if(l>r) return 0;
	else return s[r]-s[l-1];
}
ll calc(int l,int r) {
	if(l>r) return INF;
	else return (r-l+1)*a[r]-qsum(l,r);
}
bool check(int cnt) {
	for(int l=1,r=cnt;r<=n;l++,r++)if(calc(l,r)<=m) return true;
	return false;
}
void solve() {
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++) s[i]=s[i-1]+a[i];
	int l=1,r=n,ans=1;
	while(l<=r) {
		int mid=l+r>>1;
		if(check(mid)) {
			ans=mid;
			l=mid+1;
		} else r=mid-1;
	}
	cout<<ans;
}
int main() {
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	int t=1;
	while(t--) solve();
	return 0;
}
