#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500005],cnt=1;
pair<long long,long long> dp[500005],tmp[500005];
bool flag=1,ov[500005];
bool cmp(long long x,long long y){
	return x>y;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n,cmp);
	for(int i=1;i<=n;i++){
		tmp[i].second=a[i];
	}
	for(int j=2;j<=n;j++){
		flag=0;
		for(int i=j;i<=n;i++){
			if(ov[i]==1){
				continue;
			}
			dp[i].first=tmp[i-1].second-tmp[i].second+tmp[i-1].first;
			dp[i].second=tmp[i-1].second;
			//cout<<tmp[i-1].first<<' '<<tmp[i-1].second<<' '<<tmp[i].first<<' '<<tmp[i].second<<"  ";
			if(i!=j&&dp[i].first>dp[i-1].first){
				dp[i].first=dp[i-1].first;
				dp[i].second=dp[i-1].second;
			}
			if(dp[i].first>m){
				ov[i]=1;
			}else{
				flag=1;
			}
			//cout<<dp[i].first<<' '<<dp[i].second<<"  ";
			
		}
		for(int k=j;k<=m;k++){
			tmp[k]=dp[k];
		}
		//cout<<j<<endl;
		if(flag==0){
			break;
		}else{
			cnt++;
		}
	}
	cout<<cnt;
	return 0;
}
