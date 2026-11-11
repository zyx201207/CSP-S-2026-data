#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N=1e6+10;
vector<int> mp;
int c,t,n,k;
int main(){
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    cin>>c>>t;
    while(t--){
        cin>>n>>k;
        for(int i=1;i<=n;i++){
            int u,v;
            cin>>u>>v;
            mp[u].push_back(v);
            mp[v].push_back(u);
        }
    }
    return 0;
}
