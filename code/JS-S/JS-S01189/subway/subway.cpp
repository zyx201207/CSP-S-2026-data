#include<bits/stdc++.h>
using namespace std;
const int M=5e5+5,N=505;
struct node{
    int id,T;
};
int c,n,m,d,q,cnttime,mntime;
int ltl[M];
vector<node> g[M];
vector<node> gg[M];
void dfs(int u,int to,int onwhat,int cnttime){
    if(u==to){
        int tmp;
        for(auto v:g[onwhat]){
            if(v.id==u){tmp=v.T;break;}
        }
        mntime=min(mntime,cnttime+tmp+ltl[u]);
        return;
    }
    for(int i=1;i<=n;i++){
        bool f=0;int tmp;
        for(auto v:g[i]){
            if(f&&onwhat==i){
                dfs(v.id,to,i,cnttime);
            }
            else if(f){
                if(onwhat==0){
                    dfs(v.id,to,i,cnttime+tmp);
                }
                for(auto w:g[onwhat]){
                    if(w.id==u){
                        dfs(v.id,to,i,cnttime+w.T+tmp);
                    }
                }
            }
            if(v.id==u)f=1,tmp=v.T;
        }
    }
    return;
}
void dfs2(int u,int to,int cnttime){
    if(u==to){
        mntime=min(mntime,cnttime+ltl[u]);
        return;
    }
    for(auto v:gg[u]){
        dfs2(v.id,to,cnttime+v.T);
    }
}
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;i++)cin>>ltl[i];
    if(7<=c&&c<=11){
        for(int i=1;i<=n;i++){
            int k;cin>>k;
            int x,y,z,t;cin>>x>>y>>z>>t;
            gg[x].push_back({z,y+t});
        }
        for(int i=1;i<=q;i++){
            mntime=1e9;
            int x,y;cin>>x>>y;
            dfs2(x,y,ltl[x]);
            cout<<mntime<<'\n';
        }
    }
    for(int i=1;i<=n;i++){
        int k;cin>>k;
        for(int j=1;j<=k;j++){
            int x,y;cin>>x>>y;
            g[i].push_back({x,y});
        }
    }
    for(int i=1;i<=q;i++){
        mntime=1e9;
        int x,y;cin>>x>>y;
        dfs(x,y,0,ltl[x]);
        cout<<mntime<<'\n';
    }
}
