#include<bits/stdc++.h>
#define int long long
using namespace std;
int a[500005];
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+n+1);
	int l=1;
	int ans=1,sum=0;
	for(int i=1;i<=n;i++){
		sum+=(a[i]-a[i-1])*(i-l);
		while(l<i&&sum>m)l++,sum-=(a[i]-a[l]);
		ans=max(ans,i-l+1);
	}
	cout<<ans;
	return 0;
}