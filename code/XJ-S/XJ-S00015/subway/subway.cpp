#include<bits/stdc++.h>
using namespace std;
#define int long long
#define pii pair<int,int>
int c,n,m,d,q;
constexpr int M=5e5+5;
vector<pii> ver[M];
int w[M],minn=INT_MAX;
bool has_sub[M],corey[M],vis[M];
void dfs(int cur,int w,const int &dest){
	if(w>minn) return;
	for(const auto &e:ver[cur]){
		int to=e.first,val=e.second;
		if(to==dest){
			minn=min(minn,w+val);
			return;
		}else{
			if(corey[to]==true&&!vis[to]){
				vis[to]=true;
				dfs(to,w+val,dest);
				vis[to]=false;
			}
		}
	}
	return;
}
void dfs2(int cur,int w,const int &dest,int step){
	if(w>minn||step>2) return;
	for(const auto &e:ver[cur]){
		int to=e.first,val=e.second;
		if(to==dest){
			minn=min(minn,w+val);
			return;
		}else{
			if(corey[to]==true&&!vis[to]){
				vis[to]=true;
				dfs2(to,w+val,dest,step+1);
				vis[to]=false;
			}
		}
	}
	return;
}
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++) cin>>w[i];
	for(int i=1;i<=n;i++){
		int k;cin>>k;
		int v,w;
		vector<pii> q;
		for(int i=1;i<=k;i++){
			cin>>v>>w;
			if(has_sub[v]) corey[v]=true;
			has_sub[v]=true;
			q.push_back({v,w});
		}
		for(const auto &e:q){
			int st=e.first,ini=e.second;
			for(const auto &sun:q){
				int to=sun.first,outi=sun.second;
				if(to==st) continue;
				ver[st].push_back({to,ini+outi});
			}
		}
	}
	if(c<=11&&c>=9){
		while(q--){
			minn=M;
			int x,y,tot=0;cin>>x>>y;
			tot+=w[x]+w[y];
			dfs2(x,0,y,1);
			cout<<minn+tot<<'\n';
		}
	}
	while(q--){
		minn=M;
		int x,y,tot=0;cin>>x>>y;
		tot+=w[x]+w[y];
		dfs(x,0,y);
		cout<<minn+tot<<'\n';
	}
	return 0;
}
