#include <bits/stdc++.h>
using namespace std;
template<typename T> using vec=vector<T>;
constexpr int INF=0x3fffffff;
void dfs(int u,int f,const vec<vec<int>>& e,const vec<int>& dis,vec<int>& mxs,const vec<bool>& blg){
	mxs[u]=dis[u];
	for(int v:e[u]){
		if(v==f or blg[v]!=blg[u]) continue;
		dfs(v,u,e,dis,mxs,blg);
		mxs[u]=max(mxs[u],mxs[v]);
	}
	return;
}
struct Node{
	int v,w,d;
	Node(int vv,int ww,int dd){
		v=vv,w=ww,d=dd;
	}
	friend bool operator<(const Node& a,const Node& b){
		return a.w<b.w;
	}
};
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int c,t;
	cin>>c>>t;
	while(t--){
		int n,k;
		cin>>n>>k;
		vec<vec<int>> e(n,vec<int>());
		for(int i=0;i<n-1;i++){
			int u,v;
			cin>>u>>v;
			u--,v--;
			e[u].push_back(v);
			e[v].push_back(u);
		}
		int ans=INF;
		for(int i=0;i<n;i++){
			for(int j=0;j<n;j++){
				if(i==j) continue;
				vec<int> mxs(n,INF);
				vec<bool> blg(n);
				vec<int> dis(n,INF);
				{queue<int> q;
				q.push(i);
				q.push(j);
				dis[i]=0,dis[j]=0;
				blg[i]=0,blg[j]=1;
				while(q.size()){
					int qq=q.front();
					q.pop();
					for(int v:e[qq]){
						if(dis[v]==INF){
							q.push(v);
							dis[v]=dis[qq]+1;
							blg[v]=blg[qq];
						}
					}
				}
				dfs(i,-1,e,dis,mxs,blg);
				dfs(j,-1,e,dis,mxs,blg);}
				priority_queue<Node> q;
				{vec<bool> vis(n);
				for(int v:e[i]){
					if(blg[v]==blg[i]){
						q.push(Node(v,mxs[v],1));
						vis[v]=1;
					}
				}
				for(int v:e[j]){
					if(blg[v]==blg[j]){
						q.push(Node(v,mxs[v],1));
						vis[v]=1;
					}
				}
				int kk=k-2;
				while(q.size() and kk){
					Node qq=q.top();
					q.pop();
					kk--;
					for(int v:e[qq.v]){
						if(vis[v]==0 and blg[v]==blg[qq.v]){
							q.push(Node(v,mxs[v]-qq.d,qq.d+1));
							vis[v]=1;
						}
					}
				}}
				int tmp=0;
				while(q.size()){
					tmp=max(tmp,q.top().w);
					q.pop();
				}
				ans=min(ans,tmp);
			}
		}
		cout<<ans<<'\n';
	}
	cout.flush();
	return 0;
}
