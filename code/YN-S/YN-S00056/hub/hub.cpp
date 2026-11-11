#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N = 1e6+5;
int c,t;
int n,k;
int u[N],v[N];
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    cin>>c>>t;
    while(t--){
        cin>>n>>k;
        for(int i=1;i<n;i++){
            cin>>u[i]>>v[i];
        }
        cout<<((n+1)/2-k)/4+1<<'\n';
    }
    return 0;
}

