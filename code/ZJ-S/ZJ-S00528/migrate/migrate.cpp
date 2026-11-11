#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll x[2000005];
int dp[2000005],f[2000005];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int c,T;
	cin>>c>>T;
	while(T--){
		int n,res=0;
		ll d;
		cin>>n>>d;
		for(int i=1;i<=n;i++){
			cin>>x[i];
		}
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				dp[j] = 2e9;
				f[j] = 1;
			}
			dp[i] = 0;
			f[i] = 1;
			for(int j=i+1;j<=n;j++){
				for(int k=j-1;k>=i&&x[j]-x[k]<=d;k--){
					if(dp[j]>dp[k]+1){
						dp[j] = dp[k]+1;
						f[j] = f[k];
					}else if(dp[j]==dp[k]+1){
						f[j]+=f[k];
					}
				}
				if(f[j]==2){
					res++;
				}
			}
		}
		cout<<res<<'\n';
	}
	return 0;
}
