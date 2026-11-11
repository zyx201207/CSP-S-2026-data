#include<bits/stdc++.h>
#define int long long
using namespace std;
inline int read(){
    char ch = getchar_unlocked();
    int sign = 1,value = 0;
    while(!isdigit(ch)){
        if(ch == '-')sign = -1;
        ch = getchar_unlocked();
    }
    while(isdigit(ch)){
        value = value * 10 + ch - '0';
        ch = getchar_unlocked();
    }
    return sign * value;
}
const int N = 510,M = 500010;
const int inf = 0x3f3f3f3f3f3f3f3f;
int c,n,m,d,q;
int w[M],sz[N];
vector<int> to[M],val[M];//the station to the line
int dis[N][N];
signed main(){
    freopen("subway.in" , "r" , stdin);
    freopen("subway.out" , "w" , stdout);
    c = read() , n = read() , m = read() , d = read() , q = read();
    for(int i = 1;i<=m;i++)w[i] = read();
    for(int i = 1;i<=n;i++){
        sz[i] = read();
        for(int j = 1;j<=sz[i];j++){
            int A = read(),T = read();
            to[A].push_back(i);
            val[A].push_back(T);
        }
        for(int j = 1;j<=n;j++)if(i != j)dis[i][j] = inf;
    }
    for(int p = 1;p<=m;p++){
        for(int i = 0;i<to[p].size();i++){
            for(int j = 0;j<to[p].size();j++){
                if(i == j)continue;
                int hi = to[p][i] , hj = to[p][j];
                int wi = val[p][i] , wj = val[p][j];
                dis[hi][hj] = min(dis[hi][hj] , wi + wj);
                dis[hj][hi] = min(dis[hj][hi] , wi + wj);
            }
        }
    }
    for(int k = 1;k<=n;k++){
        for(int i = 1;i<=n;i++){
            for(int j = 1;j<=n;j++){
                dis[i][j] = min(dis[i][j] , dis[i][k] + dis[k][j]);
            }
        }
    }
    for(int p = 1;p<=q;p++){
        int x,y;
        x = read(),y = read();
        int ans = inf;
        for(int i = 0;i<to[x].size();i++){
            for(int j = 0;j<to[y].size();j++){
                int hi = to[x][i],hj = to[y][j];
                int wi = val[x][i],wj = val[y][j];
                ans = min(ans , wi + dis[hi][hj] + wj);
            }
        }
        ans += w[x] + w[y];
        printf("%lld\n" , ans);
    }
    return 0;
}
