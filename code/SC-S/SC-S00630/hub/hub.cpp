#include<bits/stdc++.h>
#define LL long long
#define For(i,a,b)	for(int i=a;i<=b;i++)
#define Rep(i,a,b)	for(int i=a;i>=b;i--)
using namespace std;
const int N=2e6+5;
const int inf=1e9;
int c,T,n,k,vis[N],dp[N],res,ans,tot;
vector<int> G[N];
void dfs(int u,int f){
	if(vis[u]){
		dp[u]=0;
		if(!vis[f])	tot++;
	}else dp[u]=dp[f]+1;
	for(auto v:G[u]){
		if(v==f)	continue;
		dfs(v,u);
		dp[u]=min(dp[u],dp[v]+1);
	}
	res=max(res,dp[u]);
}
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin>>c>>T;
	while(T--){
		cin>>n>>k;ans=inf;
		For(i,1,n)	G[i].clear();
		For(i,1,n-1){
			int u,v;
			cin>>u>>v;
			G[u].push_back(v);
			G[v].push_back(u);
		}
		if(c<=3){
			for(int i=0;i<(1<<n);i++){
				int cnt=0;res=0;
				for(int j=0;j<n;j++){
					dp[j+1]=inf;
					vis[j+1]=0;
					if(i&(1<<j)){
						vis[j+1]=1;
						cnt++;
					}
				}
				if(cnt!=k)	continue;
				dp[0]=inf,tot=0;
				dfs(1,0);
				if(tot<=2){
					ans=min(ans,res);
//					cout<<ans<<" "<<i<<"\n";
				}	
			}
			cout<<ans<<"\n";
		}else if(c==13||c==14){
			int m=n/2;
			if(m%2==0){
				if(k%2==0){
					ans=(n-m-m/2-k/2)/2+1;
				}else{
					ans=(m/2-k/2)/2+1+(m/2-k/2)%2;
				}
			}else{
				if(k%2==0){
					ans=((n-m)/2-k/2)/2+1+((n-m)/2-k/2)%2;
				}else{
					ans=(m/2-k/2)/2+1;
				}
			}
			cout<<ans<<"\n";
		}
	}
	return 0;
}