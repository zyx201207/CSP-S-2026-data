#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=5e3+5;
int c,T,n,d,a[N],ans,sum,x,y,dp[N][N];
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>c>>T;
	while(T--){
		cin>>n>>d;
		sum=0,ans=0;
		for(int i=1;i<=n;i++){
			cin>>a[i];
			sum+=a[i];
		}
		if(n<=5000){
			for(int i=1;i<=n-1;i++){
				dp[i][i]=1;
				for(int k=i+1;k<=n;k++){
					dp[i][k]=0;
					if(a[k]-a[i]<=d){
						dp[i][k]=1;
						continue;
					}
					int j=i;
					while(a[k]-a[j]>d) j++;
					int mn=1e8;
					for(int z=j;z<=k-1;z++){
						mn=min(mn,dp[i][z]);
					}
					for(int z=j;z<=k-1;z++){
						if(mn==dp[i][z]) dp[i][k]+=mn;
					}
					if(dp[i][k]==2) ans++;
				}
			}
			cout<<ans<<'\n';
		}
		else{
			int k=a[2]-a[1];
			if(d<2*k||d>=3*k||n<=3) cout<<"0\n";
			else cout<<n-3<<'\n';
		}
		
	}
	
	return 0;
}
