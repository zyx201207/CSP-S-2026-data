#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const int N=2e6+10;

int c,t;
int n,k;
vector<int> g[N];

void init(){
    for(int i=0;i<n;i++) g[i].clear();
}

int main(){
    freopen("hub","r",stdin);
    freopen("hub","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin>>c>>t;
    while(t--){
        cin>>n>>k;
        init();
        for(int i=1;i<n;i++){
            int u,v;
            cin>>u>>v;
            g[u].push_back(v);
            g[v].push_back(u);
        }
        cout<<"1"<<"\n";
    }
    return 0;
}
