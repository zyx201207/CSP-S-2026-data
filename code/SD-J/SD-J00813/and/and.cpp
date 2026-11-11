#include<bits/stdc++.h> 
using namespace std;
const int N=2E5+5;
int num[N];
const int M=2E3+5;
int dp[M][25];
int pre[N],nxt[N];
int ans=0;
int n,m;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for (int i=1;i<=n;i++){
		cin>>num[i];
	}
	if (n<=20){
		int ans=0;
		for (int i=1;i<=n;i++){
			dp[i][1]=num[i];
		}
		for (int i=2;i<=n;i++){
			for (int j=1;j<i;j++){
				for (int k=2;k<=min(i,m);k++){
					dp[i][k]=max(dp[i][k],dp[j][k-1]&num[i]);
				}
			}
			if (i>=m){
				ans=max(dp[i][m],ans);
			}
		}
		cout<<ans;
		return 0;
	}
	if (n<=2000){
		if (m==n){
			int ans=num[1];
			for (int i=2;i<=n;i++){
				ans=ans&num[i];
			}
			cout<<ans;
			return 0;
		}
		if (m==1){
			int ans=0;
			for (int i=1;i<=n;i++){
				ans=max(ans,num[i]);
			}
			cout<<ans;
			return 0;
		}
		if (m==2){
			int ans=0;
			for (int i=2;i<=n;i++){
				for (int j=1;j<i;j++){
					ans=max(ans,num[i]&num[j]);
				}
			}
			cout<<ans;
			return 0;
		}
	}
	else{
		if (m==n-1){
			int ans=0;
			pre[1]=num[1];
			nxt[n]=num[n];
			for (int i=2;i<=n;i++){
				pre[i]=pre[i-1]&num[i];
			}
			for (int i=n-1;i>=1;i--){
				nxt[i]=nxt[i+1]&num[i];
			}
			for (int i=1;i<=n;i++){
				ans=max(ans,pre[i-1]&nxt[i+1]);
			}
			cout<<ans;
			return 0;
		}
		int ans=0;
		for (int i=1;i<=n;i++){
			ans=max(ans,num[i]);
		}
		cout<<ans;
	}
	return 0;
}
