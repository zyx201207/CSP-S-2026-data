#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int M = 5e5+9;
const int N = 509;
int c,n,m,d,q;
int w[M],k[N],iid[M],id[N];
vector<pair<ll,int>> to[M];  //图 边权 目标点 
ll dis[M],ans;
bool vis[M];
/*
id[i] 表示线路i对应的图中结点的编号（整个线路上的所有闭上站台缩成一个点） 
iid[i] 表示编号为i的站厅对应的图中结点编号 
*/
int now_id = 0;
void solve(int S,int T){
	memset(vis,0,sizeof(vis));
	memset(dis,0x3f,sizeof(dis));
	ans = 0;
	
	priority_queue<pair<ll,int>> st;
	st.push(make_pair(0,S));
	dis[S] = 0;
	while (!st.empty()){
		int u = st.top().second;
		st.pop();
		if (vis[u]) continue;
		vis[u] = 1;
		
		for (int i = 0;i < (int)to[u].size();i++){
			int v = to[u][i].second;
			ll dd = to[u][i].first;
			
			if (dis[u] + dd < dis[v]){
				dis[v] = dis[u] + dd;
				st.push(make_pair(-dis[v],v));
			}
			
		}
	}
	ans = dis[T];
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	//cin>>c>>n>>m>>d>>q;
	scanf("%d%d%d%d%d",&c,&n,&m,&d,&q);
	for (int i = 1;i <= m;i++){
		//cin>>w[i];
		scanf("%d",&w[i]);
		now_id++;
		iid[i] = now_id;
	}
	for (int i = 1;i <= n;i++){
		scanf("%d",&k[i]);
		//cin>>k[i];
		now_id++;
		id[i] = now_id;
		for (int j = 1;j <= k[i];j++){
			int a,t;
			scanf("%d%d",&a,&t);
			//cin>>a>>t;
			to[id[i]].push_back(make_pair(t,iid[a]));
			to[iid[a]].push_back(make_pair(t,id[i]));
		}
	}
	for (int i = 1;i <= q;i++){
		int l,r;
		scanf("%d%d",&l,&r);
		//cin>>l>>r;
		solve(iid[l],iid[r]);
		ans += w[l] + w[r];
		cout<<ans<<endl;
	}
	return 0;
}
