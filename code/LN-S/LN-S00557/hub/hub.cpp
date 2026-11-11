#include<bits/stdc++.h>
using namespace std;
int main(){
    // freopen("hub.in","r",stdin);
    // freopen("hub.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    int c,t;
    cin>>c>>t;
    while(t--){
        int n,k;
        cin>>n>>k;
        int zx=2147485647;
        for(int i=1;i<=n-1;i++){
            int u,v;
            cin>>u>>v;
            if(abs(v-u)<zx){
                zx=abs(v,u);
            }
        }
        cout<<zx<<"\n";
    }
    return 0;
}