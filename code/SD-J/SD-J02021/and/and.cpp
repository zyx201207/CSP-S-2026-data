#include<bits/stdc++.h>
using namespace std;
long long maxn,n,m,a[2005],dp[2005][2005],dna;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie();
	cout.tie();
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}sort(a+1,a+1+n,greater<long long>());
	long long minn=a[1];
	for(int i=1;i<=20;i++){
		for(int j=1;j<=20;j++){
			dp[i][j]=minn;	
		}
	}
	if(m==1){
		cout<<a[1];
	}else if(m==n){
		dna=a[1];
		for(int i=2;i<=n;i++){
			dna&=a[i];
		}cout<<dna;
	}else if(m==2){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				if(j==i)continue;
				maxn=max(maxn,a[i]&a[j]);
			}
		}cout<<maxn;
	}else if(n<=20&&m<=20){
		for(int i=3;i<=n;i++){
			dp[i][1]=max(dp[i-1][1],a[i]);
			dp[i][i]=dp[i-1][i-1]&a[i];
			for(int j=2;j<i;j++){
				dp[i][j]=max(dp[i-1][j],a[j-1]&a[j]);
			}
		}cout<<dp[n][m];
	}
	return 0;
}
