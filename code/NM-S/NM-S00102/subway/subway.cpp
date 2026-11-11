#include<bits/stdc++.h>
using namespace std;
long long c,n,m,d,q,w[300000],k[300000],x[300000],y[300000],jl[600][600];
vector<long long>a[300000],f[300000];
set<pair<long long,long long>>s;
vector<pair<long long,long long>>dd[300000];
unordered_map<long long,long long>mm[300000],ddd[300000];
unordered_map<long long,long long>cd[600];
void dj(int xx){
    s.insert({0,xx});
    jl[xx][xx]=0;
    ddd[xx][xx]=1;
    while(s.size()!=0){
        long long y=s.begin()->first,x=s.begin()->second;
        s.erase(s.begin());
        ddd[xx][x]=1;
        for(auto i=cd[x].begin();i!=cd[x].end();i++){
            if(ddd[xx][i->first]==0 and jl[xx][i->first]>jl[xx][x]+i->second){
                s.erase({jl[xx][i->first],i->first});
                jl[xx][i->first]=jl[xx][x]+i->second;
                s.insert({jl[xx][i->first],i->first});
            }
        }
    }
}
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.in","r",stdout);
    scanf("%d%d%d%d%d",&c,&n,&m,&d,&q);
    for(int i=0;i<=500;i++){
        for(int j=0;j<=500;j++){
            jl[i][j]=1e18;
            cd[i][j]=1e18;
        }
    }
    for(int i=1;i<=m;i++){
        scanf("%lld",&w[i]);
    }
    for(int i=1;i<=n;i++){
        scanf("%lld",&k[i]);
        for(int j=0;j<k[i];j++){
            long long f1,ff;
            scanf("%lld%lld",&f1,&ff);
            a[i].push_back(f1);
            f[i].push_back(ff);
            mm[i][f1]=ff;
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=0;j<k[i];j++){
            for(int l=0;l<dd[a[i][j]].size();l++){
                cd[dd[a[i][j]][l].first][i]=min(cd[dd[a[i][j]][l].first][i],dd[a[i][j]][l].second+f[i][j]);
                cd[i][dd[a[i][j]][l].first]=min(cd[i][dd[a[i][j]][l].first],dd[a[i][j]][l].second+f[i][j]);
            }
            dd[a[i][j]].push_back({i,f[i][j]});
        }
    }
    for(int i=1;i<=n;i++){
        dj(i);
    }
    for(int i=1;i<=q;i++){
        scanf("%d%d",&x[i],&y[i]);
        long long ans=1e18;
        for(int j=1;j<=n;j++){
            for(int l=1;l<=n;l++){
                if(mm[l][y[i]]!=0 and mm[j][x[i]]!=0){
                    ans=min(ans,mm[l][y[i]]+mm[j][x[i]]+w[y[i]]+w[x[i]]+jl[j][l]);
                }
            }
        }
        printf("%lld\n",ans);
    }
    return 0;
}
