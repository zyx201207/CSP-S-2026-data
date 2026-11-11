#include<bits/stdc++.h>
#define endl "\n"
#define int long long
using namespace std;
const int N = 1e6 + 10;
int n,m,a[N],c[N];
int ans;
int maxx=-1e18;
bool check(int mid) {
	for(int i=1; i<=n; i++) {
		c[i] = mid-a[i];
	}
	ans=0;
	int i=1,mm=m;
	while(mm>=0&&i<=n) {
		int x=c[i];
		if(x>=0&&mm>=x) {
			ans++;
			mm-=x;
		}
		i++;
	}
	return (maxx<ans);
}
void solve() {
	cin>>n>>m;
	bool f=1;
	for(int i=1; i<=n; i++) {
		cin>>a[i];
		if(a[i]!=i){
			f=0;
		}
	}
	sort(a+1,a+1+n);
	int l = 1,r = n;
	while(l < r) {
		int mid = (l + r) >> 1;
		if(check(a[mid])) {
			l = mid + 1;
		} else {
			r = mid;
		}
		maxx = max(maxx,ans);
	}
	cout<<max(maxx,ans)<<endl;
}
signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int _ = 1;
//	cin>>_;
	while(_--) {
		solve();
	}
	return 0;
}
