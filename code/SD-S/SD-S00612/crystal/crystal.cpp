#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N=5e5+10;
int n,m,ans=-1e12;
int a[N];
int s[N];
signed main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for (int i=1; i<=n; i++) cin>>a[i];
	sort(a+1,a+n+1);
	for (int i=1; i<=n; i++) s[i]=s[i-1]+a[i];
	for (int i=1; i<=n; i++) {
		int l=1,r=i,res=-1e9,mid;
		while (l<=r) {
			mid=l+r>>1;
			if (a[i]*(i-mid+1)-s[i]+s[mid-1]<=m) {
				res=max(res,i-mid+1);
				r=mid-1;
			} else {
				l=mid+1;
			}
			//cout<<l<<" "<<r<<"\n";
		}
		ans=max(res,ans);
	}
	cout<<ans;
	return 0;
}
/*
5 8
-3 -1 2 2 7
*/
