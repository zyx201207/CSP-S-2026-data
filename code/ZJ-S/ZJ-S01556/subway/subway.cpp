#include <bits/stdc++.h>
using namespace std;
int c,        n,          m,        d,                             q;
//测试点编号、地铁线路数、地铁站数、每个地铁站最多被几条线路经过，出行计划数
long long w[500050];
//表示i地铁站的地铁口走到站厅需要的时间

vector<long long>xian[550];
struct qwer{
	long long xianlu;
	long long time;
};
vector<qwer>zhan[500050];
//图 
long long dis[550];
//在第i条线路上的站到在什么时候到 
int main(){
//	ios::sync_with_stdio(0);
//	cin.tie(0);
//	cout.tie(0);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;++i){
		cin>>w[i];
	}
	long long k,a,tt;
	for(int i=1;i<=n;++i){
		cin>>k;
		for(int j=1;j<=k;++j){
			cin>>a>>tt;
			xian[i].push_back(a);
			zhan[a].push_back(qwer{i,tt}); 
		}
	}
	int xx,yy;
	while(q--){
		queue<int>gaibian;//变化过的线路 
		cin>>xx>>yy;
		for(int i=1;i<=n;++i){
			dis[i]=1e18;
		}
		for(qwer xianlu:zhan[xx]){
			dis[xianlu.xianlu]=w[xx]+xianlu.time;
			gaibian.push(xianlu.xianlu);
		}
//		while(!gaibian.empty()){
//			int bian=gaibian.front();
//			gaibian.pop();
//			cout<<bian<<endl;
//		}
		while(!gaibian.empty()){
			int bian=gaibian.front();
			gaibian.pop();
//			cout<<bian<<endl;
			for(int x:xian[bian]){
				long long nowtime;
				for(qwer xianlu:zhan[x]){
					if(xianlu.xianlu==bian){
						nowtime=xianlu.time;
						break;
					}
				}
				for(qwer xianlu:zhan[x]){
					if(xianlu.xianlu==bian){
						continue;
					}
					if(dis[xianlu.xianlu]>dis[bian]+nowtime+xianlu.time){
						dis[xianlu.xianlu]=dis[bian]+nowtime+xianlu.time;
						gaibian.push(xianlu.xianlu);
					}
				}
			}
		}
		long long ans=1e18;
		for(qwer x:zhan[yy]){
			ans=min(ans,dis[x.xianlu]+x.time+w[yy]);
		}
		cout<<ans<<endl;
	}
	return 0; 
} 

/*

0 2 5 20 2
4 1 9 2 5
3 1 5 2 7 4 6
3 2 3 3 4 5 7
1 3
1 2

0 3 7 20 2
8 3 6 1 7 2 9
3 1 4 2 5 5 100
3 2 6 3 1 7 2
4 3 2 5 100 4 6 6 7
1 6
2 3


*/
