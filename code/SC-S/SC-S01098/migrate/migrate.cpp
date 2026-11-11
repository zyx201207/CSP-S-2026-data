#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=5005,inf=0x3f3f3f3f3f3f3f3f;
int c,T,n,d,x[N],m,f[N][N],cnt,ans,mn,tmp,dp[N][N];
//f[i][j]:从 j -> i的最短路径 
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>T;
	while(T--){
		cin>>n>>d;
		m=0;
		ans=0;
		for(int i=1;i<=n;i++)
			cin>>x[i];
		memset(f,0x3f,sizeof(f));
		memset(dp,0,sizeof(dp));
		f[1][0]=0;
		for(int i=2;i<=n;i++){
			for(int j=i-1;j>=1;j--){
				if(x[i]-x[j]>d) break;
				if(f[i][j]==1) dp[i][j]++;
				else{
					f[i][j]=1;
					dp[i][j]=1;
				}
				for(int k=j-1;k>=1;k--){
					if(f[j][k]==inf) continue;
					tmp=f[j][k]+1;
					if(tmp<=f[i][k]){
						if(tmp<f[i][k]){
							f[i][k]=tmp;
							dp[i][k]=0;
						}
						dp[i][k]++;
					}
				}
			}
		}
		for(int i=1;i<=n;i++){
			for(int j=1;j<i;j++){
				if(dp[i][j]==2) {
//					cout<<i<<" "<<j<<'\n';
					ans++;
				}
			}
		}
		cout<<ans<<'\n';
	}
	return 0;
}