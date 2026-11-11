#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N=1e6+5;
ll c,t,n,k;
ll u[N],v[N];

int main(){
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);

    ios::sync_with_stdio(0);
    cin.tie(0);

    cin>>c>>t;
    while(t--){
        cin>>n>>k;
        for(int i=1;i<=n-1;i++){
            cin>>u[i]>>v[i];
        }
        cout<<u[1]<<v[1];
    }
    return 0;
}
