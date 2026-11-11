#include<bits/stdc++.h>
using namespace std;
int n,m;
long long a[200010];
long long dp[2010][2010];
priority_queue<long long,vector<long long>,greater<long long> > pq;
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(i==1)dp[1][1]=a[i];
		else if(i<=m)dp[i][i]=(dp[i-1][i-1]&a[i]);
	}
	if(n<=2000){
		long long zd=a[1];
		for(int i=1;i<=n;i++){
			dp[i][1]=zd;
			zd=max(zd,a[i+1]);
		}
		for(int i=2;i<=n;i++){
			for(int j=2;j<=min(m,i);j++){
				dp[i][j]=max(dp[i-1][j],(dp[i-1][j-1]&a[i]));
			}
		}
		cout<<dp[n][m];
		return 0;
	}else{
		long long ans=(1<<31)-1;
		for(int i=1;i<=n;i++){
			pq.push(ans xor a[i]);
		}
		if(m==n-1){
			cout<<ans-pq.top();
			return 0;
		}
		for(int i=1;i<=m;i++){
			ans-=(pq.top()&ans);
			pq.pop();
		}
		cout<<ans;
	}
	return 0;
}          
