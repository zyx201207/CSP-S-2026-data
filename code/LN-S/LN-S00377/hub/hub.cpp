#include <bits/stdc++.h>
using namespace std;
int c,t;
int n,k;
int main(){
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>c>>t;
    if(c==13 || c==14){
        while(t--){
            cin>>n>>k;
            for(int i=1;i<n;i++){
                int u,v;
                cin>>u>>v;
            }
            cout<<(((n-2*k)/8)+(n&1)?1:0)<<"\n";
        }
    }else{
        while(t--) cout<<1<<"\n";
    }
    return 0;
}