// 花费 18min 过 T1 的来
// 诡异最短路 
// 这个 c 意义不明。 
// 等一下 m 有 1e6 个。
// q 有 1e5 次？？？
// nlogn 是吗
// 卧槽该不会是 Johnson 吧 
// 不对，be calm
// 地铁线路之间是不是可以预处理啊 
// 哦不对我糖了。
// 什么叫只用求步行时间？？？？？ 
// 我想想。应该就是求最小换乘数。可以 dp 吗？ 
// 点太多了，不好搞。 
// 感觉有点像带权并查集是怎么回事？
// 我想想。merge 时如果在同一个地铁线路直接 d[i]=0，如果不同就取换乘的 min，好像可以搞？
// 不行啊，我们建树之后还要求 lca。
// 哎我靠不管了先打暴力111 
// 啥玩意，暴力 60 分？？？？？
// 开玩笑呢。 
// 不管了，开 T3。 
// 欸这道题是不是可以倍增加速跳跃？？
// 我靠？？？？？
// 没时间了。100 -> 60 
#include<bits/stdc++.h>
#include<bits/extc++.h>
#define mod 998244353
#define ll long long
#define hsh __gnu_pbds::gp_hash_table 
#define inf 0x7f7f7f7f7f7f7f7f
using namespace std;
int idc,n,m,D,Q;
int w[500005],k[505];
vector<int> d[500005];
vector<int> a[505];
hsh<int,int> e[505];
int s,t;
ll ans[100005];
bool vis[500005];
void dfs(int s,int t,ll sum,int ansid,int route,int id){
	if(sum>ans[ansid]) return ;
	if(s==t){
		ans[ansid]=sum+w[t]+e[route][t];
		return ;
	}
	if(route==-1){
		for(auto p:d[s]){
			for(int j=0;j<k[p];j++){
				if(a[p][j]==s){
					dfs(s,t,w[s]+e[p][s],ansid,p,j);
					break;
				}
			}
		}
		return ;
	}else{
		vis[s]=1;
		for(int i=0;i<k[route];i++){
//			cout<<"now traversed to "<<a[route][i]<<", size="<<d[a[route][i]].size()<<'\n';
			if(vis[a[route][i]]) continue;
			if(a[route][i]==t) dfs(t,t,sum,ansid,route,id);
			else if(d[a[route][i]].size()>1){
				for(auto p:d[a[route][i]]){
					if(p==route) continue;
					for(int j=0;j<k[p];j++){
//						cout<<"new route: "<<p<<", traversed to "<<a[p][j]<<'\n';
						if(a[p][j]==a[route][i]){
							dfs(a[route][i],t,sum+e[route][a[route][i]]+e[p][a[route][i]],ansid,p,j);
							break;
						}
					}
				}
			}
		}
		vis[s]=0;
	}
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	memset(ans,0x7f,sizeof ans);
	cin>>idc>>n>>m>>D>>Q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		cin>>k[i];
		for(int j=1;j<=k[i];j++){
			int x,y;
			cin>>x>>y;
			e[i][x]=y;
			a[i].push_back(x);
			d[x].push_back(i);
		}
	}
	if(n<=2){ // n<=2，并且保证联通。那么最小的花费就是 s->t，中间可能有换乘但无伤大雅。 
		ll minn=inf;
		for(int i=1;i<=m;i++){
			if(d[i].size()==2){
				minn=min(minn,(ll)e[d[i][0]][i]+e[d[i][1]][i]);
			}
		}
		for(int i=1;i<=Q;i++){
			cin>>s>>t;
			vector<int> f;
			unordered_set<int> st;
			for(auto p:d[s]) st.insert(p);
			for(auto p:d[t]){
				if(st.count(p)){
					f.push_back(p);
				}
			}
			ll Ans=inf;
			for(auto p:f){
				Ans=min(Ans,(ll)w[s]+w[t]+e[p][s]+e[p][t]);
			}
			if(Ans==inf){ // 要换乘 
				Ans=w[s]+w[t]+e[d[s][0]][s]+e[d[t][0]][t]+minn;
			}cout<<Ans<<'\n';
		}
		return 0;
	}
//	cout<<"-------------routes-------------\n";
//	for(int i=1;i<=n;i++){
//		for(auto j:a[i]){
//			cout<<j<<' ';
//		}
//	cout<<'\n';
//	}
//	cout<<"-------------stations-------------\n";
//	for(int i=1;i<=m;i++){
//		for(auto j:d[i]){
//			cout<<j<<' ';
//		}
//	cout<<'\n';
//	}
//	cout<<"-------------dfs-------------\n";
	for(int i=1;i<=Q;i++){
		cin>>s>>t;
		dfs(s,t,0ll,i,-1,0);
	}
//	cout<<"-------------answer-------------\n";
	for(int i=1;i<=Q;i++) cout<<ans[i]<<'\n';
}
/*
Nr.1
0 2 5 20 2
4 1 9 2 5
3 1 5 2 7 4 6
3 2 3 3 4 5 7
1 3
1 2

Nr.2 
0 3 7 20 2 8 3 6 1 7 2 9
3 1 4 2 5 5 100
3 2 6 3 1 7 2
4 3 2 5 100 4 6 6 7
1 6
2 3
*/
// Iron-Blue Intention
