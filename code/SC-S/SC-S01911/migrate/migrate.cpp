#include<bits/stdc++.h>
using namespace std;
#define int long long
const int MAXN=5010,N=2e6+10;
int cn,t,n,d,a[N],dp[MAXN][MAXN],g[MAXN][MAXN],c[MAXN],rx[N],ls,rs;
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>cn>>t;
	if(cn==11||cn==12){
		while(t--){
			cin>>n>>d;
			for(int i=1;i<=n;i++)cin>>a[i];
			int dx=a[2]-a[1];
			int k=d/dx;
			if(n>=2*k&&k>=2){
				cout<<n-2*k+1<<'\n';
			}
			else cout<<0<<'\n';
		}
		return 0;
	}if(cn==13||cn==14){
		while(t--){
			int tx=0,ans=0;
			cin>>n>>d;
			for(int i=1;i<=n;i++){
				cin>>a[i];
				rx[i]=n;
				if(a[i]-a[tx]>d){
					rx[tx++]=i-1;
				}
			}
			for(int i=1;i<tx;i++){
				if(rx[i]>tx){
					ans+=rx[rx[i]]-rx[i];
				}else ans+=rx[rx[i]]-rx[i]-1;
				cout<<i<<' '<<ans<<' '<<rx[i]<<' '<<rx[rx[i]]<<' '<<'\n';
			}
			cout<<ans<<'\n';
		}
		return 0;
	}
	while(t--){
		int ans=0;
		cin>>n>>d;
		for(int i=1;i<=n;i++){
			cin>>a[i];
		}	
		for(int i=1;i<=n;i++){
			int l=1,r=0;
			g[i][i]=1;
			c[++r]=i;
			for(int j=i+1;j<=n;j++){
				g[i][j]=0;
				while(l<=r&&a[j]-a[c[l]]>d)l++;
				int l2=l;
				while(dp[i][c[l2]]==dp[i][c[l]]&&l2<=r){
					dp[i][j]=dp[i][c[l2]]+1;
					g[i][j]+=g[i][c[l2]];
					l2++;
				}while(l<=r&&dp[i][c[r]]>dp[i][j])r--;
				c[++r]=j;
				if(g[i][j]==2)ans++;
			}
		}cout<<ans<<'\n';
	}

	return 0;
}
