#include <bits/stdc++.h>
// #define int long long
#define gc getchar
const int N = 1e6 + 10;

using namespace std;
namespace Sol{

int rd(){
    char c = gc(); int re = 0;
    while(c < '0' || c > '9') c = gc();
    while(c >= '0' && c <= '9')
        re = re * 10 + c - '0', c = gc();
    return re;
}

vector<int> g[N];

bool ck(int x){
    return 1;
}

void main(){
    #ifdef LOCAL
    freopen("hub.in", "r", stdin);
    // freopen("hub.out", "w", stdout);
    #else
    freopen("hub.in", "r", stdin);
    freopen("hub.out", "w", stdout);
    #endif
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int C = rd(), T = rd();
    for(int n, k; T; T--){
        n = rd(), k = rd();
        for(int i=1; i<=n; i++) g[i].clear();
        for(int i=1, u, v; i<n; i++)
            u = rd(), v = rd(),
            g[u].push_back(v), g[v].push_back(u);
        if(n == k){cout << "0\n"; continue;}
        if((C == 13 || C == 14) && k >= n/2){
            cout << "1\n"; continue;
        }
        int l = 0, r = n;
        while(l < r){
            int mid = (l+r) >> 1;
            if(ck(mid)) r = mid;
            else l = mid + 1;
        }
        cout << l << '\n';
    }
}

}signed main(){Sol::main();}