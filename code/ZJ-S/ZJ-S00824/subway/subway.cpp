#include<bits/stdc++.h>
using namespace std;
const int N=505,M=500005;
const long long INF=0x3f3f3f3f3f3f3f3f;
inline void checkmin(long long& x,long long y){x=min(x,y);}
long long val[M],g[N][N];
vector<pair<int,long long>> node[N],vec[M];
int main(){
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    int Case,n,m,d,q;
    cin >> Case >> n >> m >> d >> q;
    for(int i=0;i<m;++i) cin >> val[i];
    for(int i=0;i<n;++i){
        int k;
        cin >> k;
        while(k--){
            int u;
            long long t;
            cin >> u >> t;
            --u;
            node[i].push_back(make_pair(u,t));
            vec[u].push_back(make_pair(i,t));
        }
    }
    memset(g,0x3f,sizeof(g));
    for(int i=0;i<n;++i) g[i][i]=0;
    for(int i=0;i<n;++i){
        for(auto P:node[i]){
            const int u=P.first;
            for(auto Q:vec[u]) checkmin(g[i][Q.first],P.second+Q.second);
        }
    }
    for(int k=0;k<n;++k){
        for(int i=0;i<n;++i){
            for(int j=0;j<n;++j) checkmin(g[i][j],g[i][k]+g[k][j]);
        }
    }
    while(q--){
        int s,t;
        cin >> s >> t;
        --s;
        --t;
        long long ans=INF;
        for(auto P:vec[s]){
            for(auto Q:vec[t]) ans=min(ans,P.second+Q.second+g[P.first][Q.first]);
        }
        cout << ans+val[s]+val[t] << '\n';
    }
    return 0;
}