#include<bits/stdc++.h>
using namespace std;
int c,t,n,k,u,v,f=1e5;
int main(){
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>c>>t;
    while(t--){
        cin>>n>>k;
        for(int i=1;i<=n;i++){
            cin>>u>>v;
            if((v-u)<f){
                f=v-u;
            }
        }
        cout<<f;
    }
    return 0;
}
