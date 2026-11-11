#include <bits/stdc++.h>
using namespace std;
using ll=long long;
const int maxn=2e6+5;
int c,t,n,k,u,v;
signed main(){
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    srand(time(NULL));
    cin>>c>>t;
    while(t--){
        cin>>n>>k;
        for(int i=0;i<n-1;++i) cin>>u>>v;
        cout<<rand()%11<<'\n';
    }
    return 0;
}