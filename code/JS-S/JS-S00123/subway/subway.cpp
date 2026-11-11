#include<bits/stdc++.h>
using namespace std;
struct node{
    int line;
    int time;
};
void dfs(int pos,int ed){
    if(pos==ed){

    }
    else{

    }
}
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    ios::sync_with_stdio();
    cin.tie(0);
    cout.tie(0);
    int c,n,m,d,q;
    cin>>c>>n>>m>>d>>q;
    vector<int> w(m+1);
    vector<node> g(m+1);
    vector<int> to(n+1);
    for(int i=1;i<=m;i++){
        cin>>w[i];
    }
    for(int i=1;i<=n;i++){
        int k;
        cin>>k;
        while(k--){
            int a,b;
            cin>>a>>b;
            to[i].push_back(a);
            g[a].push_back({i,b});
        }
    }
    for(int i=1;i<=q;i++){
        int st,ed;
        cin>>st>>ed;
        dfs(st,ed);
    }
    return 0;
}
