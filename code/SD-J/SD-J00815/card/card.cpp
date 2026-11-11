#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=5e5+10;
int n,m;
int a[N];
map<int,int> mp;
map<int,int> vis;
int ans[N];
bool check() {
	for (auto i:mp) {
		if (i.second>1) {
			return false;
		}
	}
	return true;
}
void Delete(int l,int r) {
	for (int i=l; i<=r; i++) {
		vis[a[i]]=0;
	}
}
signed main() {
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for (int i=1; i<=n; i++) {
		cin>>a[i];
		mp[a[i]]++;
	}
	for (int i=1; i<=n; i++) {
		bool flag=0;
		if (flag) {
			for (int j=n-i+1; j<=n; j++) {
				ans[a[j]]++;
			}
			continue;
		}
		if (check()) {
			flag=1;
		}
		for (int i=1; i<=n; i++) {
			vis[a[i]]=0;
		}
		for (int j=i; j<=n; j++) {
			if (!vis[a[j]]) {
				vis[a[j]]=j;
			} else {
				Delete(vis[a[j]],j);
				vis[a[j]]=j;
			}
		}
		for (auto x:vis) {
			if (x.second) {
				ans[x.first]++;
				//cout<<x.first<<" ";
			}
		}
		//cout<<"\n";
		mp[a[i]]--;
	}
	for (int i=1; i<=m; i++) {
		cout<<ans[i]<<" ";
	}
	return 0;
}
/*
10 3
3 1 2 1 3 2 3 1 2 1
*/
