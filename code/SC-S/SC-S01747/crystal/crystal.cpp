#include <bits/stdc++.h>

#define int long long

using namespace std;

const int N = 5e5 + 10;

int n,a[N],pr[N],m,ans = 0;

signed main() {
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n>>m;
	for(int i = 1;i <= n;i++) {
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	for(int i = 1;i <= n;i++) {
		pr[i] = pr[i-1] + a[i];//cout<<pr[i]<<' ';
	}
//	cout<<"\n";
	for(int i = 1;i <= n;i++) {
		int l = 1,r = i,ret = i;
		while(l <= r) {
			int mid = (l + r) >> 1;
			int cst = a[i] * (i-mid+1) - pr[i] + pr[mid-1];
			//cout<<i<<"-"<<mid<<"->>"<<cst<<"\n";
			if(cst <= m) {
				ret = min(ret,mid);
				r = mid - 1;
			}else l = mid + 1;
		}
		ans = max(ans,i - ret + 1);
	}
	cout<<ans<<"\n";
	return 0;
}
/*
5 5
1 2 4 8 9

3
---
5 8
-3 -1 2 2 7

4
---

14:42
g++ '/home/user/work/csps/down/crystal/crystal.cpp' -o '/home/user/work/csps/down/crystal/crystal' -Wall
/usr/bin/time '/home/user/work/csps/down/crystal/crystal'
diff '/home/user/work/csps/down/crystal/m.out' '/home/user/work/csps/down/crystal/crystal3.ans'
*/