#include<bits/stdc++.h>
#define int long long
using namespace std;
int xxhh,n,m,h,w,ans=0,cnt=0,a[2000005],b[100005];
signed main() {
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>xxhh>>w;
	while(w--) {
		cin>>n>>m;
		for(int i=1; i<=n; i++) {
			cin>>a[i];
		}
		h=a[2]-a[1];
		if(h>=m) {
			cout<<0<<"\n";
		} else {
			for(int i=3; i<=n; i++) {
				if(a[i]>m&&a[i-1]>m){
					ans++;
				}
			}
			cout<<ans<<"\n";
		}
	}
	return 0;
}
/*
0 2
4 2
1 2 3 4
5 2
1 2 3 4 5
0 2
5 3
-2 -1 0 1 2
6 2
-4 -3 -2 -1 3 6
*/