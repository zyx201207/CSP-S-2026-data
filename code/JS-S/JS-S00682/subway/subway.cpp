#include<bits/stdc++.h>
#define endl '\n'
using namespace std;
int c,n,m,d,q;
struct nod{
    int u,w;
};
vector<nod> ve[1000009];
int cost[500009],dis[1000009];
bool vis[1000009];
int main(){
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;i++){
        cin>>cost[i];
    }
    while(n--){
        int k,a,t,lst=-1;
        cin>>k;
        for(int i=1;i<=k;i++){
            cin>>a>>t;
            ve[a].push_back({a+n,t});
            ve[a+n].push_back({a,t});
            ve[a].push_back({lst,0});
            lst=a;
        }
    }
    while(q--){
        int x,y;
        cin>>x>>y;
        cout<<cost[x]+cost[y];
    }
    return 0;
}
