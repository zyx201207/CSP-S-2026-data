#include<bits/stdc++.h>
#define int long long
#define I_want_to_AK_csp return
using namespace std;

const int N=200005;
int a[N];
int n,m,maxn,ans;

signed main() {

	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);

	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin>>n>>m;
	for(int i=1; i<=n; i++) {
		cin>>a[i];
		maxn=max(maxn,a[i]);
	}

	ans=a[1];
	for(int i=2; i<=n; i++) {
		ans&=a[i];
	}

	if(m==1) {
		cout<<maxn;
	} else if(m==n) {
		cout<<ans;
	} else {
		sort(a+1,a+1+n,greater<int>());
		cout<<a[m];
	}

	I_want_to_AK_csp 0;
}
