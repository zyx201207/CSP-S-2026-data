#include<bits/stdc++.h>
#define int long long
using namespace std;
inline int read() {
     int x=0,f=0,ch=getchar();
     while(!isdigit(ch)) f|=ch=='-',ch=getchar();
     while(isdigit(ch)) x=(x<<1)+(x<<3)+(ch^48),ch=getchar();
     return f?-x:x;
}
const int M=1e4+5;
const int N=505;
int n,m;
int c,d,q;
int w[N],f[N],h[N];
vector<pair<int,int> >g[N*M];
int cnt;
priority_queue<pair<int,int>,vector<pair<int,int> >,greater<pair<int,int> > >e;
int dp[M][M];
int dis[M*N];
bool vis[M*N];
void dij(int s) {
    for(int i=1;i<=n*m+m;i++) dis[i]=1e18,vis[i]=false;
    e.push(make_pair(0,s));dis[s]=0;
    while(!e.empty()) {
        pair<int,int> y=e.top();
        int t=y.second;
        //cout<<666<<' '<<t<<'\n';
        e.pop();
        if(vis[t]) continue;vis[t]=true;
        for(auto v:g[t]) {
            //if(s==1) cout<<t<<' '<<v.first<<' '<<dis[t]<<' '<<dis[v.first]<<'\n';
            if(dis[t]+v.second<dis[v.first]) {
                //if(s==1) cout<<v.first<<'\n';
                dis[v.first]=dis[t]+v.second;
                e.push(make_pair(dis[v.first],v.first));
            }
        }
    }
    for(int i=1;i<=m;i++) {
        dp[s][i]=dis[i];
        //if(s==1) cout<<1<<' '<<i<<' '<<dis[i]<<' '<<'\n';
    }
}

signed main() {
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    c=read(),n=read(),m=read(),d=read(),q=read();
    //cout<<111<<'\n';
    for(int i=1;i<=m;i++) w[i]=read();
    for(int i=1;i<=n;i++) {
        int k=read();
        //cout<<k<<'\n';
        for(int j=1;j<=k;j++) {
            f[j]=read();h[j]=read();
            f[j]=i*m+f[j];
        }
        for(int j=1;j<k;j++) {
            g[f[j]].push_back(make_pair(f[j+1],0));
        }
        for(int j=1;j<=k;j++) {
            int id=f[j]-i*m;
            //cout<<id<<' '<<f[j]<<' '<<h[j]<<'\n';
            g[f[j]].push_back(make_pair(id,h[j]));
            g[id].push_back(make_pair(f[j],h[j]));
        }
    }
    //for(int i=0;i<g[2].size();i++) {
    //cout<<g[2][i].first<<'\n';
    //}
    for(int i=1;i<=n;i++) {
        dij(i);
    }
    while(q--) {
        int x,y;
        x=read(),y=read();
        printf("%lld\n",dp[x][y]+w[x]+w[y]);
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
