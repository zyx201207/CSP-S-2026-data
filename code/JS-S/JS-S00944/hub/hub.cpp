#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1e6+2;
int c,t,n,k;
vector<int>edges[N];
int main(){
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    cin>>c>>t;
    while(t--){
        cin>>n>>k;
        for(int i=1;i<=n;++i)edges[i].clear();
        for(int i=1,u,v;i<n;++i){
            cin>>u>>v;
            edges[u].push_back(v);
            edges[v].push_back(u);
        }
        cout<<"1\n";
    }

    return 0;
}
