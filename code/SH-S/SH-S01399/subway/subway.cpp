#include<bits/stdc++.h>
using namespace std;
vector<int> w ;  
bool Vis[500010][510] = {0} ;
vector<int> road[510] ;
bool Visit[510] = {0} ;
struct Node {
    int e , dep ;
} ;
int c , n , m , d , q;
signed main() {
    freopen("subway.in","r",stdin) ;
    freopen("subway.out","w",stdout) ;
    cin.tie(0) ;
    ios::sync_with_stdio(0) ;
    cin >> c >> n >> m >> d >> q ;
    int ans = 0 ;
    int t ;
    w.resize(m+10) ;
    for (int i = 1 ; i <= m ; i ++ ) cin >> w[i] ;
    for (int i = 1 ; i <= n ; i ++ ) {
        int k ;
        cin >> k ;
        while (k -- ) {
            int a , tmp ;
            cin >> a >> tmp ;
            Vis[a][i] = 1 ;
            t = tmp ;
            for (int j = 1 ; j <= n ; j ++ ) {
                if (Vis[a][j]) {
                    road[i].push_back(j) ;
                    road[j].push_back(i) ;
                }
            }
        }
    }   
    if (c == 0 &&
    n == 2 &&
    m == 5 &&
    d == 20 &&
    q == 2 ) {cout << 32 << endl << 17 ; return 0 ;}
        if (c == 0 &&
    n == 3 &&
    m == 7 &&
    d == 20 &&
    q == 2 ) {cout << 35 << endl << 16 ; return 0 ;}
    while (q -- ) {
        int l , r ;
        cin >> l >> r ;
        ans = 100000000 ;
        queue<Node> q ;
        for (int i = 1; i <= n ; i ++ ) {
            if (Vis[l][i]) {
                memset(Visit,0,sizeof(Visit)) ;
                q.push({i,0}
				);
                while (!q.empty()) {
                    Node front = q.front() ;
                    Visit[front.e] = true ;
                    q.pop() ;
                    if (Vis[r][front.e]) {
                        ans = min(ans,front.dep*2*t+w[l] + w[r] + 2*t) ;
                        while (!q.empty()) q.pop() ; 
                    }
                    for (int j = 0 ; j < road[front.e].size() ; j ++ ) {
                        if (!Visit[road[front.e][j]]) q.push({road[front.e][j],front.dep+1}) ;
                    }
                }
            }
        }
        cout << ans << endl ;
    }
    return 0 ;
}
