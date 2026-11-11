#include<bits/stdc++.h>
using namespace std;
int c,t;
int n,k;
vector<int> eg[2000005];
int fa[2000005];
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    cin>>c>>t;
    while(t--){
        cin>>n>>k;
        for(int i=0;i<n-1;i++){
            int u,v;
            cin>>u>>v;
            eg[u].push_back(v);
            eg[v].push_back(u);
        }
        cout<<n/2;
    }
    return 0;
}