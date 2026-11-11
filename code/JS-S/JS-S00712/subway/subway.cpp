#include <bits/stdc++.h>
using namespace std;
#define int long long
const int MAXN = 2010;
const int mod = 998244353;
int c,n,m,d,q,dis[MAXN][MAXN],a[MAXN];
vector<pair<int,int> > g[MAXN];
void solve(){
    cin >> c >> n >> m >> d >> q;
    //kou:1
    //ting:2
    //tai:3
    memset(dis,0xf,sizeof(dis));
    for(int i = 1;i <= m;i++){
        int w;
        cin >> w;
        dis[i + m * 2][i] = dis[i][i + m * 2] = w;
    }
    for(int i = 1;i <= n;i++){
        int k;
        cin >> k;
        for(int j = 1;j <= k;j++){
            int t;
            cin >> a[j] >> t;
            for(int ii = 1;ii <= n;ii++) dis[(3 + ii) * m + i][2 * m + a[j]] = t;
            for(int ii = 1;ii <= n;ii++) dis[2 * m + a[j]][(3 + ii) * m + i] = t;
            if(j > 1) dis[(3 + i) * m + a[j - 1]][(3 + i) * m + a[j]] = 0;
        }
    }
    for(int k = 1;k <= (3 + n) * m;k++){
        for(int i = 1;i <= (3 + n) * m;i++){
            for(int j = 1;j <= (3 + n) * m;j++){
                dis[i][j] = min(dis[i][j],dis[i][k] + dis[k][j]);
            }
        }
    }
    while(q--){
        int s,t;
        cin >> s >> t;
        cout << dis[s][t] << endl;
    }
}
signed main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
	int t = 1;
	//cin >> t;
	while(t--) solve();
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

// MAYBE, AFO ON 2026/10/31.
// I'M SORRY.
// I CAN NOT REACH THE GOAL,AND IT'S THE END.
// BYE.
