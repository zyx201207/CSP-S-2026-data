#include <bits/stdc++.h>
using namespace std;
int c,t;
int n,k;
int u,v;
vector<int> g[1000005];
int main(){
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    cin >> c >> t;
    while(t--){
        cin >> n >> k;
        for(int i = 1;i < n;i++){
            cin >> u >> v;
            g[u].push_back(v);
            g[v].push_back(u);
        }
        int m = (n - 1) / 2;
        int ans;
        if (k >= n) ans = 0;
        else if (k >= m) ans = 1;
        else{
            int c = n / 2;
            ans = ((c - k) + 1) / 2 + 1;
        }
	cout << ans;
    }
    return 0;
}
