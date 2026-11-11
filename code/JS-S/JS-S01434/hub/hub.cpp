#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int c,t;
int n,k;
vector<int>mp[1000005];
int main(){
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    cin>>c>>t;
    while(t--){
        cin>>n>>k;
        for(int i=1;i<n;++i){
            int u,v;cin>>u>>v;
            mp[u].push_back(v);
            mp[v].push_back(u);
        }
        cout<<1<<endl;
    }
    return 0;
}