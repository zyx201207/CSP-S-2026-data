#include<bits/stdc++.h>
using namespace std;
long long c,t,n,k,u,v,fa[1000010][25],dp[1000010],ans[1000010],vis[1000010],vs[1000010],afa;
vector<long long> e[1000010];
void dfs(long long u,long long f){
	dp[u]=dp[f]+1;
	fa[u][0]=f;
	for(long long v:e[u]){
		if(v==f) continue;
		dfs(v,u);
	}
	return ;
}
long long lca(long long x,long long y){
	if(dp[x]<dp[y]) swap(x,y);
	for(long long i=20;i>=0;i--){
		if(dp[fa[x][i]]>=dp[y]){
			x=fa[x][i];
		}
	}
	if(x==y) return x;
	for(long long i=20;i>=0;i--){
		if(fa[x][i]!=fa[y][i]){
			x=fa[x][i];
			y=fa[y][i];
		}
	}
	return fa[x][0];
}
void check(long long u,long long f){
	for(long long v:e[u]){
		if(v==f||!vs[v]||vis[v]) continue;
		vis[v]=1;
		check(v,u);
	}
	return ;
}
void ms(long long st,long long l){
	if(l>k){
		int cnt=0;
		for(long long i=1;i<=n;i++) vis[i]=0;
		for(long long i=1;i<=k;i++){
			if(!vis[ans[i]]){
				vis[ans[i]]=1;
				check(ans[i],0);
				cnt++;
				if(cnt>2) break;
			}
		}
		if(cnt<=2){
			long long num=0;
			for(long long i=1;i<=n;i++){
				if(vs[i]) continue;
				long long res=0x3f3f3f3f3f3f3f3f;
				for(long long j=1;j<=k;j++){
					res=min(res,dp[i]+dp[ans[j]]-2*dp[lca(i,ans[j])]);
				}
				num=max(res,num);
			}
			afa=min(num,afa);
		}
		return ;
	}
	for(long long i=st;i<=n;i++){
		ans[l]=i;
		vs[i]=1;
		ms(i+1,l+1);
		vs[i]=0;
	}
}
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>c>>t;
	while(t--){
		afa=0x3f3f3f3f3f3f3f3f;
		cin>>n>>k;
		for(long long i=1;i<=n;i++){
			e[i].clear();
			dp[i]=fa[i][0]=i;
		}
		for(long long i=1;i<=n-1;i++){
			cin>>u>>v;
			e[u].push_back(v);
			e[v].push_back(u);
		}
		dfs(1,0);
		for(long long j=1;j<=20;j++){
			for(long long i=1;i<=n;i++){
				fa[i][j]=fa[fa[i][j-1]][j-1];
			}
		}
		ms(1,1);
		cout<<afa<<"\n";
	}
	return 0;
}