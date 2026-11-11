#include<bits/stdc++.h>
#define int long long
using namespace std;
int a[500010];
int s[500010];
//int t[500010];
signed main() {
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	int n,m;
	cin>>n>>m;
	for (int i=1;i<=n;i++) {
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	for (int i=1;i<=n;i++) {
		s[i]=(a[i]-a[i-1])*(i-1)+s[i-1];
		//cout<<s[i]<<" ";
	}
	int l=1;
	int ans=0;
	for (int i=1;i<=n;i++) {
		int t=s[i]-s[l-1]-(l-1)*(a[i]-a[l]);
		//cout<<t<<" ";
		if (t>m) {
			//cout<<l<<"\n";
			ans=max(ans,i-l);
		}
		while (t>m) {
			//t-=a[l];
			t-=(a[i]-a[l]);
			l++;
		}
	}
	//cout<<l<<" "<<n;
	ans=max(ans,n-l+1);
	cout<<ans;
	return 0;
}
/*
5 8
-3 -1 2 2 7
*/
//AC
