#include<bits/stdc++.h>
using namespace std;
const int N=2e6+5;
long long x[N];
int dp[N],q[N],h[N],dp2[N];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,T;scanf("%d%d",&c,&T);
	while(T--){
		int n;scanf("%d",&n);
		long long b;scanf("%lld",&b);
		for(int i=0;i<=n+1;++i){
			x[i]=0;
			dp[i]=q[i]=h[i]=dp2[i]=0;
		}
		for(int i=1;i<=n;++i){
			scanf("%lld",x+i);
		}
		int k=1;
		q[1]=0;
		for(int i=2;i<=n;++i){
			while(k<=i&&x[i]-x[k]>b) ++k;
			if(i!=k) q[i]=k;
		}
		k=n;
		h[n]=0;
		for(int i=n-1;i>0;--i){
			while(k>=i&&x[k]-x[i]>b) --k;
			if(i!=k) h[i]=k;
		}
		for(int i=2;i<=n;++i){
			dp[i]=dp[q[i]];
			if(q[i]==0) continue;
			int qt=q[q[i]];
			if(q[i]!=0&&qt!=0&&x[q[i]+1]-x[qt]<=b){
				dp[i]=0;
				continue;
			}
			if(qt==0) continue;
			dp[i]+=q[q[i]+1]-qt;
		}
		for(int i=n-1;i>0;--i){
			dp2[i]=dp2[h[i]];
			if(h[i]==0) continue;
			int ht=h[h[i]];
			if(h[i]!=0&&ht!=0&&x[ht]-x[h[i]-1]<=b){
				dp2[i]=0;
				continue;
			}
			if(ht==0) continue;
			dp2[i]+=ht-h[h[i]-1];
		}
		long long ans=0;
		for(int i=2;i<=n-2;++i){
			int xt=i,yt=i+1;
		//	cout<<xt<<" "<<yt<<" "<<q[xt]<<" "<<h[xt]<<" "<<q[yt]<<" "<<h[yt]<<endl;
		//	cout<<dp[xt]<<" "<<dp2[xt]<<" "<<dp[yt]<<" "<<dp2[yt]<<endl;
			if(q[yt+1]==q[yt]||h[xt-1]==h[xt]) continue; 
			if(q[xt]==0||h[xt]==0||q[yt]==0||h[yt]==0) continue;
			if(q[xt]==q[yt]&&h[xt]==h[yt]){
				ans+=1ll*min(dp2[xt],dp2[yt])*min(dp[xt],dp[yt]);
			}
		//	cout<<ans<<endl;
			if(q[xt]==q[yt]&&(min(h[xt],h[yt])!=yt)){
				ans+=1ll*min(dp[xt],dp[yt])*(min(h[xt],h[yt])-h[xt-1]);
			}
		//	cout<<ans<<endl;
			if(h[xt]==h[yt]&&(max(q[yt],q[xt])!=xt)){
				ans+=1ll*min(dp2[xt],dp2[yt])*(q[yt+1]-max(q[xt],q[yt]));
			}
			if((min(h[xt],h[yt])!=yt)&&(max(q[yt],q[xt])!=xt))ans+=1ll*(min(h[xt],h[yt])-h[xt-1])*(q[yt+1]-max(q[xt],q[yt]));
		//	cout<<ans<<endl;
		}
		printf("%lld\n",ans);
	}
	return 0;
} 
