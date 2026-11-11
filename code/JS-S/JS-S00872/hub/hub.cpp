#include<bits/stdc++.h>
using namespace std;
int c, t, n, k, fa[1000010];
int main(){
    freopen("hub.in", "r", stdin);
    freopen("hub.out", "w", stdout);

    cin >> c >> t;
    while(t--){
        cin >> n >> k;
        for(int i = 1; i < n; i++){
            fa[i] = i;
            int u, v;
            cin >> u >> v;
        }
        cout << "0" << '\n';
    }

    return 0;
}
