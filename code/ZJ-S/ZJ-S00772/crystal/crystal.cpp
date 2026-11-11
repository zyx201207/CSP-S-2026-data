#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=1e6+7;

int n,m,ans,a[N],dp[N];

signed main(){
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+n+1);
	int l=1,now=0,la=0;
	
	for(int i=1;i<=n;i++){
		if(i!=n&&a[i]==a[i+1])continue;
		if(la)now+=(a[i]-a[la])*dp[la];
		while(l<i&&now>m){
			now-=a[i]-a[l];
			l++;
		}
		dp[i]=i-l+1;
		ans=max(ans,dp[i]);
		la=i;
	}
	cout<<ans<<'\n';
	return 0;
}
