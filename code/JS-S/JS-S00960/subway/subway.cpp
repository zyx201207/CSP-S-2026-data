#include <bits/stdc++.h>
#define ll long long
using namespace std;

// zhe sha ti
// about 16:40 observe for a long time I think R should stay at zhan ting instead of zhan tai usually
// floyd because n+1 station at most, 501*501*501 a little too much but no other way,dij:100000*500*log500
// Notice:in property A,sum of k can only be n+1 at most or the map wont be connected
// hoping for 20pts of example 7~11 thanks to this opinion
// Great,example 1~6 can also be done in this way
// about 17:10 NONONO I think I forget about Floyd
// about 17:30 ok I test the equatation out by qiongju in test.cpp
// 17:38 Good,subway4 passed
// 17:49 what is the teacher annoucing about?
// about 17:50 find example 1~6 partly wrong after some time change some n to sum of k
// 18:03 change more n to sum of k and pass subway123
// think Im done with everything

// Again and again I was silent.

const int MAXN = 510,MAXD = 21,MAXK = 500100;
const ll INF = 1e17;

int c,m,n,d,q,k[MAXN],sum;
ll w[MAXN],t[MAXN][MAXN],a[MAXN][MAXN],ans;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);

    cin >> c >> n >> m >> d >> q;

    for(int i = 1;i<=m;i++) cin >> w[i];

    for(int i = 1;i<=n;i++){
        cin >> k[i];
        sum+=k[i];
        for(int j = 1;j<=k[i];j++){
            cin >> a[i][j] >> t[i][j];
        }
    }

    if(c<=6||c>=12){
        ll dis[sum+5][sum+5];
        for(int i = 1;i<=sum;i++){
            for(int j = 1;j<=sum;j++){
                dis[i][j] = 1e17;
            }
            dis[i][i] = 0;
        }

        for(int i = 1;i<=n;i++){
            for(int xi = 1;xi<=k[i];xi++){
                for(int yi = xi+1;yi<=k[i];yi++){
                    dis[a[i][xi]][a[i][yi]] = min(dis[a[i][xi]][a[i][yi]],t[i][xi]+t[i][yi]);
                    dis[a[i][yi]][a[i][xi]] = dis[a[i][xi]][a[i][yi]];
                }
            }
        }

        for(int ki = 1;ki<=sum;ki++){
            for(int i = 1;i<=sum;i++){
                for(int j = 1;j<=sum;j++){
                    dis[i][j] = min(dis[i][j],dis[ki][i]+dis[ki][j]);
                }
            }
        }
        int x,y;
        ans = 0;
        for(int t = 1;t<=q;t++){
            cin >> x >> y;
            ans = dis[x][y];
            ans += w[x]+w[y];
            printf("%lld\n",ans);
        }
    }else if((c>=7)&&(c<=11)){
        ll dis[n+5][n+5];
        for(int i = 1;i<=n;i++){
            for(int j = 1;j<=n;j++){
                dis[i][j] = 1e17;
            }
            dis[i][i] = 0;
        }

        for(int i = 1;i<=n;i++){
            dis[a[i][1]][a[i][2]] = min(dis[a[i][1]][a[i][2]],t[i][1]+t[i][2]);
            dis[a[i][2]][a[i][1]] = dis[a[i][1]][a[i][2]];
        }

        for(int k = 1;k<=n;k++){
            for(int i = 1;i<=n;i++){
                for(int j = 1;j<=n;j++){
                    dis[i][j] = min(dis[i][j],dis[k][i]+dis[k][j]);
                }
            }
        }
        int x,y;
        ans = 0;
        for(int t = 1;t<=q;t++){
            cin >> x >> y;
            ans = dis[x][y];
            ans += w[x]+w[y];
            printf("%lld\n",ans);
        }
    }
    
    return 0;
}