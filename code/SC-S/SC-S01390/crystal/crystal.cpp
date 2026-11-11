#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll n,m,ans=0;
vector<ll> a;
ll dp[500001];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	a.push_back(0);
	for(int i=1;i<=n;++i){
		ll w;
		scanf("%lld",&w);
		a.push_back(w);
	}
	sort(a.begin()+1,a.end());
	int t=1;
	for(int i=1;i<=n;++i){
		if(a[i]==a[i-1]){
			ans=max(ans,i-(ll)t+1);
			continue;
		}
		int q=a[i]-a[i-1];
		for(int j=i-1;j>=t;--j){
			dp[j]=dp[j]+(i-j)*q;
			if(dp[j]<=m){
				if(i-j+1>ans){
					ans=i-j+1;
					//cout<<i<<':'<<j<<':'<<dp[j]<<' ';	
				}
			}else{
				t=j+1;
				break;
			}
		}
	}
	printf("%lld",ans);
} 