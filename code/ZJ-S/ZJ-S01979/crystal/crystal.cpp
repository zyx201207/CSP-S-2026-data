#include <bits/stdc++.h>
#pragma GCC optimize("O2")
#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#define int long long
using namespace std;
int n,m,i,a[500010];
int val(int x){
	int ans=0;
	for(int i=1;i<=n;i++) a[i]=abs(a[i]-x);
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++)
		if(m>=a[i]) m-=a[i],ans++;
		else break;
	return ans;
}
main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+1+n);
	if(n&1) cout<<val(a[n/2+1]);
	else cout<<val(a[n/2]);
	return 0;
}