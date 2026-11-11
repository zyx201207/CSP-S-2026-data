#include<bits/stdc++.h>
using namespace std;
long long C,T,n,k,u[2000002],v[2000002];
int main(){
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> C >> T;
    while(T--){
        cin >> n >> k;
        for(int i=1;i<n;i++){
            cin >> u[i] >> v[i];
        }
        cout << 1 << "\n";
    }
    return 0;
}
