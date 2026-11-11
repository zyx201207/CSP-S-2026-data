#include<bits/stdc++.h>
using namespace std;
#define int long long
typedef long long ll;
typedef pair<int,int> pii;
typedef vector<int> vi;
const int N = 20;
const int inf = (1LL << 60LL);

int c,t;
int n,k;
int dist[N];
int di[N];
bool b[N];
vi g[N];
inline void dfs(int x){
    b[x] = true;
    for (auto y : g[x]){
        if (!b[y] && (y&(1<<(k-1)))){
            dfs(y);
        }
    }
}
deque<int> q;
inline void bfs(int x){
    for (int i = 1;i <= n;i++){
        di[i] = inf;
    }
    b[x] = true;
    q.clear();
    q.push_back(x);
    di[x] = 0;
    dist[x] = min(dist[x],0LL);
    while (!q.empty()){
        int x = q.front();
        q.pop_front();
        for (auto y : g[x]){
            if (di[y] >= inf){
                di[y] = di[x]+1;
                dist[y] = min(dist[y],di[y]);
                q.push_back(y);
            }
        }
    }
}
signed main(){
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    scanf("%lld%lld",&c,&t);
    for (;t--;){
        scanf("%lld%lld",&n,&k);
        for (int i = 1;i <= n;i++){
            g[i].clear();
        }
        for (int i = 1;i <= n-1;i++){
            int u,v;
            scanf("%lld%lld",&u,&v);
            g[u].push_back(v);
            g[v].push_back(u);
        }
        int mi = inf;
        for (int i = 0;i < (1<<n);i++){
            int sum = 0;
            for (int j = 0;j < n;j++){
                if (i&(1<<j)){
                    sum++;
                }
            }
            if (sum == k){
                memset(b,false,sizeof(b));
                int cnt = 0;
                for (int k = 1;k <= n;k++){
                    if ((i&(1<<(k-1))) && !b[k]){
                        dfs(k);
                        cnt++;
                    }
                }
                if (cnt <= 2){
                    for (int i = 1;i <= n;i++){
                        dist[i] = inf;
                    }
                    for (int k = 1;k <= n;k++){
                        if ((i&(1<<(k-1)))){                                                       
                            bfs(k);
                        }   
                    }
                    int ma = 0;
                    for (int k = 1;k <= n;k++){
                        ma = max(ma,dist[k]);
                      //  printf("%lld ",dist[k]);
                    }
                    //printf("| %lld %lld 0000000\n",ma,i);
                    mi = min(mi,ma);
                }
            }
        }
        printf("%lld\n",mi);
    }

    return 0;
}