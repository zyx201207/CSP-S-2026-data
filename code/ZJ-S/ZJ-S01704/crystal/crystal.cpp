#include<bits/stdc++.h>
using namespace std;
int n,m;
long long ans;
long long a[500001];
pair<long long,long long>dp[500001];
bool isa,isb;
long long isbb;
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	isa=isb=true;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]!=i)isa=false;
		if(i>=3 && a[i]-a[i-1]!=a[i-1]-a[i-2])isb=false;
		isbb=a[i]-a[i-1];
	}
	if(isa){
		cout<<min(int(sqrt(m*2)),n)+1<<endl;
		return 0;
	}else if(isb){
		cout<<min(int(sqrt(m*2/isbb)),n)+1<<endl;
		return 0;
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		dp[i].first=1;dp[i].second=0;
		for(int j=i-1;j>=1;j--){
			if(dp[j].first*(a[i]-a[j])+dp[j].second<=m){
				if(dp[j].first+1>dp[i].first){
					dp[i].first=dp[j].first+1;
					dp[i].second=dp[j].first*(a[i]-a[j])+dp[j].second;
				}else if(dp[j].first+1==dp[i].first && dp[j].second+dp[j].first*(a[i]-a[j])<dp[i].second){
					dp[i].second=dp[j].first*(a[i]-a[j])+dp[j].second;
				}
			}
		}
		ans=max(ans,dp[i].first);
	}
	cout<<ans<<endl;
	return 0;
}
