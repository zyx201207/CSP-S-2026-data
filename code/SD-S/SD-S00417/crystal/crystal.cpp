#include <bits/stdc++.h>
#define max(a,b) (a>b?a:b)
#define min(a,b) (a<b?a:b)
#define ll long long
using namespace std;
const int N=5e6+5;
int a[N];
ll w[N],v[N],dp[N];
ll sum=0,ans;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	
	ll ok1=0,ok2=0,cha=0;
	ll n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]==i)
			ok1++;
		if(i>=2){
			cha=a[2]-a[1];
			if(cha==a[i]-a[i-1]){
				ok2++;
			}
		}
			
	}
	sort(a+1,a+n+1);
	if(ok1==n){
		int ans=0;
		ll sum=0;
		for(int i=1;i<=n;i++){
			sum+=i;
			if(m>=sum)
				ans=i+1;
		}
		if(ans>n)
			ans=n;
		cout<<ans;
		return 0;
	}
	if(ok2==n-1){
		int ans=0;
		ll sum=0;
		for(int i=cha;i<=cha*n;i++){
			sum+=i;
			if(m>=sum)
				ans++;
		}
		if(ans>n)
			ans=n;
		cout<<ans;
		return 0;
	}
	for(ll idx=1;idx<=n;idx++){
		memset(dp,0x3f,sizeof(dp));
		dp[0]=0;
		for(ll i=1;i<=idx;i++){
			w[i]=a[idx]-a[i];
		}
		for(ll i=1;i<=idx;i++){
			for(ll j=idx;j>=1;j--){
				dp[j]=min(dp[j],dp[j-1]+w[i]);
			}
		}
		for(ll i=idx;i>=0;i--){
			if(dp[i]<=m){
				ans=max(ans,i);
				break;
			}
		}
		
	}
	cout<<ans;
	return 0;
}
/*
5 5
1 2 4 8 9

5 8
-3 -1 2 2 7

5 1
3 6 9 12 15
*/
