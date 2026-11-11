#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m;
int a[500005];
signed main(){
	cin.sync_with_stdio(0),cin.tie(0),cout.tie(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdin);
	cin>>n>>m;
	for(int i = 1;i<=n;i++)cin>>a[i];
	sort(a+1,a+n+1);
	int l = 1,r = 1,sum = 0,ans = 1;
	while(l<=n){
		while(r<=n&&sum+(r-l+1)*(a[r+1]-a[r])<=m){
			sum+=(r-l+1)*(a[r+1]-a[r]);
			r++;
		}
//		cout<<l<<" "<<r<<" "<<sum<<'\n';
		ans = max(ans,r-l+1);
		sum-=a[r]-a[l]; 
		l++;
	}
	cout<<ans<<'\n';
	return 0;
} 
/*
<<<<<<<<J T3???
5 5
1 2 4 8 9

5 8
-3 -1 2 2 7
*/
