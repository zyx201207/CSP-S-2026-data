#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=5e5+5;
int a[N];
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0);
	int n,m; cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+n+1);
	int ans=1;
	for(int i=n,j=n;i;i--){ // 以 i 为最大
		while(j&&a[i]-a[j]<=m){
			m-=(a[i]-a[j]),j--;
		}
		ans=max(ans,i-j);
		m+=(i-j)*(a[i]-a[i-1]);
	}
	cout<<ans;
	return 0;
}