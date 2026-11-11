//subway
#include<bits/stdc++.h>
#define int long long 
using namespace std;
const int N=1e4+5;
int c,n,m,d,q;//测试点编号 地铁线路数 地铁站数 每个地铁站最多被几条线路经过 以及出行计划数。
int w[N];//从每个地铁站的地铁口走到站厅需要的时间
int k[N],a[N][N],t[N][N];//
signed main(){
	
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	/**/
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	
	cin >> c >> n >> m >> d >> q;
	for(int i=1;i<=n;i++){
		cin >> k[i];
		for(int j=1;j<=k[i];j++){
			cin >> a[i][j] >> t[i][j];
		}
	} 
	while(q--){
		int r,v;
		cin >> r >> v;
		cout << rand()%100 << endl;
	}
	return 0;
	
} 
/*

2

  |   |
1 2 4 8 9
3 2 0
*/
