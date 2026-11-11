#include<bits/stdc++.h>
using namespace std;
long long c,n,m,d,q;
long long w[500005];
long long t[500005][505];
vector<long long> a[500005];//m n w
vector<pair<long long,long long>> e[505];
long long dis[505][505];
long long vis[505];
long long st,en,tans,ans;
long long Checksame(long long x,long long y){
    long long tmpn=0,tmpmin=0x7fffffffff;
    for(auto i:a[x]){
        for(auto j:a[y]){
            if(i == j){
                long long aa=t[x][i]+t[y][i];
                if(aa < tmpmin){
                    tmpmin=aa;
                    tmpn=i;
                }
            }
        }
    }
    return tmpn;
}
void dfs(long long S,long long T,long long cost){
    if(S==T){
        tans=min(tans,cost);
    }
    if(cost>tans){
        return;
    }
    for(auto i:e[S]){
        long long id=i.first;
        long long W=i.second;
        if(vis[id] == 0){
            vis[id]=1;
            dfs(id,T,cost+W);
            vis[id]=0;
        }
    }
}
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;i++){
        cin>>w[i];
    }
    for(int i=1;i<=n;i++){
        long long k;
        cin>>k;
        for(int j=1;j<=k;j++){
            long long xx,yy;
            cin>>xx>>yy;
            a[xx].push_back(i);
            t[xx][i]=yy;
        }
    }
    for(int i=1;i<=m;i++){
        if(a[i].size() > 1){
            for(int j:a[i]){
                for(int k:a[i]){
                    if(j!=k){
                        e[j].push_back({k,t[i][j]+t[i][k]});
                    }
                }
            }
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=i+1;j<=n;j++){
            vis[i]=1;
            tans=0x7fffffffff;
            dfs(i,j,0);
            dis[i][j]=dis[j][i]=tans;
            vis[i]=0;
        }
    }
    while(q--){
        cin>>st>>en;
        long long tmp=Checksame(st,en);
        if(tmp >= 1){
            cout<<w[st]+w[en]+t[st][tmp]+t[en][tmp]<<endl;
            continue;
        }
        ans=0x7fffffffff;
        long long numm1=0,numm2=0;
        for(int i:a[st]){
            for(int j:a[en]){
                if(ans>dis[i][j]){
                    ans=min(ans,dis[i][j]);
                    numm1=i,numm2=j;
                }
            }
        }
        cout<<w[st]+w[en]+ans+t[st][numm1]+t[en][numm2]<<endl;
    }
    return 0;
}
