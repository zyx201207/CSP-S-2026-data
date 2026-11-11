#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=2e6+10;
int c,q,n,d,a[N],cnts[N],dp[N];
void solve(int now, int cnt){
	if(now>n) return;
	if(cnts[now]<cnt) return;
	if(cnts[now]==cnt) dp[now]++;
	else cnts[now]=cnt,dp[now]=1;
	for(int i=now+1;i<=n&&a[i]-a[now]<=d;i++) solve(i,cnt+1);
}
signed main(){
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>q;
	while(q--){
		cin>>n>>d;
		int ans=0;
		for(int i=1;i<=n;i++) cin>>a[i];
		for(int i=1;i<=n;i++){
			for(int j=i;j<=n;j++) cnts[j]=INT_MAX,dp[j]=0;
			solve(i,0);
			for(int j=i;j<=n;j++) if(dp[j]==2) ans++;
		}
		cout<<ans<<endl;
	}
	return 0;
}
