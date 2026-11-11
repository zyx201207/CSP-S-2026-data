#include <bits/stdc++.h>
using namespace std;

int n,k;

int main(){
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    int c,t;
    cin >> c >> t;
    while(t--){
        cin >> n >> k;
        for(int i = 1; i <= n; i++){
            int x;
            cin >> x;
            cout << x << '\n';
        }
    }
    return 0;
}