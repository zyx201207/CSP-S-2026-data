#include<bits/stdc++.h>//powered_by_flyin2899
#define int long long 
//need to fix:TLE[09:xx]
//TLE has been fxxxg fixed![10:55]
using namespace std;

int a[200005],n,m;

signed main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	int ans=INT_MIN;
	for(int i=1;i<=n-m+1;i++){
		int t=a[i];
		for(int j=i+1;j<=i+m-1;j++){
			t&=a[j];
		}
		ans=max(ans,t);
	}
	cout<<ans;
	return 0;
}
