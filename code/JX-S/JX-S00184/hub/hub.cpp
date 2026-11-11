#include <bits/stdc++.h>
using namespace std;
int main(){
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int c,t;
    cin >> c >> t;
    int n[6],k[6];
    int u[1005][1005],v[1005][1005];
    for (int i = 1;i<=t;i++){
        cin >> n[i] >> k[i];
        for (int j = 1;j<=n[i]-1;j++){
            cin >> u[i][j] >> v[i][j];
        }
    }
    return 0;
}
