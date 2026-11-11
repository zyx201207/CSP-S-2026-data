#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
const LL MAXN = 505,MAXM = 5e5+5,INNF = 1e17;
struct Node{
	LL v,w;
	bool operator < (const Node &cmp)const{
		return w < cmp.w;
	}
};
LL n,m,q,d,tv[MAXN];
LL tl[MAXN][MAXN];//第i条线路 到j 的步行时间 
bool c;
vector<Node> paths[MAXN],lns[MAXM],a[MAXN];//第i个站过的线路 第i条线路过的站
//初始化,构图 
inline void initt(){
	memset(tl,-1,sizeof(tl));
	for(LL i = 1;i <= n;i++){
		tl[i][i] = 0;
		for(auto xa:a[i]){
			for(auto xl:lns[xa.v]){
				if(tl[i][xl.v]==-1) tl[i][xl.v]=tl[xl.v][i]= xa.w+xl.w;
				else tl[i][xl.v]=tl[xl.v][i]= min(tl[i][xl.v],xa.w+xl.w);
			}
		}
	}
	for(LL i = 1;i <= n;i++){
		for(LL j = 1;j <= n;j++){
			if(i==j) continue;
			if(tl[i][j] != -1){
				paths[i].push_back({j,tl[i][j]});
				paths[j].push_back({i,tl[i][j]});
			}
		}
	}
}
//dijkstra
bool vis[MAXN];
inline LL dijk(LL srt,LL dst){
	memset(vis,0,sizeof(vis));
	priority_queue<Node> qu;
	qu.push({srt,0});
	while(!qu.empty()){
		LL ui = qu.top().v, di = qu.top().w;
		qu.pop();
		if(vis[ui]) continue;
		vis[ui] = 1;
		if(ui==dst) return -di;
		for(auto vi: paths[ui]){
			qu.push({vi.v,di-vi.w});
		}
	}
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin >> c >> n >> m >> d >> q;
	for(LL i = 1;i <= m;i++){
		cin >> tv[i];
	}
	for(LL i = 1;i <= n;i++){
		LL ki,ai,wi;
		cin >> ki;
		for(LL j = 1;j <= ki;j++){
			cin >> ai >> wi;
			a[i].push_back({ai,wi});
			lns[ai].push_back({i,wi});
		}
	} 
	initt();
	while(q--){
		LL xi,yi,ans = INNF;
		cin >> xi >> yi;
		for(auto lx:lns[xi]){
			for(auto ly:lns[yi]){
				if(lx.v == ly.v){
					ans = lx.w+ly.w;
					break;
				}
				ans = min(ans,dijk(lx.v,ly.v)+lx.w+ly.w);
			}
		}
		ans += tv[xi] + tv[yi];
		cout << ans << "\n";
	}
	return 0;
}
