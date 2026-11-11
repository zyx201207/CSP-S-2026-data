#include <bits/stdc++.h>
#define endl '\n'
#define int long long
using namespace std;
constexpr int N=5e5+10;
int n,m,a[N],d[N],s[N],ss[N],ans,tmp;

signed main() {
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+n+1);
	for(int i=2;i<=n;i++) d[i]=a[i]-a[i-1];	
	for(int i=2;i<=n;i++) s[i]=d[i]+s[i-1];
	for(int i=2,l=2;i<=n;i++) {
		tmp+=d[i]*(i-l+1);
		if(tmp<=m) ans=max(ans,i-l+2);
		else {
			while(tmp>m) {
				tmp=tmp-(s[i]-s[l-1]);
				l++;
			}
		}
	}
	cout<<ans<<endl;
	return 0;
}
