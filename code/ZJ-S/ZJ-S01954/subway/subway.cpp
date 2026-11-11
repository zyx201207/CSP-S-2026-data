#include<cmath>
#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
#include<ctime>
#include<vector>
#define mp make_pair
#define fo(i , x , y) for(int i = (x) ; i <= (y) ; i++)
#define go(i , x , y) for(int i = (x) ; i >= (y) ; i--)
#define chkmax(a , b) (a) = max((a) , (b))
#define chkmin(a , b) (a) = min((a) , (b))
#define local
#ifdef local
#define debug(x) cerr << #x" : " << x << ", "
#define debugn(x) cerr << #x" : " << x << "\n"
#define debugs(s) cerr << s
#define debugarr(a , n) cerr << #a" : " << "\n"; fo(i , 1 , n) cerr << a[i]; cerr << "\n"
#elif
#define debug(x) "Chytholly is the happiest girl in the world!"
#define debugn(x) "Elaina"
#define debugs(s) "miku"
#define debugarr(a , n) "n-buna"
#endif
using namespace std;
const int maxn = 500;
const int maxm = 5e5;
const long long inf = 1e18;
int c , n , m , d , q;
long long w[maxm + 5];
struct Info{
	int id;
	long long dis;
};
vector<Info> info[maxm + 5];
long long dis[maxn + 5][maxn + 5];
int main(){
	ios :: sync_with_stdio(0) , cin.tie(0) , cout.tie(0);
	freopen("subway.in" , "r" , stdin);
	freopen("subway.out" , "w" , stdout);
	cin >> c >> n >> m >> d >> q;
	fo(i , 1 , m) cin >> w[i];
	fo(i , 1 , n){
		int k;
		cin >> k;
		fo(j , 1 , k){
			int a;
			long long t;
			cin >> a >> t;
			info[a].push_back({i , t});
		}
	}
	fo(i , 1 , n)
		fo(j , 1 , n)
			dis[i][j] = inf;
	fo(i , 1 , n) dis[i][i] = 0;
	fo(k , 1 , m){
		int len = info[k].size();
		fo(i , 0 , len - 1)
			fo(j , i + 1 , len - 1){
				int u = info[k][i].id;
				int v = info[k][j].id;
				long long dist = info[k][i].dis + info[k][j].dis;
				chkmin(dis[u][v] , dist);
				chkmin(dis[v][u] , dist);
			}
	}
	fo(k , 1 , n)
		fo(i , 1 , n)
			fo(j , 1 , n)
				chkmin(dis[i][j] , dis[i][k] + dis[k][j]);
//	fo(i , 1 , n){
//		fo(j , 1 , n)
//			cerr << dis[i][j] << " ";
//		cerr << "\n";
//	}
	fo(i , 1 , q){
		long long ans = inf;
		int u , v;
		cin >> u >> v;
		for(Info x : info[u]){
			for(Info y : info[v])
				chkmin(ans , w[u] + w[v] + x.dis + y.dis + dis[x.id][y.id]);
		}
		cout << ans << "\n";
	}
}