#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q;
int w[500005],k[505],a[500005][21],fa[10000005],o[500005];
long long t[10000005],dp[501][501];
bool pp[501][501];
vector<int> ed[501];
void dfs(int x,int y){
	if(pp[x][y]) return ;
	pp[x][y]=pp[y][x]=1;
	for(auto v:ed[x]){
		dfs(v,y);
		if(!dp[x][y]) dp[x][y]=dp[x][v]+dp[v][y];
		dp[x][y]=min(dp[x][y],dp[x][v]+dp[v][y]);
	}
	dp[y][x]=dp[x][y];
}
void dij(){
	for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++){
			dfs(i,j);
		}
	}
	return ;
}
long long fid(int x,int y){
	long long ans=0;
	for(int i=1;i<=o[x];i++){
		for(int j=1;j<=o[y];j++){
			int p=a[x][i],q=a[y][j];
			if(fa[p]==fa[q]) return t[p]+t[q];
			if(!ans){
				ans=dp[fa[p]][fa[q]]+t[p]+t[q];
			}
			ans=min(dp[fa[p]][fa[q]]+t[p]+t[q],ans);
		}
	}
	return ans; 
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		scanf("%d",&w[i]);
	}
	int A,T,M=m;
	for(int i=1;i<=n;i++){
		scanf("%d",&k[i]);
		for(int j=1;j<=k[i];j++){
		scanf("%d %d",&A,&T);
			o[A]++;
			a[A][o[A]]=++M;
			t[M]=T;
			fa[M]=i;
		}
	}
	for(int i=1;i<=m;i++){
		if(o[i]>1) for(int p=1;p<o[i];p++)
			for(int q=p+1;q<=o[i];q++){
				int x=a[i][p],y=a[i][q];
				if(dp[fa[x]][fa[y]]){
					dp[fa[x]][fa[y]]=min(dp[fa[x]][fa[y]],(t[x]+t[y]));
				}
				dp[fa[x]][fa[y]]=t[x]+t[y];
			}
		}
	for(int i=1;i<n;i++){
		for(int j=i+1;j<=n;j++){
			if(dp[i][j]){
				dp[j][i]=dp[i][j];
				ed[i].push_back(j);
				ed[j].push_back(i);
			}
		}
	}
	dij();
	/*for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++){
			cout<<dp[i][j]<<endl;
		}
	}*/
	int x,y;
	for(int i=1;i<=q;i++){
		scanf("%d %d",&x,&y);
		printf("%lld\n",w[x]+w[y]+fid(x,y));
	}
	return 0;
}
