#include<bits/stdc++.h>
using namespace std;
int c,t,n,k;

int main(){
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    cin >> c >> t;
    while(t--){
        cin >> n >> k;
        for(int i = 1;i<=n;i++){
            int v,u;
            cin >> v >> u;
        }
        cout << n-k;
    }
    return 0;
}
