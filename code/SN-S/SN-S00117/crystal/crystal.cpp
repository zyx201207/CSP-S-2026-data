#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m;
int a[500005];
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> m;
	for(int i=1;i<=n;i++){
		cin >> a[i];
	}
	sort(a+1,a+n+1);
	int ans=1;
	int l=1,r=1;
	int now=0;
	while(r<n){
		int len=r-l+1;
		r++;
		now+=len*(a[r]-a[r-1]);
		while(now>m){
			now-=(a[r]-a[l]);
			l++;
		}
		ans=max(ans,r-l+1);
	}
	cout << ans;
	return 0;
}

