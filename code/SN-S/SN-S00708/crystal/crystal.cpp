#include<bits/stdc++.h>
using namespace std;
int n;
long long m;
long long a[500005];
long long pre[500005];
long long dp[500005];
int cnt;
long long ans,pos;
int maxx;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		dp[i]=dp[i-1]+(a[i]-a[i-1])*(i-1);
	}
	int l=1;
	for(int i=1;i<=n;i++){
		if(dp[i]-ans-dp[l-1]<=m){
			cnt++;
		}else{
			while(dp[i]-ans-dp[l-1]>m&&cnt!=1){
				l++;
				if(pos==0){
					ans+=dp[l-1]*(i-1);
					pos+=dp[l-1]; 
				}else{
					pos+=dp[l-1];
				}
				cnt--;
			}
			cnt++;
		}
		ans+=pos;
		maxx=max(maxx,cnt);
	}
	cout<<maxx;
	return 0;
}

