#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N=1e5+5;
int n,m,a[N],dp[N],vis[N],sum,cnt,p;
signed main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	int num=0;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]>sum){
			num=i;
			sum=a[i];
		}
		if(i==1){
			p=a[1];
		}
		else
		{
			p&=a[i];
		}
	}
	if(m==1){
		cout<<sum;
		return 0;
	}
	else if(m==2){
		int ans=0;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n&&j!=i;j++){
				ans=max(ans,a[i]&a[j]);
			}
		}
		cout<<ans;
		return 0;
	}
	else if(n==m){
		cout<<p<<endl;
		return 0;
	}
	dp[1]=sum;
	vis[num]=1;
	for(int i=2;i<=m;i++){
		dp[i]=0,cnt=0;
		for(int j=1;j<=n;j++){
			if(vis[j]==0){
				if((dp[i-1]&a[j])>dp[i]){
					cnt=j;
					dp[i]=dp[i-1]&a[j];
				}
			}
		}
		vis[cnt]=1;
	}
	cout<<dp[m]<<endl;
	return 0;
}
