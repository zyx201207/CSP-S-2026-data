#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("crysral.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int n;long long m;cin>>n>>m;
	long long a[n+1]={0};
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	long long b[n+1]={0};
	for(int i=1;i<n;i++){
		b[i]=a[i+1]-a[i];//cout<<b[i]<<" ";
	}//cout<<endl;
	long long dp[n+1][n+1];
	for(int i=1;i<n;i++){
		dp[i][i]=0;
	}
	dp[n][n]=0;
	for(int i=1;i<n;i++){
		for(int j=1;j+i<=n;j++){
			dp[i][i+j]=dp[i][i+j-1]+b[i+j-1];
		}
	}
	long long lans=0;int ans=0,ansr=0;
	for(int j=1;j<=n;j++){
		for(int i=j;i>=1;i--){
			if((lans+dp[i][j])<=m){
				lans=lans+dp[i][j],ansr++;//cout<<"b";
			}else break;
		}
	//	cout<<ansr<<" "<<lans<<" ";
		ans=max(ansr,ans);
		ansr=0,lans=0;
	}
	cout<<ans;
	return 0;
}
