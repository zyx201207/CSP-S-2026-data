#include<bits/stdc++.h>
using namespace std;
const int N=1e6+5;
int c,t,n,k;
vector<int>g[N];
int main(){
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    cin>>c>>t;
    while(t--){
        cin>>n>>k;
        for(int i=1,u,v;i<n;i++)
            cin>>u>>v,g[u].push_back(v),g[v].push_back(u);
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
