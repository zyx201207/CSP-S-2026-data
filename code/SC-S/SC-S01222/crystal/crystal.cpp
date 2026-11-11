#include<bits/stdc++.h>
using namespace std;
const int N=5e5+10;
long long n,m,a[N]={},dp[N]={};

int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i]; 
	}
	
	if(m==0){
		long long maxn=INT_MIN;
		for(int i=1;i<=n;i++){
			dp[a[i]]++;
			maxn=max(maxn,dp[a[i]]);
		}
		cout<<maxn;
		exit(0);
	} 
	
	sort(a,a+n);
	
	long long ans=INT_MIN;
	for(int i=n;i>=1;i--){
		long long sum=0,cnt=0;
		for(int j=i;j>=1 ;j--){
			dp[j]=a[i]-a[j];
			if(sum+dp[j]<=m){
				sum+=dp[j];
				cnt++;	
			}
		}
		ans=max(ans,cnt);
		
	}
	
	cout<<ans;
	return 0;
}