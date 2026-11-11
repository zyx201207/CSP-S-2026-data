#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N=5e5+5;
int n,m,a[N],num,sum[N],minn,maxx;
signed main() {
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin >>n>>m;
	for (int i=1;i<=n;i++) {
		cin >>a[i];
		minn=min(minn,a[i]);
		maxx=max(maxx,a[i]);
	}
	sort(a+1,a+n+1);
	for (int i=1;i<=n;i++) {
		sum[i]=sum[i-1]+a[i];
		int l=1,r=i,ans=i;
		while (l<=r) {
//			cout <<l<<" "<<r<<"\n";
			int mid=l+r>>1;
			if (a[i]*(i-mid+1)-(sum[i]-sum[mid-1])<=m) r=mid-1,ans=mid;
			else l=mid+1;
		}
		
		num=max(num,i-ans+1);
	}
//	for (int i=minn;i<=maxx;i++) {
//		for (int j=1;j<=n;j++) {
//			if (a[j]<=i)
//		}
//	} 
	cout <<num; 
	return 0; 
}
/*
5 5
1 2 4 8 9
*/
