#include<bits/stdc++.h>
using namespace std;
#define int long long
const int inf=0x3f3f3f3f3f3f3f3f;
int n,m;
int a[500005];
int dp[500005];
bool check(int x,int y) {
	return (dp[y]-dp[x]-(x-1)*(a[y]-a[x]))<=m;
}
void solve() {
	cin>>n>>m;
	for(int i=1; i<=n; i++) {
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	dp[1]=0;
	for(int i=2; i<=n; i++) {
		dp[i]=dp[i-1]+(i-1)*(a[i]-a[i-1]);
	}
	int maxx=-1;
	for(int i=1; i<=n; i++) {
		int l=1,r=i-1,ans=0;
		while(l<r) {
			int mid=(l+r)/2;
			if(check(mid,i)) {
				int x=i;
				while(a[x+1]==a[x]) {
					x++;
				}
				ans=max(ans,x-mid+1);
				r=mid-1;
			} else {
				l=mid+1;
			}
		}
		maxx=max(maxx,ans);
	}
	cout<<maxx<<"\n";
}
signed main() {
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	solve();
	return 0;
}
