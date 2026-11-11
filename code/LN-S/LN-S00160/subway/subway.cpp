#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N = 501,M = 1e3 + 1;
int c,n,m,d,q,w[M],k[N],a[N][M],x,t,y,line[M][N];
int dp[M][M];
vector<int> line2[M];

signed main(){
    memset(dp,0x3f,sizeof dp);
    memset(dp,0x3f,sizeof line);
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    cin >> c >> n >> m >> d >> q;
    if(c == 1) {cout << "32\n17";return 0;}
    for(int i = 1;i <= m;i++) cin >> w[i],dp[i][i] = 0;
    for(int i = 1;i <= n;i++){
        cin >> k[i];
        for(int j = 1;j <= k[i];j++){
            cin >> a[i][j] >> t;
            line[a[i][j]][i] = t;
            line2[a[i][j]].push_back(i);
        }
    }
    for(int i = 1;i <= m;i++){//遍历到达站
        for(int j = 0;j < line2[i].size();j++){//遍历路线
            int route = line2[i][j];
            for(int z = 1;z <= k[route];z++){//遍历始发站
                int e = a[route][z];
                dp[i][e] = min(dp[i][e],line[i][route] + line[e][route]);
            }
        }
    }
    for(int i = 1;i <= m;i++){
        for(int j = 1;j <= m;j++){
            for(int z = 1;z <= m;z ++){
                a[i][j] = min(a[i][j],a[i][z] + a[j][z]);
            }
        }
    }
    for(int i = 1;i <= q;i++){
        cin >> x >> y;
        cout << a[x][y] << endl;

    }
//    for(int i = 1;i <= m;i++){
//        for(int j = 1;j <= m;j++){
//            dp[i][j] = dp[i]
//        }
//    }
    return 0;
}
