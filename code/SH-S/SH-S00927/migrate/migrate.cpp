#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
const ll N=2e6+5,INF=1000000000000000000;
ll c,t,n,vis[N],cache;
ull d,ans,now,a[N],dp[N];
void init(int start){
	now=0;
	for(int i=1;i<=n;i++){
		dp[i]=INF;
		vis[i]=0;
	}
	dp[start]=0;
}
ull solve(int u){
	ull ret=0;
	for(int i=u;i<=n;i++){
		dp[i]=INF;
		vis[i]=0;
	}
	dp[u]=vis[u]=1;
	for(int i=u;i<=n;i++){
		if(vis[i]==2) ret++;
		for(int j=i+1;j<=n;j++){
			if(a[j]-a[i]<=d){
				if(dp[i]<dp[j]){
					dp[j]=dp[i]+1;
					vis[j]+=vis[i];
				}
			}else break;
		}
	}
	return ret;
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
    cin>>c>>t;
    for(int T=1;T<=t;T++){
    	cin>>n>>d;
    	for(int i=1;i<=n;i++){
    		cin>>cache;
    		a[i]=INF;
    		a[i]+=cache;
		}
    	ans=0;
    	for(int i=1;i<n;i++){
    		ans+=solve(i);
		}
		cout<<ans<<endl;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
