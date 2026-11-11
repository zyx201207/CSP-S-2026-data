#include<iostream>
#include<cmath>
#include<cstdio>
#include<algorithm>
#include<vector>
#include<queue>
using namespace std;
const int M=5*1e5+7;
int az[M];
int c,n,m,d,q;
struct lc{
    int b,tm;
};
vector<lc> z[M];
int k[505];
queue<int> qp;
long long ans=0;
long long vis[M];
void bfs(int l,int r){
    for(int i=1;i<=m;i++){
        vis[i]=-1;
    }
    vis[l]=0;
    qp.push(l);
    while(!qp.empty()){
        int d=qp.front();
        //cout<<d<<" "<<z[d].size()<<"\n";
        qp.pop();
        if(d==r){
            ans=vis[d]+az[d];
            return;
        }
        int len=z[d].size();
        for(int i=0;i<len;i++){
            if(vis[z[d][i].b]==-1){
                qp.push(z[d][i].b);
                vis[z[d][i].b]=vis[d]+z[d][i].tm;
            }
        }
    }
}
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;i++){
        cin>>az[i];
    }
    vector<lc> lx;
    for(int i=1;i<=n;i++){
        cin>>k[i];
        lx.clear();
        for(int j=1;j<=k[i];j++){
            int zb,xj;
            cin>>zb>>xj;
            lx.push_back({zb,xj});
        }
        for(int j=0;j<k[i];j++){
            if(j!=0){
                z[lx[j].b].push_back({(lx[j-1].b),(lx[j-1].tm)});
            }
            if(j!=k[i]-1){
                z[lx[j].b].push_back({(lx[j+1].b),(lx[j+1].tm)});
            }
        }
    }
    while(q--){
        int lx,rx;
        cin>>lx>>rx;
        bfs(lx,rx);
        cout<<ans<<"\n";
    }
    return 0;
}
