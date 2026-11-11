# include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 5;

int c, T, n, k;
vector <int> g[N];
int main(){
    freopen("hub.in", "r", stdin);
    freopen("hub.out", "w", stdout);
    scanf("%d%d", & c, & T);
    while (T --){
        scanf("%d%d", & n, & k);
        for (int i = 0; i <= n; i ++) g[i].clear();
        for (int i = 1, u, v; i < n; i ++){
            scanf("%d%d", & u, & v);
            g[u].push_back(v);
            g[v].push_back(u);
        }
        printf("%d\n", n / k - 1);
    }
    return 0;
}
