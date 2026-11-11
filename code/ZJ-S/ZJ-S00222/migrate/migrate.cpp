#include<bits/stdc++.h>
using namespace std;
long long c,T,n,d,a[2000005],dis[405],dp[405],tot,su,book[405],ans;
void dijstra(int x){
	
	for(int i=1;i<=n;++i){
		book[i]=0LL;
		dis[i]=1000000000000000001LL;
	}
	dis[x]=0;
	dp[x]=1;
	for(int i=1;i<=n;++i){
		long long mi=1000000000000000000LL,wei=-1;
		for(int j=1;j<=n;++j){
			if(dis[j]<mi&&!book[j]){
				wei=j;
				mi=dis[j];
			}
		}
		if(wei==-1){
			return;
		}
		book[wei]=1;
		if(dp[wei]==2){
			++ans;
		}
		for(int j=1;j<=n;++j){
			if(book[j]) continue;
			if(abs(a[j]-a[wei])>d) continue;
			if(dis[j]>(dis[wei]+1)){
				dis[j]=dis[wei]+1;
				dp[j]=dp[wei];
			}else if(dis[j]==(dis[wei]+1)){
				if(dp[j]==-1||dp[wei]==-1){
					dp[j]==-1;
				}else{
					dp[j]+=dp[wei];
					if(dp[j]>=3){
						dp[j]=-1;
					}
				}
			}
		}
	}
}
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>T;
	while(T--){
		cin>>n>>d;
		su+=n;
		for(int i=1;i<=n;++i){
			cin>>a[i];
		}
		ans=0;
		if(n<=300&&su<=300){
			for(int i=1;i<=n;++i){
				dijstra(i);
			}
			cout<<ans/2<<'\n';
		}else{
			long long cha=a[2]-a[1];
			if(cha>d){
				cout<<"0\n";
				continue;
			}
			int ma=d/cha;
			for(int i=1;i<n;++i){
				int mi=(i+ma-1)/ma;
				int tt=(mi*ma)-i;
				if(mi!=1&&ma!=1&&mi==2&&tt==1){
					ans=ans+n-i;
				}
			}
			cout<<ans<<'\n';
		}
	}
}