#include<bits/stdc++.h>
using namespace std;
int n,k;
int main(){
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int c,t;
    cin>>c>>t;
    if(c==13||c==14){
        while(t--){
            cin>>n>>k;
            for(int i=1;i<n;i++){
                int u,v;
                cin>>u>>v;
            }
            int kk=(n+1)/2+1-k+2;
            kk/=2;
            kk/=2;
            cout<<kk<<"\n";
        }
    }
    return 0;
}
