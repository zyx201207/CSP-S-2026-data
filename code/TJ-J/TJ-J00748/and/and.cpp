#include<bits/stdc++.h>
using namespace std;
int n,m;
long long a[200005], ans;
int cmp(int x, int y) {
	return x>y;
}
int main() {
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin>>n>>m;
	for(int i=1; i<=n; i++) {
		cin>>a[i]; 
	}
	sort(a, a+n+1, cmp);
	if(n>2000) {
		if(n>2e5) {
			cout<<a[1];
			return 0;
		}
		if(m=1) {
			cout<<a[1];
			return 0;
		}
		if(m=n) {
			ans=a[1];
			for(int i=1; i<=n; i++) {
				ans&=a[i];
			}
			cout<<ans;
			return 0;
		}
	}
	ans=a[1];
	cout<<a[1];
	for(int i=2; i<=m; i++) {
		ans&=a[i];
	}
	cout<<ans;
	return 0;
} 

