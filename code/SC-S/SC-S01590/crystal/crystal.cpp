#include <bits/stdc++.h>
using namespace std;
#define int long long
int n,m,a[500005],s[500005],l=1,ans;
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;++i) cin>>a[i];
	sort(a+1,a+1+n);
	for(int i=1;i<=n;++i) s[i]=s[i-1]+a[i];
	for(int i=1;i<=n&&l<=n;++i){
		while(a[i]*(i-l+1)-(s[i]-s[l-1])>m) l++;
		ans=max(ans,i-l+1);
	}
	cout<<ans;
	return 0;
}