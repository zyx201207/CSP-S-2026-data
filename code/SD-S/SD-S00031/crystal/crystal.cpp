#include <bits/stdc++.h>
#define int long long
using namespace std;
int n,m,a[500005],sum[500005],ans; 
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+1+n);
	int l=1;
	for(int i=1;i<=n;i++){
		sum[i]=sum[i-1]+a[i];
		while(l<i&&a[i]*(i-1-l+1)-(sum[i-1]-sum[l-1])>m)l++;
		ans=max(ans,i-1-l+1+1);
	}
	cout<<ans<<"\n";
	return 0;
}
//Hello, CCF ^_^, 100pts OK?

/*
5 5
1 2 4 8 9

5 8
-3 -1 2 2 7
*/
