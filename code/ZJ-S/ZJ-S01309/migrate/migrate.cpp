#include<bits/stdc++.h>
using namespace std;
const int N=2e6+5;long long _,t,n,m,a[N],ans=0,f[N],dp[7][N];//1:1 2:2 3:22 4:21 5:11 6:211
bool ck1(){for(int i=3;i<=n;i++) if(a[i]-a[i-1]!=a[2]-a[1]) return 0;return 1;}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0),cout.tie(0);
	cin>>_>>t;while(t--){
		cin>>n>>m,ans=0;for(int i=1;i<=n;i++) cin>>a[i];
//		if(ck1()){
//			m=m/(a[2]-a[1]);if(m>1) for(int i=1;i<=n;i++) ans+=(i+m*2-1<=n);
//			cout<<ans<<"\n";continue;
//		}else if(a[n]-a[1]<=m){cout<<"0\n";continue;}
		f[0]=f[n+1]=0;for(int i=1;i<=n;i++){
			f[i]=max(1ll*i,f[i-1]);while(f[i]<n&&a[f[i]+1]-a[i]<=m) f[i]++;
//			cout<<i<<":"<<f[i]<<"\n";
		}
		for(int i=n;i>=1;i--){
			dp[1][i]=dp[2][i]=dp[3][i]=dp[4][i]=dp[5][i]=dp[6][i]=0;if(f[i]==i) continue;
			if(i+1==f[i]) dp[1][i]=dp[1][f[i]],dp[2][i]=dp[2][f[i]]+f[i]-i;
			else if(i+2==f[i]) dp[1][i]=dp[5][f[i]],dp[2][i]=dp[3][f[i]]+f[i]-i;
			else dp[1][i]=dp[6][f[i]],dp[2][i]=dp[3][f[i]]+f[i]-i;
			ans+=dp[1][i];if(i==1) continue;
			dp[3][i]=f[i]-max(f[i-1],1ll*i);if(f[i]!=f[i-1]) dp[3][i]+=dp[(i+1==f[i]?2:3)][f[i]];
			if(f[i]==f[i-1]) dp[4][i]=0;
			else if(i+1==f[i]) dp[4][i]=dp[1][f[i]];
			else if(f[i-1]+1==f[i]) dp[4][i]=dp[4][f[i]];
			else if(i+2==f[i]) dp[4][i]=dp[5][f[i]];
			else dp[4][i]=dp[6][f[i]];
			dp[5][i]=max(0ll,f[i-1]-i);
			if(i+1==f[i]) dp[5][i]+=dp[f[i-1]==f[i]?2:1][f[i]];
			else if(f[i-1]==f[i]) dp[5][i]+=dp[3][f[i]];
			else if(f[i-1]+1==f[i]) dp[5][i]+=dp[4][f[i]];
			else dp[5][i]+=dp[i+2==f[i]?5:6][f[i]];
			if(f[i-2]==f[i]) dp[6][i]=0;
			else if(i+1==f[i]) dp[6][i]=(f[i-1]==f[i]?1+dp[2][f[i]]:dp[1][f[i]]);
			else if(f[i-2]+1==f[i]) dp[6][i]=(f[i-1]==f[i]?1+dp[3][f[i]]:dp[4][f[i]]);
			else if(f[i-1]==f[i]) dp[6][i]=dp[3][f[i]]+f[i]-max(f[i-2],1ll*i);
			else if(f[i-1]+1==f[i]) dp[6][i]=dp[4][f[i]]+max(0ll,f[i-1]-max(1ll*i,f[i-2]));
			else dp[6][i]=dp[6][f[i]]+max(0ll,f[i-1]-max(1ll*i,f[i-2]));
		}
//		for(int i=1;i<=n;i++) cout<<i<<":"<<dp[1][i]<<" "<<dp[2][i]<<" "<<dp[3][i]<<" "<<dp[4][i]<<" "<<dp[5][i]<<" "<<dp[6][i]<<"\n";
		cout<<ans<<"\n";
	}
	return 0;
}
