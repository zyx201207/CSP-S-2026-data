#include<bits/stdc++.h>
using namespace std;
const int N=2e5+3;
long long a[N],k;
long long dp[2003][2003];
bool cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	k=1;
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		
	}
	sort(a+1,a+n+1,cmp);
	for(int i=1;i<=n;i++){
		dp[0][i]=a[i];
		if(dp[1][i-1]<a[i]){
			k=i;
			dp[1][i]=a[i];
		}else{
			dp[1][i]=dp[1][i-1];
		}
	}
	for(int i=2;i<=m;i++){
		for(int j=1;j<=n;j++){
			if(k==j){
				
				dp[i][j]=dp[i][j-1];
			
				continue;
			}
			long long f=dp[i-1][j]&a[j];
			if(dp[i][j-1]<f){
				dp[i][j]=f;
				if(j>k)k=j;
			}else{
				dp[i][j]=dp[i][j-1];
			}
		}
	}
    cout<<dp[m][n];
	return 0;
}
