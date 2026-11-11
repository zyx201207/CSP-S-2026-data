#include <bits/stdc++.h>
#define ll long long
using namespace std;
struct edge{
    int u;
    int v;
    int flag;
};
ll n,m,c,d,q;
ll w[500005],t[505][500005];
vector <int> sub[505];
vector <edge> tu[500005];
//vector <int> tu[500005];
//vector <int> fa[500005];
int minn=INT_MAX;
void dfs(int u,edge fa,int ans,int v){
     for(auto e:tu[u]){
        if(fa.u==e.v){
            continue;
        }
        if(e.v==v){
            if((e.flag)!=fa.flag) ans+=t[fa.flag][u]+t[e.flag][u];
            ans+=t[e.flag][e.v];
            minn=min(minn,ans);
            return ;
        }
        if(e.flag==fa.flag){
            dfs(e.v,e,ans,v);
        }
        else if(fa.flag==0){
            dfs(e.v,e,ans+t[e.flag][u],v);
        }
        else{
            dfs(e.v,e,ans+t[fa.flag][u]+t[e.flag][u],v);
        }
     }
}
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;i++){
        cin>>w[i];
    }
    for(int i=1;i<=n;i++){
        int k;
        cin>>k;
        for(int j=1;j<=k;j++){
            int x;
            cin>>x;
            sub[i].push_back(x);
            cin>>t[i][x];
        }
        for(int j=0;j<k-1;j++){
            int x=sub[i][j];
            int y=sub[i][j+1];  
            tu[x].push_back((edge){x,y,i});
            tu[y].push_back((edge){y,x,i});
        }
    }
    while(q--){
        minn=INT_MAX;
        int u,v;
        cin>>u>>v;
        dfs(u,{0,u,0},w[u]+w[v],v);
        cout<<minn<<endl;
    }
}