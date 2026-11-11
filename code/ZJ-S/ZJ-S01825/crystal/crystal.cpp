#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,ans=1,a[500005];
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+n+1);
	int l=1,r=2,s=0;
	while(r<=n){
		s+=(r-l)*(a[r]-a[r-1]);
		while(s>m)s-=(a[r]-a[l]),l++;
		ans=max(ans,r-l+1);
		r++;
	}
	cout<<ans;
	return 0;
}
/*
yellow?
orange?
5 5
1 2 4 8 9
5 8
-3 -1 2 2 7
?!14:46AC!?
*/
