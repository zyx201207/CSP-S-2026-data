#include<bits/stdc++.h>
using namespace std;
int c,t;
vector<int>edge[1000001];
int main(){
    freopen(hub.in,"r",stdin);
    freopen(hub.out,"w",stdout);
    std::ios::sync_with_stdio(0);
    std::cin.tie(nullptr);
    cin>>c>>t;
    while(t--){
        int n;
        cin>>n;
        for(int i=1;i<n;i++){
            int u,v;
            cin>>u>>v;
            edge[u].push_back(v);
            edge[v].push_back(u);
        }
    }

    return 0;
}
