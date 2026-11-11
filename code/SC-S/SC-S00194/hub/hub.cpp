#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 1e6 + 10;
int cnt[N], d;
vector<int> G[N];
int at(int s, int i){
    return (s >> (i - 1)) & 1;
}
void dfs(int u, int fath, int s, int dep){
    if(at(s, u)) d = min(d, dep);
    for(int v : G[u]) if(v != fath) dfs(v, u, s, dep + 1);
}
bool vis[N];
void cov(int u, int fath, int s){
    vis[u] = 1;
    for(int v : G[u]) if(v != fath && at(s, v)){
        cov(v, u, s);
    }
}
int n, k;
bool check(int x){
    int fst = 1, cnt = 0;
    for(int i = 1; i <= (n + 1) / 2; i++){
        if(fst == x) {
            cnt++;
            fst = 1;
        }else fst++;
    }
    return cnt <= k;
}
int main(){
    freopen("hub.in", "r", stdin);
    freopen("hub.out", "w", stdout);
    int test_id, T;
    scanf("%d%d", &test_id, &T);
    while(T--){
        scanf("%d%d", &n, &k);
        for(int i = 1; i <= n; i++) G[i].clear();
        for(int i = 1; i < n; i++){
            int u, v;
            scanf("%d%d", &u, &v);
            G[u].push_back(v);
            G[v].push_back(u);
        }
        if(n <= 20){
            int U = 1 << n;
            for(int s = 1; s < U; s++) cnt[s] = cnt[s >> 1] + (s & 1);
            int ans = n + 1;
            for(int s = 1; s < U; s++) if(cnt[s] == k){
                int cnt = 0;
                for(int i = 1; i <= n; i++) vis[i] = 0;
                for(int i = 1; i <= n; i++) if(!vis[i] && at(s, i)) cov(i, 0, s), cnt++;
                if(cnt > 2) continue;
                int maxx = 0;
                for(int i = 1; i <= n; i++) if(!at(s, i)){
                    d = n + 1;
                    dfs(i, 0, s, 0);
                    maxx = max(maxx, d);
                }
                ans = min(ans, maxx);
            }
            printf("%d\n", ans);
        }else{
            int loc = n / 2, ans = 1;
            int flag = 0;
            while(loc > k){
                if(!flag || flag == 1){
                    loc--;
                    ans++;
                }else if(flag == 2){
                    loc--;
                }else if(flag == 3){
                    loc--;
                }else if(flag % 2 == 0){
                    loc --;
                    ans++;
                }else loc--;
                flag++;
            }
            printf("%d\n", ans);
        }
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}