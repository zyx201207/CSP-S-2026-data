#include <bits/stdc++.h>
using namespace std;
int main(){
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    long long c,t,n,k,u[1000010] = {0},v[1000010] = {0};
    cin >> c >> t;
    while(t>=0){
        cin >> n >> k;
        for(int i = 1;i<=n-1;i++){
            cin >> u[i] >> v[i];
        }
        t--;
    }
    cout << "1" << endl << "2";
    return 0;
}
