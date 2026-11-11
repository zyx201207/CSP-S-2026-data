#include<bits/stdc++.h>
using namespace std;
const int N=5e5+10;
struct node{
    int idx;
    int line;
};
int w[N],t[N][N];
vector<node> h[N];
int vis[N];
bool ok;
int dfs(int x,int ed,int ti,int line){
        if(x==ed)return ti+w[ti]+t[line][x];
        int mi=LLONG_MAX;
        for(auto y:h[x]){
            if(vis[y.idx])continue;
            else{ok=true;}
            if(y.idx==line){
                    vis[y.idx]=true;
                mi=min(mi,dfs(y.idx,ed,ti,line));


            }else {
                vis[y.idx]=true;
                int nt=ti+t[line][y.idx]+t[y.line][y.idx];
                mi=min(mi,dfs(y.idx,ed,nt,y.line));
            }
            vis[y.idx]=false;
        }
        if(ok==false)return 0;
        return mi;
}
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    int c,n,m,d,q;
    for(int i=1;i<=n;i++)cin>>w[i];
    for(int i=1;i<=n;i++){
        int k;cin>>k;
        int lst=0;
        for(int j=1;j<=k;j++){
            int a,tt;
            cin>>a>>tt;
            if(j!=1)
            h[lst].push_back({a,i}),
            h[a].push_back({lst,i}),
            t[i][j]=tt;
            lst=a;
        }

    }
    while(q--){
        int s,e;
        cin>>s>>e;
        int minn=LLONG_MAX;
        for(auto z:h[s]){
                ok=true;
            minn=min(minn,dfs(s,e,t[z.line][s],z.line));
        }
        cout<<minn<<'\n';
    }
    return 0;
}
