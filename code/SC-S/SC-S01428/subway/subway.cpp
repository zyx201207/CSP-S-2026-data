//让我想到了一个考的比较少的最短路知识点--虚点
//其他的我也想不到了，应该有分吧
#include <bits/stdc++.h>
using namespace std;
const int N=5e5+600;
#define ll long long
#define pli pair<ll,int>
#define id second
#define val first
int c,n,m,d,q,tim[N],cnt=5e5+10,dis[N],vis[N],kus[N];
vector<pair<ll,int>> l[N];
ll dij(int s,int t){
	priority_queue<pli,vector<pli>,greater<pli>> q;
	memset(vis,0,sizeof(vis));
	memset(dis,0x3f,sizeof(dis));
	q.push({tim[s]+kus[s],s});dis[s]=tim[s]+kus[s];
	while(!q.empty()){
		int u=q.top().id;
		q.pop();
		vis[u]=1;
		for(auto it:l[u]){
			if(dis[it.id]>dis[u]+it.val+kus[it.id]){
				dis[it.id]=dis[u]+it.val+kus[it.id];
				q.push({dis[it.id]+kus[it.id],it.id});
			}
		}
	}
	return dis[t]+tim[t]-kus[t];
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>tim[i];
	}
	for(int i=1;i<=n;i++){
		int k;cin>>k;//建立虚点，连接地铁线路
		cnt++;
		for(int j=1;j<=k;j++){
			int x,y;cin>>x>>y;
			l[cnt].push_back({y,x});
			l[x].push_back({0,cnt});//走虚点免费
			kus[x]=y;
		}
	}
	while(q--){
		int x,y;cin>>x>>y;
		cout<<dij(x,y)<<'\n';
	}
	return 0;
}