#include<bits/stdc++.h>
using namespace std;

int c,n,m,d,q,w[500005];
vector<pair<long long,int>> station[500005];
long long need[505][505];

template<typename T>
inline void set_min(T& a,const T& b){
    a=min(a,b);
}

int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;++i){
        cin>>w[i];
    }
    for(int i=1;i<=n;++i){
        int k;
        cin>>k;
        while(k--){
            int a,b;
            cin>>a>>b;
            station[a].push_back({b,i});
        }
    }
    memset(need,63,sizeof(need));
    for(int i=1;i<=n;++i){
        need[i][i]=0;
    }
    for(int i=1;i<=m;++i){
        for(pair<long long,int> pa1 : station[i]){
            for(pair<long long,int> pa2 : station[i]){
                set_min(need[pa1.second][pa2.second],pa1.first+pa2.first);
            }
        }
    }
    for(int k=1;k<=n;++k){
        for(int i=1;i<=n;++i){
            for(int j=i+1;j<=n;++j){
                long long sum=need[i][k]+need[k][j];
                if(sum<need[i][j]){
                    need[i][j]=need[j][i]=sum;
                }
            }
        }
    }
    while(q--){
        int a,b;
        cin>>a>>b;
        long long ans=9e18;
        for(pair<long long,int> pa1 : station[a]){
            for(pair<long long,int> pa2 : station[b]){
                set_min(ans,w[a]+w[b]+pa1.first+pa2.first+need[pa1.second][pa2.second]);
            }
        }
        cout<<ans<<'\n';
    }
    return 0;
}
