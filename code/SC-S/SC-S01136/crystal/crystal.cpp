#include<bits/stdc++.h>
#define ll long long 
using namespace std;
ll m,n,a[500050],cnt,ans,dp[500050],p;//dp[a[i]] 当合成水晶都为a[i]时的最大数量 
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(ll i=1;i<=n;i++){
		cin>>a[i];
		dp[a[i]]=1;
	}
	p=a[2]-a[1];
	for(ll i=1;i<=n;i++){
		if(a[i+1]-a[i]==p&&(i+1)!=(n+1)) cnt++;
	}
	if(cnt==n-1){
		ll pre=p;
		for(ll i=n;i>=1;i--){
			m-=pre;pre+=p;
			if(m>=0){
				ans++;
			}
		}
		cout<<ans;
		return 0;
	}else{
		ans=-1;
		sort(a+1,a+1+n);
		ll pre=0,mm=m;
		for(ll i=1;i<=n;i++){
			if(a[i]==a[i-1]){
				dp[a[i]]=dp[a[i-1]]+1;
			}else if(i!=1){
				mm=m;
				pre=a[i]-a[i-1];
				for(ll j=i-1;j>=1;j--){
					pre=a[i]-a[j];
					mm-=pre;
					if(mm>=0){
						dp[a[i]]++;
					}else{
						break;
					}
				}
			}
		}
		for(ll i=1;i<=n;i++){
			ans=max(ans,dp[a[i]]);
		}
		cout<<ans;
	}
	
	return 0;
}

/*
10 20
1 5 10 15 20 25 30 35 40 45
5
1 5 10 15 20 25 30 45 45 45

*/