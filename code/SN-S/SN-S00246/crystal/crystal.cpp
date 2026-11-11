#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N = 5e5+5;
int n,m;
int a[N],dp[N],sum[N];
int minn = 4e18,ans = 0;
bool flag = 1;
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+1+n);
	int v = a[2]-a[1];
	for(int i=1;i<=n;i++){
		if(i > 1 && a[i]-a[i-1] != v) flag = 0;
		minn = min(minn,a[i]-a[i-1]);
	}
	if(minn > m) cout<<0<<endl;
	else if(minn == m) cout<<1<<endl;
	else{
		if(flag == 1){
			for(int i=1;i<=n;i++){
				int u = sqrt(m*2/v)+1;
				if(u*(u-1) <= m) ans = max(ans,u);
				else ans = max(ans,u-1);
			}
			cout<<ans<<endl;
			return 0;
		}
		for(int i=1;i<=n;i++){
			dp[i] = 1;
			int x = m,cnt = 1;
			while((x-a[i]+a[i-cnt] >= 0) && (i > cnt)){
				x -= (a[i]-a[i-cnt]);
				cnt++;
				dp[i] ++;
			}
			ans = max(ans,dp[i]);
		}
		cout<<ans<<endl;
	}
	return 0;
}
