#include<bits/stdc++.h>
using namespace std;
//#define int long long 
//#define lowbit(x) ((x)&(-(x)))
//#define pnt pair<int,int> 
bool MS;
vector<int>e[1000001];
int ff[21][1000001],dep[1000001],fa[1000001];
int find(int x){
	return fa[x]==x?x:fa[x]=find(fa[x]);
}
void dfs(int u,int pa){
	ff[0][u]=pa;
	for(int v:e[u]){
		if(v==pa)continue;
		dep[v]=dep[u]+1;
		dfs(v,u);
	}
}
int lca(int u,int v){
	if(dep[u]<dep[v])swap(u,v);
	for(int i=20;i>=0;i--){
		if(dep[ff[i][u]]>=dep[v])u=ff[i][u];
	}
	if(u==v)return u;
	for(int i=20;i>=0;i--){
		if(ff[i][u]!=ff[i][v]){
			u=ff[i][u];
			v=ff[i][v];
		}
	}
	return ff[0][u];
}
int a[1000001],d[1005][1005];
void solve(){
	int n,K;
	scanf("%d %d",&n,&K);
	for(int i=1;i<=n-1;i++){
		int u,v;
		scanf("%d %d",&u,&v);
		e[u].push_back(v);
		e[v].push_back(u);
	}
	if(n<=10){
		dfs(1,0);
		for(int i=1;i<=20;i++){
			for(int j=1;j<=n;j++){
				ff[i][j]=ff[i-1][ff[i-1][j]];
			}
		}
		int ans=1e9;
		for(int i=0;i<=(1<<n)-1;i++){
			int cnt=__builtin_popcount(i);
			if(cnt!=K)continue;
			for(int j=1;j<=n;j++){
				fa[j]=j;
			}
			for(int j=1;j<=n;j++){
				if((1<<(j-1))&i){
					a[j]=1;
				}else a[j]=0;
			}
			for(int j=1;j<=n;j++){
				if(a[j]==1){
					for(int v:e[j]){
						if(a[v]!=1)continue;
						if(find(j)!=find(v)){
							fa[find(j)]=find(v);
							cnt--;
						}
//					if(i==262){
//						printf("---%d %d\n",j,v);
//					}
					}
				}
			}
			if(cnt>2)continue;
			int maxx=0;
			for(int j=1;j<=n;j++){
				int res=1e9;
				for(int k=1;k<=n;k++){
					if(a[k]==1){
						res=min(res,dep[j]+dep[k]-2*dep[lca(j,k)]);
					}
				}
//			printf("%d %d %d\n",i,j,res);
				maxx=max(maxx,res);
			}
//		if(maxx==1){
//			for(int j=1;j<=n;j++){
//				printf("%d ",a[j]);
//			}
//			printf("%d\n",i);
//			puts("");
//		}
			ans=min(ans,maxx);
		}
		printf("%d\n",ans);
		for(int i=1;i<=n;i++){
			dep[i]=0;
			fa[i]=i;a[i]=0;
			for(int j=0;j<=20;j++){
				ff[j][i]=0;
			}
			e[i].clear();
		}
	}else if(K==2){
		for(int i=1;i<=n;i++){
			dep[i]=0;
			dfs(i,0);
			for(int j=1;j<=n;j++){
				d[i][j]=dep[j];
			}
		}
		int ans=1e9;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				int res=0;
				for(int k=1;k<=n;k++){
//					printf("%d %d %d\n",j,k,d[j][k]);
//					if(i==2&&j==4){
//						printf("%d %d\n",min(d[i][k],d[j][k]));
//					}
					res=max(res,min(d[i][k],d[j][k]));
				}
				ans=min(ans,res);
			}
		}
		for(int i=1;i<=n;i++)for(int j=1;j<=n;j++)d[i][j]=0;
		printf("%d\n",ans);
		for(int i=1;i<=n;i++){
			dep[i]=0;
			fa[i]=i;a[i]=0;
			for(int j=0;j<=20;j++){
				ff[j][i]=0;
			}
			e[i].clear();
		}
	}
}
bool MT;
signed main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
//	ios::sync_with_stdio(0);
//	cin.tie(0);cout.tie(0);
	int T=1,c=0;
	scanf("%d %d",&c,&T);
//	cin>>T;
	while(T--)solve();
//	cerr<<((&MS)-(&MT))/(1024.0*1024.0)<<" MB\n"<<clock()/1000.0<<"s Time";
}
/*
0 1
5 2
1 2
2 3
3 4
4 5
10 3
1 2
1 3
2 4
2 5
3 6
3 7
3 8
7 9
9 10
*/