#include<bits/stdc++.h>
using namespace std;
#define int long long
int c,n,m,d,q,f[505][505],dp[505][505],vt[500005];
vector<vector<pair<int,int>>>a;
vector<vector<pair<int,int>>>b;
map<int,int>e;
int has(int i,int j){
    return i*1000007+j;
}
inline int read(){
    int x=0,r=1;char s;
    cin.get(s);
    if('0'<=s&&s<='9')x=s-'0';
    else if(s=='-')r=-1;
    while(1){
        cin.get(s);
        if('0'<=s&&s<='9')x=x*10+s-'0';
        else break;
    }
    return x*r;
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    freopen("subway.in","r",stdin);

    freopen("subway.out","w",stdout);
    cin>>c>>n>>m>>d>>q;int k;int x,y;
    a.resize(m+2);
    b.resize(n+2);
    for(int i=1;i<=m;++i)cin>>vt[i];
    for(int i=1;i<=n;++i){
        cin>>k;
        for(int j=1;j<=k;j++){
            cin>>x>>y;
            a[x].push_back({i,y});
            b[i].push_back({x,y});
        }
    }int ttt;
    for(int i=1;i<=m;++i){
        for(int j=0;j<(int)a[i].size();j++){
            for(int k=j+1;k<(int)a[i].size();k++){
                ttt=has(a[i][j].first,a[i][k].first);
                if(e.find(ttt)!=e.end())e[ttt]=min(e[ttt],a[i][j].second+a[i][k].second);
                else e[ttt]=a[i][j].second+a[i][k].second;
                e[has(a[i][k].first,a[i][j].first)]=e[ttt];
            }
        }
    }
    for(int i=1;i<=n;++i){
        for(int j=1;j<=n;++j){
            if(e.find(has(i,j))!=e.end())f[i][j]=e[has(i,j)];
            else f[i][j]=2100000000;
        }
    }
    for(int i=1;i<=n;++i){
        f[i][i]=0;
    }
    for(int i=0;i<=504;++i){
        for(int j=0;j<=504;++j){
        dp[i][j]=2100000000;
    }
    }
    for(int i=1;i<=n;++i){
        dp[i][i]=0;
    }
    for(int k=1;k<=n;++k){
        for(int i=1;i<=n;++i){
            for(int j=i;j<=n;++j){
                if(f[i][k]<=2099999999&&f[k][j]<=2099999999)dp[i][j]=min(dp[i][j],f[i][k]+f[k][j]);
                dp[j][i]=dp[i][j];
            }
        }
    }
    int ans=2100000000;
    for(int i=1;i<=q;++i){
        cin>>x>>y;
        for(auto& g:a[x]){
            for(auto& h:a[y]){
                ans=min(dp[g.first][h.first]+g.second+h.second,ans);
            }
        }cout<<ans+vt[x]+vt[y]<<"\n";
    }

    return 0;
}
