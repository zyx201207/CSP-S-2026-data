#include<bits/stdc++.h>
using namespace std;
const int N=500*2*500005;
int c,n,m,d,q;
char vis[N];
struct node{
    int v,w;
};
vector<node> G[N];
void dfs(int s,int e,int num){
    if(vis[s]){
        return ;
    }
    if(s==e){
        cout<<num<<endl;
        return ;
    }
    vis[s]=true;
    for(auto ch : G[s]){
        if(!vis[ch.v]){
            num+=ch.w;
            vis[ch.v]=true;
            dfs(ch.v,e,num);
            vis[ch.v]=false;
        }
    }
    return ;
}
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>c>>n>>m>>d>>q;
    for(int i=0;i<m;i++){
        int w;
        cin>>w;
        G[n+i].push_back({n+i+m,w});
        G[n+i+m].push_back({n+i,w});
    }
    for(int i=0;i<n;i++){
        int x;
        cin>>x;
        for(int j=0;j<x;j++){
            int a,t;
            cin>>a>>t;
            G[i].push_back({a,t});
            G[a].push_back({i,t});
        }
    }
    for(int i=1;i<=q;i++){
        int st,en;
        cin>>st>>en;
        memset(vis,0,sizeof(vis));
        dfs(st+n+m-1,en+n+m-1,0);
    }
    return 0;
}