#include<bits/stdc++.h>
#define endl "\n"
#define int long long
using namespace std;
const int N = 1e6 + 10;
int n,m,a[N];
int andji[N];
//priority_queue
//lower_bound upper_bound
bool vis[N];
set<int>st;
void dfs(int dqand,int cishu) {
	if(cishu==0) {
		st.insert(dqand);
		return;
	}
	for(int i=1; i<=n; i++) {
		if(!vis[i]) {
			vis[i]=1;
			dfs(dqand&a[i],cishu-1);
			vis[i]=0;
		}
	}
}
void solve() {
	cin>>n>>m;
	if(m==1) {
		int maxx=-1e18;
		for(int i=1; i<=n; i++) {
			cin>>a[i];
			maxx=max(maxx,a[i]);
		}
		cout<<maxx<<endl;
		return;
	}
	for(int i=1; i<=n; i++) {
		cin>>a[i];
	}
	if(m==n-1) {
		for(int i=1; i<=n; i++) {
			for(int j=1; j<=i; j++) {
				andji[j]&=a[i];
			}
		}
		int maxx=andji[2];
		for(int i=3; i<=m; i++) {
			for(int j=n-i+3; j<=n; j++) {
				andji[i]&=a[j];
			}
			maxx=max(maxx,andji[i]);
		}
		cout<<maxx<<endl;
		return;
	}
	int maxx=-1e18;
	for(int i=1; i<=n; i++) {
		vis[i]=1;
		dfs(a[i],m-1);
		vis[i]=0;
	}
	for(auto it:st) {
		maxx=max(maxx,it);
	}
	cout<<maxx<<endl;
}
signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int _ = 1;
//	cin>>_;
	while(_--) {
		solve();
	}
	return 0;
}
