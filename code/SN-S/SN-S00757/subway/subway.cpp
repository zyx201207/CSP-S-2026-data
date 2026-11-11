#include<bits/stdc++.h>
#define int long long
using namespace std;
const int M = 5e5+7;
const int N = 500 + 7;
const int EDGE_CNT = M;
// 这是啥阴间题 考场写了3小时 谨以此言 封建迷信 
// (此处有一个佛祖的ASCII码像) 
// (此处有一个图灵的ASCII码像) 
// (此处有一个GPT-6 Astra的ASCII码像)
// (此处有一个米雪儿李的ASCII码像) 
// \|/   \|/    \|/   \|/ 
// 本人写题未半而中道debug 今T3 T4未看 我已疲敝 此诚危急存亡之秋也
// 牺牲玉帛 弗敢加也 必以信
// 小信已孚 神福也 
// 只要不爆零我多少把klbq都愿意打的 
struct edge{ // 根本没有这么多的代码 
	int nxt,to,w;
}edges[2*EDGE_CNT];
int head[M],cnt;
void _add(int u,int v,int w){
	edges[++cnt].to = v;
	edges[cnt].nxt = head[u];
	edges[cnt].w = w;
	head[u] = cnt;
}
void add(int u,int v,int w){
	_add(u,v,w);
	_add(v,u,w);
//	cout << "Linked " << u << " with " << v << endl;
}
int c,n,m,d,q;
int w[M];
int belong[M];
int t[N][M];
int lastLayer[M];
struct sugar{
	int id,_dis;
};
struct cat{
	bool operator()(sugar michele,sugar lee){
		return michele._dis > lee._dis;
	}
};
const int SPACING = 1145;
int getExit(int u){
	return w[u] + t[belong[u]][u];
}
int alan;
int turing[N][M],mfz[N][M];
int getLayerID(int base,int layer){
	return (layer-1)*SPACING + base;
}
int LayerToOri(int ser){
	return ser%SPACING;
}
pair<int,int> dijkstra(int st,int ed){
	int dist[M];
	memset(dist,0x3f,sizeof dist);
	priority_queue<sugar,vector<sugar>,cat> que;
	dist[st] = 0;
	que.push({st,0});
	while(!que.empty()){
		int u = que.top().id;
		int dis = que.top()._dis;
		que.pop();
		for(int i = head[u];i;i = edges[i].nxt){
			int v = edges[i].to;
			int ew = edges[i].w;
			if(dis + ew < dist[v]){
				dist[v] = dis + ew;
				que.push({v,dist[v]});
			}
		}
	}
	int result = INT_MAX;
	int layerOf = -1;
//	cout << "From " << st << " to " << ed << endl;
	for(int j = 1;j<=n;j++){
//		cout << "Dist " << dist[getLayerID(LayerToOri(ed),j)] << " " << j << " " << getLayerID(LayerToOri(ed),j)<< endl;
		if(result > dist[getLayerID(LayerToOri(ed),j)]){
			result = dist[getLayerID(LayerToOri(ed),j)];
			layerOf = j;
		}
	}
	return {result,layerOf};
}
bool has[N][M];
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin >> c >> n >> m >> d >> q;
	for(int i =1;i<=m;i++){
		cin >> w[i];
		lastLayer[i] = 1;
	}
	for(int i = 1;i<=n;i++){
		int k;
		cin >> k;
		int lst = -1;
		for(int j = 1;j<=k;j++){
			int x;
			cin >> x;
			cin >> t[i][x];
			has[i][x] = true;
			if(belong[x] != 0){// 曾经被别的穿过 
				add(getLayerID(x,belong[x]),getLayerID(x,i),t[belong[x]][x] + t[i][x]);
			}
			belong[x] = i;
			if(lst == -1) lst = x;
			else{
				add(getLayerID(lst,i),getLayerID(x,i),0);
				lst = x;
			}
		}
	}
	//build
	
	while(q--){
		int st;
		int ed;
		int ans = INT_MAX;
		cin >> st >> ed;
		for(int i = 1;i<=n;i++){
			if(!has[i][st]) continue;
			int in = w[st] + t[i][st];
			pair<int,int> result = dijkstra(getLayerID(st,i),getLayerID(ed,i));
			int out = w[ed] + t[result.second][ed];
			ans = min(ans,in + result.first + out);
		}
		cout << ans << endl;
	}
	
	return 0;
}


//Generate by GPT-6 Astra Deepseek-v4-flash Mofuzhen Mofuzhen Mofuzhen
