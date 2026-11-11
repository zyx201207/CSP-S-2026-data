#include <bits/stdc++.h>
using namespace std;
int main(){
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    int c,t;
    cin >> c >> t;
    while (t--){
        int n,k;
        cin >> n >> k;
        vector<int>a[n+1];
        for (int i=0;i<n-1;i++){
            int u,v;
            cin >> u >> v;
            a[u].push_back(v);
            a[v].push_back(u);
        }
        cout << n-1;
    }
    return 0;
}
