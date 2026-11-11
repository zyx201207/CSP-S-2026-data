#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    int c,t;
    cin>>c>>t;
    int mi=INT_MAX;
    while(t--){
        int n,k;
        cin>>n>>k;
        for(int i=1;i<=n;i++){
            int u,v;
            cin>>u>>v;
            long long cnt=v-u;
            if(mi>cnt){
                mi=cnt;
            }
        }
        cout<<mi<<'\n';
    }
    return 0;
}
