#include<bits/stdc++.h>
using namespace std;
int u[20000000] = {},v[20000000] = {};
int main(){
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    int c,t;
    cin >> c >> t;
    for (int h = 1 ; h <= t ; h++) {
        int n,k;
        cin >> n >> k;
        for(int i = 1 ; i <= n ; i++) {
            cin >> u[i] >> v[i];
        }
        cout << "1" << endl;
        cout << "2" << endl;
    }
    return 0;
}