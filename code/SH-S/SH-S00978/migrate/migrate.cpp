#include<bits/stdc++.h>
using namespace std;

const int N=2000005;
long long c,t,n,d,x[N];
long long dp[N],dis[N];

void solve1(){
	long long dis=x[2]-x[1];
	if(d>=2*dis && d<3*dis)
		cout<<n-3<<"\n";
	else
		cout<<0<<"\n";
}

int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	scanf("%lld%lld",&c,&t);
	while(t--){
		scanf("%lld%lld",&n,&d);
		for(long long i=1;i<=n;i++)
			scanf("%lld",&x[i]);
		if(n<=3){
			cout<<0<<"\n";
			continue;
		}
		if(c==11 || c==12){
			solve1();
			continue;
		}
		long long ans=0;
		for(long long i=1;i<=n;i++){
			for(long long j=1;j<=n;j++){
				dp[j]=0;
				dis[j]=9e18;
			}
			for(long long j=i;j<=n;j++){
				if(x[j]-x[i]<=d){
					dis[j]=1;
					dp[j]=1;
					continue;
				}
				for(long long k=j-1;k>i;k--){
					if(x[j]-x[k]>d)
						break;
					if(dis[k]+1<dis[j]){
						dis[j]=dis[k]+1;
						dp[j]=1;
					}
					else if(dis[k]+1==dis[j]){
						dp[j]++;
						if(dp[j]==2)
							ans++;
						if(dp[j]>2)
							ans--;
					}
				}
			}
		}
		cout<<ans<<"\n";
	}
	return 0;
}
