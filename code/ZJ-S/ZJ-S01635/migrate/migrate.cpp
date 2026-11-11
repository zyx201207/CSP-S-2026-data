#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=2e6+10;
int a[N],b[N];
int dp[5010][5010];
int ans[N];
int n,d;
bool check1(){
	for(int i=1;i<n-1;i++){
		if(b[i]!=b[i+1])return 0;
	}
	return 1;
}
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,t;
	cin>>c>>t;
	while(t--){
		cin>>n>>d;
		for(int i=1;i<=n;i++){
			cin>>a[i];
		}
		for(int i=1;i<n;i++){
			b[i]=a[i+1]-a[i];
			//cout<<b[i]<<" ";
		}
		if(check1()){
			if(2*b[1]>d){
				cout<<"0\n";
				continue;
			}
			int p=d/b[1];
			int ans=max(0ll,n-(2*p-1));
			cout<<ans<<"\n";
		}
		else{
			for(int i=1;i<=n;i++){
				ans[i]=0;
				for(int j=1;j<=n;j++)dp[i][j]=1e9;
			}
			for(int i=1;i<n;i++){
				int sum=0;
				dp[i][i-1]=1;
				for(int j=i;j<n;j++){
					if(sum+b[j]>d){
						if(b[j]<=d)dp[i][j]=dp[i][j-1]+1;
						else break;
						sum=0;
					}
					else dp[i][j]=dp[i][j-1];
					sum+=b[j];	
				}
			}
			int ret=0;
			//cout<<dp[1][2]<<" "<<dp[3][3]<<" "<<dp[1][3]<<"\n";
			for(int i=1;i<n;i++){
				for(int j=i;j<n;j++){
					int cnt=0;
					for(int k=i;k<j;k++){
						if(dp[i][k]+dp[k+1][j]==dp[i][j]){
							cnt++;
						}
					}
					cnt-=dp[i][j]-1;
					if(cnt==1)ret++;
				}
			}
			cout<<ret<<"\n";
		}
	}
	return 0;
}