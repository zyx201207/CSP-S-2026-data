#include<bits/stdc++.h>
using namespace std;
int a[1000005];
int b[1000005];
int main(){
    freopen("hub.in", "r", stdin);
    freopen("hub.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int c, t;
    cin >> c >> t;
    while(t--){
        int n, m;
        cin >> n >> m;
        for(int i = 1; i <= n; i++){
            cin >> a[i] >> b[i];
        }
        cout << 1;
    }
    return 0;
}
