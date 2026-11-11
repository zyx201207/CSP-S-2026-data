#include<bits/stdc++.h>
using namespace std;
int n,m,a[500005],last[500005],ans[300005];
vector<pair<int,int>> dp[500005];
bool flag=1;
void Tesk(){
	for(int i=1;i<=m;i++) cout<<i<<' ';
	exit(0);
}
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		if(a[i-1]>a[i]) flag=0;
	}
	if(flag) Tesk();
	for(int i=n;i>=1;i--){
		if(!last[a[i]]) last[a[i]]=i;
	}
	for(int i=n;i>=1;i--){
		if(last[a[i]]==i){
			if(i+1<=n){
				for(int j=0;j<dp[last[a[i+1]]].size();j++){
					dp[i].push_back({dp[last[a[i+1]]][j].first,dp[last[a[i+1]]][j].second});
				}
			}
			dp[i].push_back({a[i],1});
			
		}
		for(int j=0;j<dp[last[a[i]]].size();j++){
			ans[dp[last[a[i]]][j].first]+=dp[last[a[i]]][j].second;
		}
	}
	for(int i=1;i<=m;i++) cout<<ans[i]<<' ';
	return 0;
} 
