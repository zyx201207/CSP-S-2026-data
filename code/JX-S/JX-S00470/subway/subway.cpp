#include <bits/stdc++.h>
#define ll long long
#define pii pair<int,int>
#define pll pair<long long,long long>
#define fi first
#define se second
#define pb push_back

#define OI freopen("subway.in","r",stdin),freopen("subway.out","w",stdout)

using namespace std;

const ll INF = 0x3f3f3f3f3f3f3f3f;

ll a[510];
int k[500010];
int c,m,n,d,q;

ll f[3010][3010];
int cnt;

vector <int> subw[500010];

signed main(){
	ios::sync_with_stdio(0);cin.tie(0);
	OI;
	
	cin >> c >> m >> n >> d >> q;
	memset(f,INF,sizeof f);
	for(int i = 1;i <= n;i ++){
		cin >> a[i];
	}

	cnt = n;
	
	for(int i = 1;i <= m;i ++){
		cin >> k[i];
		int lst = 0;
		for(int j = 1;j <= k[i];j ++){
			int to;
			ll dist;
			cin >> to >> dist;
			cnt ++;
			subw[i].pb(cnt);
			if(lst) f[lst][cnt] = 0,f[cnt][lst] = 0;
		//	cout << lst << " to " << cnt << ",dist=0.\n";
			lst = cnt;
			
			f[to][cnt] = dist;
		//	cout << to << " to " << cnt << ",dist=" << dist << ".\n";
			f[cnt][to] = dist;
		}
	}
/*	
	for(int i = 1;i <= n;i ++){
		cout << "belong to " << i << ":\n";
		for(auto j : subw[i]){
			cout << j << ' ';
		}
		cout << '\n';
	}
*/
	for(int i = 1;i <= cnt;i ++) f[cnt][cnt] = 0;
	
	for(int k = 1;k <= cnt;k ++){
		for(int i = 1;i <= cnt;i ++){
			if(i == k) continue;
			for(int j = 1;j <= cnt;j ++){
				if(i == j) continue;
				f[i][j] = min(f[i][j],f[i][k] + f[k][j]);
			}
		}
	}
	
	for(int i = 1;i <= q;i ++){
		int from,to;
		cin >> from >> to;
		cout << f[from][to] + a[from] + a[to] << '\n';
	}
	return 0;
}

/*
 * floyd hui zha haoxiang,bu guan le you fen jiu xing.
 * wo ba suo you de dian jian chu lai
 * dian fen wei zhan ting he zhan tai
 * zhe ge di tie kou de tiao jian ying gai mei shen me yong
 * dian de shu liang ying gai shi nd=10^4
 * ran hou pao dijkstra? buxing,m hen da
 * zhe yang you 12 ge dian 48 fen
 * xian da zai shuo
*/

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

/*
da wan le,ying gai you yi deng le /kel
xian kai T3
*/

