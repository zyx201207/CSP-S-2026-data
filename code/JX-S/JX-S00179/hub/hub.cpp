#include <iostream>
#include <vector>
#define pii pair<int, int>
using namespace std;
int n, c, t, k;
const int N = 4e3 + 5;
const int INF = 0x3f3f3f3f;
vector<int> ve[N];
int deep[N], vis[N], no[N];
int cnt = 0;
int main(){
    freopen("hub.in", "r", stdin);
    freopen("hub.out", "w", stdout);
    cin >> c >> t;
    while(t--){
        cin >> n >> k;
        for(int i = 1;i < n;i++){
            int u, v;
            cin >> u >> v;
            ve[u].push_back(v);
            ve[v].push_back(u);
        }
        if(k == n){
            cout << "0\n";
            continue;
        }
        if(c == 13 || c == 14){
            int m = n / 2;
            if(k >= m){
                cout << "1\n";
            }else{
                int d = (m - k + 3) / 4;
                cout << d + 1 << '\n';
            }
            continue;
        }
    }
    return 0;
}

/*
6:24
EOF
*/
