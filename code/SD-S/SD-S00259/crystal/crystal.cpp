#include<bits/stdc++.h>
#define int long long
#define N 500050
using namespace std;
int n,m,a[N],l,r,sum,ans;
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for (int i=1; i<=n; i++){
		cin>>a[i];
	}
	sort (a+1,a+1+n);
	l=r=1;
	while (l<=r && r<=n){
		sum+=(a[r]-a[r-1])*(r-l);
		if (sum>m){
			sum-=(a[r]-a[r-1])*(r-l);
			sum-=(a[r-1]-a[l++]);
		} else {
			ans=max (ans,r-l+1);
			r++;
		}
	}
	cout<<ans;
	return 0;
}
