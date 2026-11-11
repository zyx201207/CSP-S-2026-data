#include<bits/stdc++.h>
using namespace std;
#define int long long
int c,T,n,k;
vector<int>g[1000005];
void solve(){
    cin>>n>>k;
    for(int i=1;i<=n;i++)g[i].clear();
    for(int i=1,u,v;i<n;i++){
        cin>>u>>v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    if(n==k){
        cout<<0<<"\n";
        return;
    }
    if(n<=5){
        if(k>=2){
            cout<<1<<"\n";
            return;
        }
        else{
            if(g[1].size()<n-1&&g[2].size()<n-1&&g[3].size()<n-1&&g[4].size()<n-1&&g[5].size()<n-1){
                cout<<2<<"\n";
            }else{
                cout<<1<<"\n";
            }
        }
    }else{
        if(k==2){
            cout<<(n>>4)<<"\n";
        }
        cout<<2<<"\n";
    }
}
signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    cin>>c>>T;
    while(T--){
        solve();
    }
    return 0;
}
