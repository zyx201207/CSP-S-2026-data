#include<bits/stdc++.h>
using namespace std;
vector<pair<int,int>> v[500010];
int n,m,t,q;
int a[500010];
map<int,map<int,int>> w;
map<int,bool> b;
int dfs(int x,int y){
    if(y==x){
        return 0;
    }
    if(w[x][y]){
        return w[x][y];
    }
    int mn=1e9;
    for(auto i:v[x]){
        if(b[i.first]) continue;
        b[i.first]=1;
        mn=min(mn,dfs(i.first,y)+i.second);
        b[i.first]=0;
    }
    w[x][y]=mn;
    return mn;
}
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    cin>>t>>m>>n>>t>>q;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(int i=1;i<=m;i++){
        int k;
        cin>>k;
        vector<pair<int,int>> cnt;
        for(int j=1;j<=k;j++){
            int x,y;
            cin>>x>>y;
            for(auto l:cnt){
                v[x].push_back({l.first,y+l.second});
                v[l.first].push_back({x,y+l.second});
            }
            cnt.push_back({x,y});
        }
    }
    while(q--){
        b.clear();
        int x,y;
        cin>>x>>y;
        b[x]=1;
        cout<<a[x]+a[y]+dfs(x,y)<<endl;
    }
    return 0;
}
