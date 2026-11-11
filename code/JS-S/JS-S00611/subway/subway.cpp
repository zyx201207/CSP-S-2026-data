#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef pair<int,int> PII;
const int N = 505,M = 5e5 + 5;;
LL C,n,m,d,q;
LL w[N][N];
LL op[M],g[M][N];
vector<pair<int,LL>> v[M];

int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);

    memset(w,0x3f,sizeof w);
    scanf("%lld%lld%lld%lld%lld",&C,&n,&m,&d,&q);
    for(int i = 1;i <= m;i++) scanf("%lld",&op[i]);
    for(int i = 1;i <= n;i++){
        int k;
        scanf("%d",&k);
        for(int j = 1;j <= k;j++){
            int t1;
            LL t2;
            scanf("%d%lld",&t1,&t2);
            v[t1].push_back({i,t2});

        }
    }
    for(int id = 1;id <= m;id++){
        for(int i = 0;i < v[id].size();i++){
            for(int j = i + 1;j < v[id].size();j++){
                w[v[id][j].first][v[id][i].first] = w[v[id][i].first][v[id][j].first] = min(w[v[id][i].first][v[id][j].first],v[id][i].second+v[id][j].second);
            }
        }
    }

    for(int i = 1;i <= n;i++) w[i][i] = 0;

    for(int i = 1;i <= n;i++){
        for(int k = 1;k <= n;k++){
            for(int j = 1;j <= n;j++){
                w[i][j] = min(w[i][j],w[i][k] + w[k][j]);
            }
        }
    }

//     for(int i = 1;i <= n;i++){
//        for(int j = 1;j <= n;j++){
//            if(i == j) continue;
//            cout << i << ' ' << j << ' ' << w[i][j] << endl;
//        }
//    }

    for(int i = 1;i <= q;i++){
        int x,y;
        cin >> x >> y;
        LL res = 0x3f3f3f3f3f3f3f3f;
        for(auto t:v[x]){
            for(auto k:v[y]){
                res = min(res,w[t.first][k.first] + t.second + k.second);
            }
        }
        printf("%lld\n",res + op[x] + op[y]);
    }
    return 0;
}
//save the previous stop and the next stop
