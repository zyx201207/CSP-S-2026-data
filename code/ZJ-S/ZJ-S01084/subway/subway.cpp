#include<bits/stdc++.h>
#define For(i,j,k) for(auto i=(j);i<=(k);i++)
#define dFor(i,j,k) for(auto i=(j);i>=(k);i--)
using namespace std;
#define MAXN 505
#define MAXM 500005
#define INF (1ll<<60)
int c,n,m,d,q,w[MAXM];
long long dis[MAXN][MAXN];
vector<pair<int,int>> e[MAXM];
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>c>>n>>m>>d>>q;
    For(i,1,m){
        cin>>w[i];
    }
    For(i,1,n){
        int k;
        cin>>k;
        For(j,1,k){
            int u,t;
            cin>>u>>t;
            e[u].push_back({i,t});
        }
    }
    For(i,1,n){
        For(j,1,n){
            if(i==j) dis[i][j]=0;
            else dis[i][j]=INF;
        }
    }
    For(u,1,m){
        for(auto p1:e[u]){
            int v1=p1.first,w1=p1.second;
            for(auto p2:e[u]){
                int v2=p2.first,w2=p2.second;
                dis[v1][v2]=min(dis[v1][v2],(long long)w1+w2);
            }
        }
    }
    For(i,1,n){
        For(u,1,n){
            For(v,1,n){
                dis[u][v]=min(dis[u][v],dis[u][i]+dis[i][v]);
            }
        }
    }
    For(i,1,q){
        int u,v;
        cin>>u>>v;
        long long ans=INF;
        for(auto p1:e[u]){
            int v1=p1.first,w1=p1.second;
            for(auto p2:e[v]){
                int v2=p2.first,w2=p2.second;
                ans=min(ans,dis[v1][v2]+w1+w2);
            }
        }
        ans+=w[u]+w[v];
        cout<<ans<<'\n';
    }
    return 0;
}
/*
g++ -O2 -std=c++14 -Wall -Wextra -Wshadow -o subway subway.cpp
*/