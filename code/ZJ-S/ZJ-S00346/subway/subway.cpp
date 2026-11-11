#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll c,n,m,d,q,w[500005],k[505],vis[500005],a[505][20005],t[505][20005],ans;
vector<ll>subb[500005];
void dfs(ll u,ll v,ll sum,ll lines){
	//cout<<u<<" "<<v<<" "<<sum<<" "<<lines<<"\n";
	vis[u]=1;
	if(u==v){
		ans=min(ans,sum+t[lines][u]);return ;
	}
	for(int i=0;i<subb[u].size();i++){
		ll tot=0;
		if(!lines)tot=t[subb[u][i]][u];
		else if(lines!=subb[u][i])tot=t[lines][u]+t[subb[u][i]][u];
		else continue;
		for(int j=1;j<=k[subb[u][i]];j++){
			if(subb[a[subb[u][i]][j]].size()==1&&a[subb[u][i]][j]!=v)continue;
			if(!vis[a[subb[u][i]][j]])dfs(a[subb[u][i]][j],v,sum+tot,subb[u][i]),vis[a[subb[u][i]][j]]=0;
		}
	}
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	scanf("%lld%lld%lld%lld%lld",&c,&n,&m,&d,&q);
	for(int i=1;i<=m;i++)scanf("%lld",&w[i]);
	for(int i=1;i<=n;i++){
		scanf("%lld",&k[i]);
		for(int j=1;j<=k[i];j++){
			scanf("%lld",&a[i][j]);scanf("%lld",&t[i][a[i][j]]);
			subb[a[i][j]].push_back(i);
		}
	}
	for(int i=1,x,y;i<=q;i++){
		ans=1e18;
		scanf("%d%d",&x,&y);
		memset(vis,0,sizeof(vis));
		dfs(x,y,0,0);
		printf("%lld\n",ans+w[x]+w[y]);
	}//16:53 60pts
	return 0;
}
//15:50 eat chocolate*1
//guess:green+
