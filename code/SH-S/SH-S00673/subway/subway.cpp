#include<bits/stdc++.h>
using namespace std;
const int N = 505;
long long c,n,m,d,q,w[N],vis2[N],vis[N];
vector <pair<long long,long long> > g2[N];
vector <long long> g[N];
struct node{//激动人心的最短路!!
	long long v,t;//t代表时间,v代表能到达的节点 
	bool operator<(const node& u) const{
		return t > u.t;
	}
};
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin >> c >> n >> m >> d >> q;
	for(int i = 1;i <= m;i++) cin >> w[i];//第i个地铁站走到站厅所用的时间
	for(int i = 1;i <= n;i++){
		long long k;
		cin >> k;
		while(k--){
			long long a,t; 
			//依次将所经过的地铁站入队
			cin >> a >> t;
			g[a].push_back(i);//第i条路线可以到达a地铁站 以及用时 
			g2[i].push_back({a,t});//此时在这条线上有几个站 以及每个站的用时 
		}
	}
	while(q--){
		for(int i = 1;i <= 500;i++){
			vis[i] = 0;
			vis2[i] = 0;
		}
		long long s,e;
		long long ans = 0;//总用时 
		cin >> s >> e;
		priority_queue<node> pq;
		ans = w[s];//从起点出发，所以要走起点的站台 
		//这里的s指的是第几个站 所以我们要从第几个站入手
		//我也不知道要走多少遍bfs 
		
		pq.push({s,0});//地铁站此时所在的节点,此时所用的换乘时长为0 
		while(!pq.empty()){
			auto now = pq.top();
			long long vv = now.v,tt = now.t;//记录当前的节点,以及当前的用时
			ans += tt;
			if(vv == e) break;
			pq.pop(); 
			for(auto it:g[vv]){ 
				long long to = it;//记录下到的节点以及用时
				//it.first是线路！线路啊！ 
				//if(vis[to]) continue;//这一条线路已经走过了
				for(auto uuu:g2[to]){//线路上有几站 
					long long uu = uuu.first,ww = uuu.second;
					//uu代表站 ww代表用时 
					if(vis2[uu] == 1) continue;
					pq.push({uu,ww});
					vis2[uu] = 1;
				}
			}
		}
		ans += w[e];
		cout << ans << "\n";
	}
	
	return 0;
}
