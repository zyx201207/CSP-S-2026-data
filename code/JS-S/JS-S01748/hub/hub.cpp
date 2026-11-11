#include <bits/stdc++.h>
using namespace std;

long long a[2000001];

int main(){
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    long long c,t;
    cin >> c >> t;
    while(t--){
        long long n,k;
        cin >> n >> k;
        for(int i = 1;i < n;i++){
            int u,v;
            cin >> u >> v;
        }
        cout << n/k-1;
    }
    return 0;
}
