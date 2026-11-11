#include <iostream>

using namespace std;
const int N = 5e5 + 1000;
int a[N], ans[N], b[N];
int n, m;

void init(){
    freopen("card.in", "r", stdin);
    freopen("card.out", "w", stdout);
    cin >> n >> m;
    for(int i = 1; i <= n; ++i){
        cin >> a[i];
        b[i] = a[i];
    }
}

void solve(){
    if(m == 1){
        ans[1] = n;
        cout << ans[1] << endl;
        return;
    }
    for(int i = 1; i <= n; ++i){
        int g = n;
        for(int j = 1; j <= n; ++j){
            int x = g;
            for(int p = 1; p <= n; ++p){
                if(b[j] == a[p]){
                    for(int q = p; q <= g; ++q)
                        a[q] = 0;
                    g = p;
                    a[g] = b[j];
                }
            }
            if(x == g)
                a[g + 1] = b[j];
        }
        for(int j = 1; j <= g; ++j)
            ans[a[j]] += 1;
    }
    for(int i = 1; i <= m; ++i)
        cout << ans[i] << " ";
    cout << endl;
}

int main(){
    init();
    solve();
    return 0;
}
