#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll inf=1e18;
int c,t;
int n;
ll d;
ll x[2000010];
ll dp[301][301];
ll cnt[301][301];
bool judgeA(){
	ll dd=x[2]-x[1];
	for(int i=2;i<=n;i++){
		if(x[i]-x[i-1]!=dd){
			return 0;
		}
	}
	return 1;
}
int main(){
	freopen("migrate1.in","r",stdin);
	//freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>c>>t;
	while(t--){
		cin>>n>>d;
		for(int i=1;i<=n;i++){
			cin>>x[i];
		}
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				dp[i][j]=inf;
				cnt[i][j]=0;
			}
			dp[i][i]=0;
		} 
		if(judgeA()){
			ll dd=x[2]-x[1];
			ll ans=0;
			for(ll i=1;i<=n-1;i++){
				if(d/dd==0){
					continue;
				}
				if(i%(d/dd)!=0){
					ans+=n-i;
				}
			}
			cout<<ans<<'\n';
			continue;
		}else if(n<=300){
			ll ans=0;
			for(int u=1;u<=n;u++){
				for(int v=1;v<u;v++){
					for(int k=v;k<u;k++){
						if(x[u]-x[k]<=d){
							if(dp[v][k]+1<dp[v][u]){
								dp[v][u]=dp[v][k]+1;
								cnt[v][u]=1;
							}else if(dp[v][k]+1==dp[v][u]){
								cnt[v][u]++;
							}
						}
					}
				}
			}
			for(int i=1;i<=n;i++){
				for(int j=i+1;j<=n;j++){
					if(cnt[i][j]==2){
						ans++;
					}
				}
			}
			cout<<ans<<'\n';
		}
	}
	return 0;
}
