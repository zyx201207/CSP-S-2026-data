#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=5e5+9;
ll n,m,ans,a[N],dp[N],cnt[209];
void solve(){
	for(ll i=1;i<=n;i++)dp[i]=1;
	for(ll i=1;i<=n;i++){
		ll j=i,last=m;
		while(last>a[i]-a[j]&&j>=1){
			j--;
			last-=(a[i]-a[j]);
			dp[i]++;
		}
	}
	return;
}
void solve2(){
	for(ll i=1;i<=n;i++)cnt[a[i]+101]++;
	for(ll i=1;i<=201;i++){
		ll j=i-1,sum=0,res=cnt[i];
		while(m-(i-j)*cnt[j]>=sum&&j>=1){
			sum+=(i-j)*cnt[j];
			res+=cnt[j];
			j--;
		}
		res+=(m-sum)/(i-j);
		ans=max(ans,res);
	}
	return;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(ll i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+n+1);
	if(n<=5000){
		solve();
		for(ll i=1;i<=n;i++)ans=max(ans,dp[i]);
		cout<<ans;
	}
	if(m<=100000000){
		solve2();
		cout<<ans;
	}
	return 0;
}
