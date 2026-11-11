#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 500005;
ll c,n,m,d,q,W[N],dis[N],pre[N],las[N],ans[N];
struct node{
	ll v,w;
};
vector<node>e[N],qry[N];
struct cmp{
	bool operator()(const node&a,const node&b)const{
		return a.w < b.w;
	}
};
bool visqry[N],vis[N];
void dijk(int s){
	memset(dis,0x3f3f,sizeof(dis));
	memset(vis,0,sizeof(vis));
	priority_queue<node,vector<node>,cmp>que;
	dis[s] = 0;
	que.push({s,0});
	while(!que.empty()){
		node now = que.top();
		que.pop();
		if (vis[now.v])continue;
		vis[now.v] = 1;
		for (auto to : e[now.v]){
			if (dis[to.v] > dis[now.v] + to.w){
				dis[to.v] = dis[now.v] + to.w;
				que.push({to.v,dis[to.v]});
			}
		}
	}
}
inline ll read(){
	ll z = 0;
	bool y = 0;
	char ch = getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')y=1;ch=getchar();}
	while(ch>='0'&&ch<='9')z=z*10+(ch-'0'),ch=getchar();
	return (y)?-z:z;
}
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	c = read(),n = read(),m = read(),d = read(),q = read();
	for (int i = 1;i <= m;i++){
		W[i] = read();
	}
	ll tot = m;
	for (int i = 1;i <= n;i++){
		int k;
		k = read();
		for (int i = 2;i <= 2 * k + 1;i++){
			int id = i / 2;
			if (i % 2 == 0){
				pre[id] = read();
			}
			else{
				las[id] = read();
				tot++;
				e[pre[id]].push_back({tot,las[id]});
				e[tot].push_back({pre[id],las[id]});
				if (id > 1){
					e[tot].push_back({tot-1,0});
					e[tot-1].push_back({tot,0});
				}
			}
		}
	}
	for (int i = 1;i <= q;i++){
		int x1,x2;
		x1 = read(),x2 = read();
		qry[x1].push_back({x2,i});
		visqry[x1] = 1;
	}
	for (int i = 1;i <= m;i++){
		if (visqry[i] == 1){
			dijk(i);
			for (auto to : qry[i]){
				ans[to.w] = dis[to.v] + W[i] + W[to.v];
			}
		}
	}
	for (int i = 1;i <= q;i++){
		cout << ans[i] << "\n";
	}
	return 0;
}
