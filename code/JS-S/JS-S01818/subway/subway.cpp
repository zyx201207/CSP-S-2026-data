#include<bits/stdc++.h>
#define int long long
#define r(x) x=read()
#define w(x) write(x)
#define sp putchar(' ')
#define en putchar('\n')
using namespace std;
int read(){int x=0,f=1;char ch=getchar();while(!isdigit(ch)) f=(ch=='-'?-f:f),ch=getchar();while(isdigit(ch)) x=(x<<1)+(x<<3)+(ch^48),ch=getchar();return x*f;}
void write(int x){if(x<0) x=-x,putchar('-');if(x>9) write(x/10);putchar(x%10^48);}
const int N=511;
const int M=5e5+10;
const int inf=1e18;
int c,n,m,d,q;
vector<pair<int,int>> G[N+M];
int w[M];
int dis[M+N];
int vis[M+N];
priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
void dij(int s){
    for(int i=1;i<=m+n;i++) dis[i]=inf,vis[i]=0;
    dis[s]=0;
    pq.push(make_pair(0,s));
    while(!pq.empty()){
        int u=pq.top().second;
        pq.pop();
        if(vis[u]) continue;
        vis[u]=1;
        for(auto it:G[u]){
            int v=it.first;
            int w=it.second;
            if(dis[v]>dis[u]+w){
                dis[v]=dis[u]+w;
                pq.push(make_pair(dis[v],v));
            }
        }
    }
}
signed main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    r(c),r(n),r(m),r(d),r(q);
    for(int i=1;i<=m;i++) r(w[i]);
    for(int i=1;i<=n;i++){
        int r(k);
        for(int j=1;j<=k;j++){
            int r(v),r(w);
            G[m+i].push_back(make_pair(v,w));
            G[v].push_back(make_pair(m+i,w));
        }
    }
    while(q--){
        int r(x),r(y);
        dij(x);
        w(w[x]+w[y]+dis[y]),en;
    }
    return 0;
}
/*
0 2 5 20 2
4 1 9 2 5
3 1 5 2 7 4 6
3 2 3 3 4 5 7
1 3
1 2

0 3 7 20 2
8 3 6 1 7 2 9
3 1 4 2 5 5 100
3 2 6 3 1 7 2
4 3 2 5 100 4 6 6 7
1 6
2 3
*/
