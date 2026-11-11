#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=500005;
int n;
ll m;
ll a[N],pre[N];
int main() {
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%d%lld",&n,&m);
	for (int i=1;i<=n;i++) {
		scanf("%lld",&a[i]);
	}
	int ans=1;
	sort(a+1,a+1+n);
	int l=1,r=2;
	while (l<=r&&r<=n) {
		if (a[r]-a[l]<=m) ans=max(ans,r-l+1),r++;
		else l++;
	}
	cout<<ans<<'\n';
	return 0;
}
