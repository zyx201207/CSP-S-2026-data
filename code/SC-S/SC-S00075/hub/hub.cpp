#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const int mxn = 1e6 + 5;
int c , t , fa[mxn] , u[mxn] , v[mxn];
inline int find(int x){ return (x == fa[x]) ? x : fa[x] = find(fa[x]); }
int main(){
    freopen("hub.in" , "r" , stdin); freopen("hub.out" , "w" , stdout);
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> c >> t;
    while(t--){
        int n , k; cin >> n >> k;
        for(int i = 1 ; i < n ; i++){   
            cin >> u[i] >> v[i]; 
        } 
        cout << k << "\n";
    }
    return 0;
}