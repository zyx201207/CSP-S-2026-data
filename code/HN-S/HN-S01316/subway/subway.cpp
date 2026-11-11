#include<bits/stdc++.h>
#define int long long
using namespace std;
const int INF=1e18;
const int N=5e5+10;
int c,n,m,d,q,w[N];
int dis[510][510];
struct edge{
    int v,w;
};
vector<edge>e[N];
signed main(){
    ios::sync_with_stdio(false);cin.tie(0),cout.tie(0);
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=n;++i)for(int j=1;j<=n;++j)if(i!=j)dis[i][j]=INF;
    for(int i=1;i<=m;++i)cin>>w[i];
    for(int i=1;i<=n;++i){
        int tmp;cin>>tmp;
        while(tmp--){
            int tar,D;cin>>tar>>D;
            e[tar].push_back((edge){i,D});
        }
    }
    for(int i=1;i<=m;++i){
        for(int tmp1=0;tmp1<(int)e[i].size();++tmp1){
            for(int tmp2=tmp1+1;tmp2<(int)e[i].size();++tmp2){
                edge U=e[i][tmp1],V=e[i][tmp2];
                int u=U.v,v=V.v,wid=U.w+V.w;
                dis[v][u]=min(dis[v][u],wid);
                dis[u][v]=min(dis[u][v],wid);
            }
        }
    }
    for(int k=1;k<=n;++k){
        for(int i=1;i<=n;++i){
            for(int j=1;j<=n;++j){
                dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
            }
        }
    }
    while(q--){
        int u,v;cin>>u>>v;
        int ans=INF;
        for(auto U:e[u]){
            for(auto V:e[v]){
                int clu=U.v,clv=V.v,wid=U.w+V.w;
                ans=min(ans,dis[clu][clv]+w[u]+w[v]+wid);
            }
        }
        cout<<ans<<'\n';
    }
    return 0;
}
//time ./a                                                                      
//size ./a                                                                      
// /usr/bin/time -v ./a                                                         
//-std=c++14 -O2                                                                
//-std=c++14 -Wall -Wextra -Wconversion -Wshadow -fsanitize=undefined -fsanitize=address -D_GLIBCXX -g                                                                    
//Password: Oct31==Dec25?                                                       
//Do think twice. Good luck.
//g++ -o a subway.cpp -std=c++14 -O2 -static
// diff -a -b subway.out subway7.ans


