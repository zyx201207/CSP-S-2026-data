#include<bits/stdc++.h>
#define int long long
using namespace std;
int a[500005],s[500005];
int ans=1;
signed main() {
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n,m;
	cin>>n>>m;
	for(int i=1; i<=n; i++) cin>>a[i];
	sort(a+1,a+1+n);
	for(int i=1; i<=n; i++) s[i]=a[i]-a[i-1];
	int res=0,len=0;
	for(int ed=1; ed<=n; ed++) {
		res+=len*s[ed];
		while(1) {
			if(res>m) {
				res-=(a[ed]-a[ed-len]);
				len--;
			} else break;
		}
//		cout<<res<<" "<<len<<"\n";
		ans=max(ans,len+1);
		len++;
	}
	cout<<ans;
	return 0;
}
