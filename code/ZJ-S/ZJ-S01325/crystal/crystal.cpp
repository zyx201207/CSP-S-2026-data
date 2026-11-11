#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,m,ans=1,a[500005],s[500005],p=1,now;
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=2;i<=n;i++){
		now+=(i-p)*(a[i]-a[i-1]);
		while(now>m){now-=a[i]-a[p++];}
		ans=max(ans,i-p+1);
	}
	cout<<ans;
}
