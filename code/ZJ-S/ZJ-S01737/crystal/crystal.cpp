#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N=5e5+7;
const int INF=0x3f3f3f3f3f3f3f3f;
int a[N];int ans=0;
signed main() {
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n,m;
	cin>>n>>m;
	for (int i=1;i<=n;i++) {
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	queue <int> Q;int tol=0;
	for (int i=1;i<=n;i++) {
		tol+=Q.size()*(a[i]-a[i-1]);
		while (tol>m) {
			tol-=a[i]-Q.front();
			Q.pop();
		}
		Q.push(a[i]);
		ans=max(ans,(long long)Q.size());
	}
	cout<<ans<<'\n';
}