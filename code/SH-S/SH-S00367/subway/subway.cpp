#include<bits/stdc++.h>
using namespace std;
long long c,n,m,d,q,doortohall[5000],st,ed;// doortohall[地铁站数] = 该地铁站到大厅的时间 
bool posused[505];//标记这条线路做没做过 
long long ans = 0,minn;
struct zhan{
	long long gatetohall[505];//[通往的线路] = 所需时间 
	long long tte = 0;//总共通过的线路数量 
	long long le[505];
} gate[505];//[第n地铁站] 
struct xin{
	int gateno[505];
	int ttgt = 0;
} xian[10000]; 
void dfs(int pos,long long tt){
	if(pos == ed) {
		minn = min(minn,tt);
		return ;
	}
	zhan tmp = gate[pos];
	for(int i = 1; i <= tmp.tte; i ++){
		if(!posused[tmp.le[i]]) {//如果当前站点没有用过就遍历这站点线路上的所有站点 
			posused[tmp.le[i]] = 1;
			for(int j = 1; j <= xian[tmp.le[i]].ttgt; j ++){
				int zd = xian[tmp.le[i]].gateno[j];//当前线路通往的一个站点 
				dfs(zd,tt + tmp.gatetohall[tmp.le[i]] + gate[zd].gatetohall[tmp.le[i]]);
				//将（当前选择前往的站点，以前累积的时间 + 当前所在站点通往选择线路的时间 + 该线路到选择前往的站点的从该线路到站点大厅的时间）纳入搜索
			}
			posused[tmp.le[i]] = 0;
		} 
	}
	return ;
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin >> c >> n >> m >> d >> q;
	for(int i = 1; i <= m; i ++) {
		cin >> doortohall[i];
	}
	for(int i = 1; i <= n; i ++){
		int k;//第i线路通过地铁站总数 
		cin >> k;
		for(int j = 1; j <= k; j ++){
			int t;//该线路经过的地铁站t
			cin >> t;
			cin >> gate[t].gatetohall[i]; //第t个站台所通过的线路i到大厅的时间 
			gate[t].tte ++; //第t个站台通过的总线路数加一 
			gate[t].le[gate[t].tte] = i; //记录第t个站台通过的第tte条线路对应的线路编号i 
			xian[i].gateno[++ xian[i].ttgt] = t; //记录第i条线路所经过的第ttgt个地铁站编号 
		}
	}
	while(q --){
		cin >> st >> ed;
		ans = doortohall[st] + doortohall[ed]; 
		minn = 0x3f3f3f3f;
		dfs(st,0);
		cout << minn + ans << '\n';
	}
	return 0;
}
