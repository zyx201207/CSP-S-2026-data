#include<bits/stdc++.h>
#define int long long
using namespace std;
long long cc,testcase,n,k,fa[15],T[15],d[15],ans;
bool inS[15];
struct Edge{
	int u,v;
}e[35];
inline int find(int u){
	if(fa[u]==u){
		return u;
	}
	return fa[u]=find(fa[u]);
}
inline void merge(int u,int v){
	fa[find(u)]=find(v);
	return;
}
inline bool check_ltk(){
	//inS 已经选完了
	for(int i=1;i<=n;i++){
		fa[i]=i;
		T[i]=0;
	}
	for(int i=1;i<n;i++){
		if(inS[e[i].u]==1&&inS[e[i].v]==1){
			merge(e[i].u,e[i].v);
		}
	}
	for(int i=1;i<=n;i++){
		if(inS[i]){
			T[find(i)]++;
		}
	}
	int count=0;
	for(int i=1;i<=n;i++){
		if(T[i]){
			count++;
		}
	}
	if(count<=2){
		return 1;
	}
	return 0;
}
struct edge{
	int u,v,nxt;
}ed[25];
long long tot,head[15];
inline void add_edge(int u,int v){
	ed[++tot].u=u;
	ed[tot].v=v;
	ed[tot].nxt=head[u];
	head[u]=tot;
	return;
}
bool vis2[15];
inline int find_shortest(int now,int v,int diis){
	vis2[now]=1;
	if(now==v){
		return diis;
	}
	for(int i=head[now];i;i=ed[i].nxt){
		if(!vis2[ed[i].v]){
			int qwqwq=find_shortest(ed[i].v,v,diis+1);
			if(qwqwq){
				return qwqwq;
			}
		}
	}
}
inline void solve(){
	//计算每个点的 d 
	for(int i=1;i<=n;i++){
		d[i]=0;
	}
	memset(ed,0,sizeof(ed)),tot=0;
	memset(head,0,sizeof(head));
	for(int i=1;i<n;i++){
		add_edge(e[i].u,e[i].v);
		add_edge(e[i].v,e[i].u);
	}
	for(int i=1;i<=n;i++){
		if(inS[i]){
			d[i]=0;
		}
		else{
			int shortest=INT_MAX;
			for(int j=1;j<=n;j++){
				if(!inS[j]){
					continue;
				}
				memset(vis2,0,sizeof(vis2));
				shortest=min(shortest,find_shortest(i,j,0));
//				if(inS[2]==1&&inS[5]==1&&i==3&&j==2){
//					cout<<cout<<find_shortest(i,j,0);
//				}
			}
			d[i]=shortest;
		}
	}
	int maxdi=0;
	for(int i=1;i<=n;i++){
//		cout<<d[i]<<" ";
		maxdi=max(maxdi,d[i]);
	}
//	cout<<"->maxdi=";
//	cout<<maxdi<<endl;
	ans=min(ans,maxdi);
	return;
}
inline void dfs(int now){
	if(now==n+1){
		int cnt=0;
		for(int i=1;i<=n;i++){
			cnt+=inS[i];
		}
		if(cnt!=k){
			return;
		}
		if(!check_ltk()){
			return;
		}
//		for(int i=1;i<=n;i++){
//			cout<<inS[i]<<" ";
//		}
//		cout<<"->";
		solve();
		return;
	}
	inS[now]=0;
	dfs(now+1);
	inS[now]=1;
	dfs(now+1);
	return;
}
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin>>cc>>testcase;
	while(testcase--){
		cin>>n>>k;
		for(int i=1;i<=n;i++){
			inS[i]=0;
		}
		ans=LONG_LONG_MAX;
		memset(e,0,sizeof(e));
		for(int i=1;i<n;i++){
			cin>>e[i].u>>e[i].v;
		}
//		cout<<find_shortest(1,4,0)<<endl;
		dfs(1);
		cout<<ans<<'\n';
	}
	return 0;
}
