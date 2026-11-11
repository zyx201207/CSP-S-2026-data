#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long
const int N=5e5+10;
int n,m,a[N],maxn,l,r,mid,ans;
bool check(int k) {
	int cnt=0,mincnt=LONG_LONG_MAX;
	for (int i=1;i<=k;i++) {
		cnt+=a[k]-a[i];
	}
	if (cnt<=m) {
		return true;
	}
	for (int i=2;i<=n-k+1;i++) {
		cnt-=a[i+k-2]-a[i-1];
		cnt+=(k-1)*(a[i+k-1]-a[i+k-2]);
		if (cnt<=m) {
			return true;
		}
	}
	return false;
}
bool cmp(int x,int y) {
	return x<y;
}
signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for (int i=1;i<=n;i++) {
		cin>>a[i];
	}
	sort(a+1,a+1+n,cmp);
	l=1,r=n;
	while (l<r) {
		mid=(l+r)>>1;
		if (check(mid)) {
			l=mid+1;
		}
		else {
			r=mid;
		}
	}
	while (!check(r)) {
		r--;
	}
	cout<<r<<endl;
	return 0;
}
