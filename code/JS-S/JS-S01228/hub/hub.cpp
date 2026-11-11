#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int c,t;
    cin >> c >> t;
    while(t--){
        int n,k;
        vector<vector<int>> mp;
        for(int i=1;i<=n-1;i++){
            int u,v;
            cin >> u >> v;
            mp[u].push_back(v);
            mp[v].push_back(u);
        }
        if(k==1){
            cout << 0;
            continue;
        }
    }
    return 0;
}