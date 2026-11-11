#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=2e6+26;
int c,t;
int n,d;
ll x[N];
ll dp[N];
ll ans=0;
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--){
		ans=0;
		cin>>n>>d;
		for(int i=1;i<=n;i++){
			cin>>x[i];
		}
		
		int num=0;
		for(int k=1;k<=n;k++){
			dp[k]=0;
			for(int i=k+1;i<=n;i++){
				num=0;
				if(x[i]-x[i-1]>d){
					dp[i]=0;
				}
				else{
					dp[i]=dp[i-1]+1;
					for(int j=i-1;j>=k;j--){
						if(x[i]-x[j]>d){
							break;
						}
						if(dp[j]+1<dp[i]){
							dp[i]=dp[j]+1;
							num=1;
						}
						else if(dp[j]+1==dp[i]){
							num++;
//							cout<<'b'<<dp[i]<<' '<<dp[j]<<'\n';
						}
					}
//					cout<<dp[i]<<'\n';
					if(num==2){
//						cout<<'a'<<k<<' '<<i<<'\n';
						ans++;
					}
				}
			}
		}
		
		cout<<ans<<'\n';
		ans=0;
	}
	
	return 0;
}
