#include<bits/stdc++.h>
using  namespace std;
#define ll long long

int main(){
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    vector<int>a[2000006];
    int c,t;
    cin>>c>>t;
    while(t--){
        int n,k;
        cin>>n>>k;
        for(int i=1;i<n;i++){
            int u,v;
            cin>>u>>v;
            a[u].push_back(v);
            a[v].push_back(u);
        }

    }
    return 0;
}
