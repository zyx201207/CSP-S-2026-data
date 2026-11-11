/*
站很多，但是线路数量很少(500)
可以考虑在几条线路之间建立关系
然后再最后枚举起始线路和结束线路 
*/ 
#include <bits/stdc++.h>
#include <windows.h>
using namespace std;
const int N = 5e5 + 9;
const int D = 509; 
#define int long long
const int INF = 0x3f3f3f3f3f3f3f3f; 
int dst[D][D];
int c ,  n , m , d , q , w[N] , pass[N];
vector<int> zhandian;
vector <pair<int,int>> k[N];
void merge(int u , int v,int c){
	dst[u][v] = dst[v][u] = min(c,dst[u][v]);
}
signed main(){ 
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
//	ios::sync_with_stdio(0);
//	cin.tie(0);cout.tie(0);
//	cout << 500 * ((500 + 5e5) * (log2((5e5))));
	cin >> c >> n >> m >> d >> q;
//	cout << q << endl;
	for (int i = 1;i <= m ;i ++){
		cin >> w[i];
	}
	
//	auto t1 = clock();
	for (int i = 1;i <= n;i ++){
		for (int j = 1;j <= n ;j ++){
			dst[i][j] = INF;
		}
	}
	
//	auto t2 = clock();
	for (int i = 1;i <= n;i ++){
		int f ;
		cin >> f;
		for (int j = 1;j <= f;j++){
			int a , t;
			cin >> a >> t;
			k[a].push_back({i,t});
//			zhandian.insert(a);
			if (pass[a]) continue;
			pass[a] = 1;
			zhandian.push_back(a);
		}
		
	}
//	cout << zhandian.size();
//	int qwerty = 0;

	for (auto i : zhandian){
		// O(d ^ 2 * 5e5) = 4e7
//		cout << i << "\n";
		for (int j = 0;j < k[i].size() - 1; j ++){
			int a1 = k[i][j].first , t1 = k[i][j].second; 
			for (int _ = j + 1;_ < k[i].size();_++){
				int a2 = k[i][_].first , t2 = k[i][_].second; 
				merge(a1,a2,t1+t2);
//				cout << "!" << a1 << " " << a2 <<" "<< t1 + t2  << endl;
			}
		}
		
//		if (++qwerty > 5421){
//			cout << qwerty << "\n";
//		}
	}
//	cout << '!';
	for (int i = 1;i <= n;i++){
		dst[i][i] = 0;
	}
	for (int k = 1;k <= n;k ++){
		for (int i = 1;i < n;i ++){
			for (int j = i+1;j <= n;j ++){
				dst[j][i] = dst[i][j] = min({dst[i][j],dst[i][k]+dst[k][j],dst[j][k]+dst[k][i]});
			}
		} 
	}
//	cout << q << endl;
	while(q--){
		int x , y;
		cin >> x >> y;
		int ans = INF;
		for (int j = 0;j < k[x].size(); j ++){
			int a1 = k[x][j].first , t1 = k[x][j].second;
			for (int _ = 0;_ < k[y].size();_++){
				int a2 = k[y][_].first , t2 = k[y][_].second;
				ans = min(ans,dst[a1][a2]+t1+t2);
			}
		}
		cout << ans + w[x] + w[y] << "\n";
	} 
	
	
//	Sleep(1024);
	 
//	cout << (t2 - t1) ;
//	cout << dst[1][2] << endl;
	return 0; 
} 
/*
0 2 5 20 2
4 1 9 2 5
3 1 5 2 7 4 6
3 2 3 3 4 5 7
1 3
1 2
*/
/*
0 3 7 20 2
8 3 6 1 7 2 9
3 1 4 2 5 5 100
3 2 6 3 1 7 2
4 3 2 5 100 4 6 6 7
1 6
2 3
*/
