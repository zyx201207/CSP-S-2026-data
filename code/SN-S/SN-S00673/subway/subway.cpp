#include<bits/stdc++.h>
#define pii pair<int, int>
using namespace std;

int kk,f,cc;
int readint(){
	kk = 0, f = 1,cc = getchar();
	for(;!isdigit(cc);cc = getchar()) if(cc == '-')f = -1;
	for(;isdigit(cc);cc = getchar()) kk = kk * 10 + (cc - '0');
	return kk * f;
}

int c;
int n;//地铁线数量 
int m;//地铁站数量 
int d;//每个地铁站最多线路个数 
int q;//出行计划个数 

int w[500005];//地铁口到站厅 
int k[502];//地铁经过站的个数 
map<int, int> rail[502];//rail[x]表示x号线的站点和站台到站厅的时间1
map<int, int> stat[5000005];//rail[x]表示x号站的线路和站台到站厅的时间1
bool unite[502][500005];//unite[i][j]表示i号线和j号站联通不
 


int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	c = readint();
	n = readint();
	m = readint();
	d = readint();
	q = readint();
	int dis[m+2][m+2];
	for(int i = 1;i <= m;++i){
		for(int j = 1;j <= m;++j){
			if(i == j)continue;
			dis[i][j] = 33550336;
		}
	}
	for(int i = 1;i <= m;++i){
		w[i] = readint();
	}
	for(int i = 1;i <= n;++i){
		k[i] = readint();
		for(int j = 1;j <= k[i];++j){
			int x = readint(),y = readint();
			unite[j][x] = 1;
			rail[i].insert(make_pair(x,y));
			stat[x].insert(make_pair(i,y));
		}
		for(pii p1: rail[i]){
			for(pii p2 : rail[i]){
				if(p1 == p2)continue;
				dis[p1.first][p2.first] = min(dis[p1.first][p2.first],p1.second + p2.second);
				dis[p2.first][p1.first] = min(dis[p2.first][p1.first],p1.second + p2.second);
			}
		}
	}
	
	for(int pass = 1;pass <= m;++pass){
		for(int u = 1;u <= m;++u){
			for(int v = 1;v <= m;++v){
				if(dis[u][pass] == 33550336 || dis[pass][v] == 33550336){
					continue;
				}
				dis[u][v] = min(dis[u][v], dis[u][pass] + dis[pass][v]);
			}
		}
	}
	
	for(int turn = 1;turn <= q;++turn){
		int from = readint(), to = readint();
		cout << dis[from][to]+w[from]+w[to] << "\n";
	}
	return 0;
}

/*

*/
