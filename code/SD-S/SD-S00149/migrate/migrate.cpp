#include<bits/stdc++.h>
using namespace std;
#define N 2000005
#define int long long 
int n,d,a[N],dp[N],f[N],ans;
void solve(){
	ans=0;
	cin>>n>>d;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++) {
			dp[j]=0x3f3f3f3f;
			f[j]=0;
		}
		dp[i]=0;
		f[i]=1;
		for(int j=i+1;j<=n;j++){
			for(int k=i;k<=j-1;k++){
				if(a[j]-a[k]<=d){
					if(dp[k]+1<dp[j]){
						dp[j]=dp[k]+1;
						f[j]+=f[k];
					}
					else if(dp[k]+1==dp[j]){
						f[j]+=f[k];
					}
				}
			}
		}
	    
		for(int j=i;j<=n;j++) ans=ans+(f[j]==2);
	}
	cout<<ans<<'\n';
}
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
    int c,t;
    cin>>c>>t;
    while(t--){
    	solve();
	}
	return 0;
}

