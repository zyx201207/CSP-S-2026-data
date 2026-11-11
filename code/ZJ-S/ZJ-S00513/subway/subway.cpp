#include<bits/stdc++.h>
#define ll long long
using namespace std;
const ll N=5e3+10,M=5e5+10;;
ll c,n,m,d,q,w[M],k[M],a[N][N],t[N][N],ans,vis[M];
void dfs(ll nw,ll te,ll num,ll e,bool f){
	if(te>=ans || nw>e) return;
	if(nw==e){
		ans=min(ans,te+t[num][nw]);
		return;
	}
	for(ll i=1;i<=n;i++){
		for(ll j=1;j<=k[i];j++){
			if(nw==a[i][j]){
				if(i!=num){
					if(vis[a[i][j+1]]==0){
						vis[a[i][j+1]]=1;
						dfs(a[i][j+1],te+t[num][a[i][j+1]]+t[i][a[i][j+1]],i,e,0);
						vis[a[i][j+1]]=0;
					}
					if(vis[a[i][j-1]]==0){
						vis[a[i][j-1]]=1;
						dfs(a[i][j-1],te+t[num][a[i][j-1]]+t[i][a[i][j-1]],i,e,0);
						vis[a[i][j-1]]=0;
					}
				}
				else{
					if(vis[a[i][j+1]]==0){
						vis[a[i][j+1]]=1;
						if(f) dfs(a[i][j+1],te+t[i][a[i][j+1]],i,e,0);
						else dfs(a[i][j+1],te,i,e,1);
						vis[a[i][j+1]]=0;
					}
					if(vis[a[i][j-1]]==0){
						vis[a[i][j-1]]=1;
						if(f) dfs(a[i][j-1],te+t[i][a[i][j-1]],i,e,0);
						else dfs(a[i][j-1],te,i,e,1);
						vis[a[i][j-1]]=0;
					}
				}
			}
		}
	}
}
int main(){
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(ll i=1;i<=m;i++) cin>>w[i];
	for(ll i=1;i<=n;i++){
		cin>>k[i];
		for(ll j=1;j<=k[i];j++) cin>>a[i][j]>>t[i][j];
	}
	for(ll i=1;i<=q;i++){
		memset(vis,0,sizeof vis);
		ll x,y;
		ans=LLONG_MAX;
		cin>>x>>y;
		vis[x]=1;
		dfs(x,0,0,y,1);
		vis[x]=0;
		cout<<ans+w[x]+w[y]<<"\n";
	}
	return 0;
}
