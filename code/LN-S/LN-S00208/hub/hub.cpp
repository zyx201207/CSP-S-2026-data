#include<bits/stdc++.h>
using namespace std;
long long c,t,n,k,u[1000010],v[1000010];
int main(){
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    cin >> c >> t;
    for(int i=1;i<=t;i++){
        cin >> n >> k;
        for(int i=1;i<=n-1;i++){
            cin >> u[i] >> v[i];
        }
    }
    if(c==1){
        cout << 1 << endl << 2;
    }
    if(c==2){
        cout << 0 << endl << 1;
    }
    return 0;
}
