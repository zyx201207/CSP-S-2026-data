//多测要清空，审题要认真，认真检查对拍，防止变量重名 ，及时保存代码及副本 , 开ll，计算空间 
//yyc,ytz,lcl,lyh,mpy,ljh,sxz,sbh,bjh,xjy,cjr,emmm,7/3大神保佑
//注意freopen，检查题目名，仔细核对思路，不要着急，一定行
//20min读题 , T1 15min想40min写+调 , T2 25min想45min写+调 , T3 15min想20min写暴力+调试 , T4 15min想20min写暴力+调试
//240-60-75-40-40=25min ， 留至少10分钟检查校对 
#include<bits/stdc++.h>
using namespace std;
const int N = 505;
#define ll long long
int c , n , m , d , Q , T;
int w[N] , a[N][N] , t[N][N] , k[N];
vector<int> vec[N];
vector<int> xl[N];
bool vis[N][30];
int dis[N][30];
struct node{
	int x , y , idx;
	int ans;
}ans[N];
bool cmp(node a , node b){
	if(a.x != b.x) return a.x < b.x;
	else return a.y < b.y;
}bool cmp2(node a , node b){
	 return a.idx < b.idx;
}
queue<pair<int ,int> > q;
void solveb(int st){
	//cout << "OK1";
	for(int i = 1 ; i <= n ; i++){
		for(int j = 0 ; j < 30 ; j++){
			vis[i][j] = 0;
			dis[i][j] = 1e9;
		}
	}
while(!q.empty()) q.pop();//u , 线路 
	for(auto v : xl[st]){
		q.push({st , v});
		dis[st][v] = 0;
	}
	//cout << "OK2";
	while(!q.empty()){
		int u = q.front().first;
		int x = q.front().second;
		q.pop();
		vis[u][x] = 1;
		for(auto v : vec[u]){
			for(auto nx : xl[v]){
				if(!vis[v][nx]){
					if(nx == x){
						dis[v][nx] = min(dis[v][nx] , dis[u][x]);
					}else{
						dis[v][nx] = min(dis[v][nx] , dis[u][x] + 1);
					}
					q.push({v , nx});
				}
			}
		}
	}
	//cout << "OK3";
}
int main(){
	freopen("subway.in" , "r" , stdin);
	freopen("subway.out" , "w" , stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
//	cout << "XSX";
	cin >> c >> n >> m >> d >> Q;
	for(int i = 1 ; i <= m ; i++){
		cin >> w[i];
	}
	for(int i = 1 ; i <= n ; i++){
		cin >> k[i];
		for(int j = 1 ; j <= k[i]; j++){
			cin >> a[i][j] >> t[i][j];
			T = t[i][j];
			xl[a[i][j]].push_back(i);
			if(j > 1){
				vec[a[i][j]].push_back(a[i][j - 1]);
				vec[a[i][j - 1]].push_back(a[i][j]);
			}
		}
	}
	for(int i = 1 ; i <= Q ; i++){
		cin >> ans[i].x >> ans[i].y;	
		ans[i].idx = i;
		ans[i].ans = 1e9;
	}
	sort(ans + 1 , ans + n + 1 , cmp);
	int nw = -1;
	for(int i = 1 ; i <= Q ; i++){
		//cout << "A";
		if(nw != ans[i].x) solveb(ans[i].x);
		int mi = 1e9;
		for(int i = 0 ; i < 25 ; i++){
			mi = min(mi , dis[ans[i].y][i]);
		}
		ans[i].ans = mi * T + w[ans[i].x] + w[ans[i].y];
	}
	//cout  << "OK2";
	sort(ans + 1 , ans + 1 + n , cmp2);
	for(int i = 1;  i <= Q;i++){
		cout << ans[i].ans << '\n';
	}
	return 0;
}
/*
0 3 7 20 2
8 3 6 1 7 2 9
3 1 4 2 5 5 100
3 2 6 3 1 7 2
3 2 5 100 4 6 6 7
1 6
2 3
 -O2 -Wall -Wextra
*/
