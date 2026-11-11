#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=5005;
int t,n,d,l,sum;
int a[N];
int num[N];
int dp[N];
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>t>>t;
	while(t--){
		cin>>n>>d;
		for(int i=1;i<=n;i++){
			cin>>a[i];
		}
		int ans=0;
		for(int i=1;i<=n;i++){
			for(int j=i;j<=n;j++){
				dp[j]=num[j]=0;
			}
			dp[i]=1;
			for(int j=i+1;j<=n;j++){
				int tmin=1e9;
				for(int k=i;k<j;k++){
					if(a[j]-a[k]<=d){
						tmin=min(tmin,num[k]);
					}
				}
				for(int k=i;k<j;k++){
					if(num[k]==tmin&&a[j]-a[k]<=d){
						dp[j]+=dp[k];
					}
				}
				ans+=(dp[j]==2);
				num[j]=tmin+1;
			} 
//			cout<<ans<<" "; 
		}
		cout<<ans<<"\n";
	}
	return 0;
}
