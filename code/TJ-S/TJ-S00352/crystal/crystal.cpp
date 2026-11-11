#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N=5*1e5+10;
int n,m,a[N],p[N];

signed main (){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	
	cin >> n >> m;
	for (int i=1;i<=n;i++){
		cin >> a[i];
	}
	sort(a+1,a+n+1);
	for (int i=1;i<=n;i++){
		p[i]=p[i-1]+a[i];
	}
	int l=1,r=1;
	int ans=0;
	while (r<=n){
		if (a[r]*(r-l)-(p[r-1]-p[l-1])<=m){
			ans=max(ans,r-l+1);
			r++;
		}
		else{
			l++;
		}
	}
	cout << ans;
	return 0;
}
