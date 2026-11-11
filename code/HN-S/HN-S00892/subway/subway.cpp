// #include<bits/stdc++.h>
// typedef int int32;
// #define int long long
// using namespace std;
// /*
// 作者: HN-S00892 wbw_121124(luogu uid 792595)
// drs怎么又出去了？
// 一群熟人怎么办？
// let's改一下码风？
// // freopen
// froepen是什么？

// ~~改码风还是很容易的~~

// 把"江山易改，本性难移"证伪了
// */
// const int N = 5.5e5 + 5;
// int c,n,m,d,q,cnt,b[N],fa[N],dis[N],dep[N],dp[N][20];
// struct node{
// 	int x,y,z;
// 	bool operator<(const node& u) const{
// 		return z<u.z;
// 	}
// }a[N];
// int find(int x){return x==fa[x]?x:fa[x]=find(fa[x]);}
// void unionn(int x,int y){
// 	x=find(x),y=find(y);
// 	if(x!=y)fa[x]=y;
// 	return;
// }
// vector<pair<int,int>>nbr[N];
// void pre_lca(int x,int fa){
// 	dep[x]=dep[fa]+1,dp[x][0]=fa;
// 	for(int i=1;(1<<i)<=dep[x];i++)
// 		dp[x][i]=dp[dp[x][i-1]][i-1];
// 	for(const auto&y:nbr[x]){
// 		const int&nxt=y.first,&w=y.second;
// 		if(nxt!=fa){
// 			dis[nxt]=dis[x]+w;
// 			pre_lca(nxt,x);
// 		}
// 	}
// 	return;
// }
// int lca(int x,int y){
// 	if(dis[x]>dis[y])
// 		swap(x,y);
// 	for(int i=19;i;i--)
// 		if(dis[dp[y][i]]<=dis[x])
// 			y=dp[y][i];
// 	if(x==y)return x;
// 	for(int i=19;i;i--)if(dp[x][i]!=dp[y][i]){// 压不下了:-(
// 		x=dp[x][i];
// 		y=dp[y][i];
// 	}
// 	return dp[x][0];
// }
// signed main()
// {
// 	ios::sync_with_stdio(0);
// 	cin.tie(0), cout.tie(0);
// 	// freopen("subway.in","r",stdin);
// 	// freopen("subway.out","w",stdout);
// 	cin>>c>>n>>m>>d>>q;
// 	for(int i=1;i<=n+m;i++)fa[i]=i;
// 	for(int i=1;i<=m;i++)cin>>b[i];
// 	for(int i=1;i<=n;i++){
// 		int k;
// 		cin>>k;
// 		for(int j=1;j<=k;j++){
// 			int x,y;
// 			cin>>x>>y;
// 			a[++cnt]={i+m,x,y};
// 		}
// 	}sort(a+1,a+1+cnt);
// 	for(int i=1;i<=cnt;i++)if(find(a[i].x)!=find(a[i].y)){
// 		unionn(a[i].x,a[i].y);
// 		nbr[a[i].x].push_back({a[i].y,a[i].z});
// 		nbr[a[i].y].push_back({a[i].x,a[i].z});
// 	}pre_lca(1,0);
// 	for(int i=1;i<=n+m;i++)
// 		for(auto&y:nbr[i]){
// 			const int&nxt=y.first,&w=y.second;
// 			if(i<=nxt)
// 				cerr<<'#'<<i<<"->"<<nxt<<':'<<w<<'\n';
// 		}
// 	while(q--){
// 		int x,y;
// 		cin>>x>>y;
// 		cout<<dis[x]+dis[y]-2*dis[lca(x,y)]
// 			+b[x]+b[y]<<'\n';
// 		cerr<<'@'<<x<<' '<<y<<'\n';
// 	}
// 	return 0;
// } // 伪了
#include<bits/stdc++.h>
typedef int int32;
#define int long long
using namespace std;
/*
作者: HN-S00892 wbw_121124(luogu uid 792595)
drs怎么又出去了？
一群熟人怎么办？
let's改一下码风？
// freopen
froepen是什么？

~~改码风还是很容易的~~

把"江山易改，本性难移"证伪了

我需要速度测试而不是稳定性测试！
*/
const int N = 5e5 + 500 + 5, M = 500 + 5;
int c,n,m,d,q,cnt,b[N],dis[M][M];
// dis[i][j]表示路线i到路线j的最短距离
vector<pair<int,int>>nbr[N];
// struct node{
// 	int x,y;
// 	bool operator<(const node& u) const{
// 		return y>u.y;
// 	}
// };
// bool vis[N];
// void work(int s,int id){
// 	priority_queue<node>q;//不记得怎么写可以->
// 	// 在/usr/include里搜
// 	memset(vis,0,sizeof(bool)*(n+m+5));
// 	memset(dis[id],0x3f,sizeof(int)*(n+m+5));
// 	q.push({s,0});
// 	dis[id][s]=0;
// 	while(!q.empty())
// 	{
// 		node x=q.top();
// 		q.pop();
// 		if(vis[x.x])continue;
// 		vis[x.x]=true;
// 		for(auto&y:nbr[x.x]){
// 			const int&nxt=y.first,&w=y.second;
// 			if(!vis[nxt]&&dis[id][nxt]>x.y+w){
// 				dis[id][nxt]=x.y+w;
// 				q.push({nxt,dis[id][nxt]});
// 			}
// 		}
// 	}
// 	return;
// }
signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	memset(dis,0x3f,sizeof dis);
	for(int i=1;i<=m;i++)cin>>b[i];
	for(int i=1;i<=n;i++){
		dis[i][i]=0;
		int k;
		cin>>k;
		for(int j=1;j<=k;j++){
			int x,y;
			cin>>x>>y;
			// e[i].push_back(x);
			// dis[i][x]=y;
			// nbr[i+m].push_back({x,y});
			nbr[x].push_back({i,y});
		}
	}
	for(int i=1;i<=m;i++)
		for(auto&y:nbr[i]){
			const int&nxt=y.first,&u=y.second;
			for(auto&z:nbr[i]){
				const int&x=z.first,&v=z.second;
				dis[x][nxt]=min(dis[x][nxt],u+v);
			}
		}
	// cerr<<'#'<<clock()<<'\n';
	for(int k=1;k<=n;k++)
		for(int i=1;i<=n;i++)
			if(i!=k)
				for(int j=1;j<=n;j++)
					dis[i][j]=min(dis[i][j],
						dis[i][k]+dis[k][j]);
	// for(int i=1;i<=n;i++)work(i+m,i);
	// cerr<<'#'<<clock()<<'\n';
	while(q--){
		int x,y,ans=LLONG_MAX>>2;
		cin>>x>>y;
		// if(x==y)cout<<"0\n";
		// else{
		for(auto&u:nbr[x]){
			const auto&nxt1=u.first,&w1=u.second;
			for(auto&v:nbr[y]){
				const auto&nxt2=v.first,&w2=v.second;
				ans=min(ans,w1+w2+dis[nxt1][nxt2]);
				// cerr<<'#'<<nxt1<<' '<<nxt2<<':'<<
				// 	dis[nxt1][nxt2]<<' '
				// 	<<w1<<' '<<w2<<'\n';
			}
		}
		cout<<ans+b[x]+b[y]<<'\n';
		// }
	}
	return 0;
}