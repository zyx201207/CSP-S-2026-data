#include <bits/stdc++.h>
using namespace std;
int n,m;
long long int ans;
long long int  a[20005],dp[20005];
bool cmp(int a,int b){
	return a>b;
}
int main(){
	
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	sort(a,a+n,cmp);
	ans=a[0];
	for(int i=1;i<m;i++){
		ans=ans&a[i];
	}
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			if(j!=i){
				dp[1]=max(dp[1],a[i]&a[j]);
			}
		}
	}
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			if((a[j]&a[i])==dp[1]){
				a[i]=-1;
				a[j]=-1;
			}
		}
	}
	for(int i=2;i<m;i++){
		for(int k=0;k<n;k++){
			if(a[k]!=-1){
				dp[i]=max(dp[i-1],dp[i]&a[k]);
			}
		}
		for(int k=0;k<n;k++){
			if((a[k]&dp[i-1])==dp[i]){
				a[k]=-1;
				break;
			}
		}
	}
	ans=max(ans,dp[m-1]);
	cout<<ans;
	return 0;
}