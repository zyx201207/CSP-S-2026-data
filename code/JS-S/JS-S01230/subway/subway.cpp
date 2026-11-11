#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q;
vector<int> hycc[505];
vector<int> zhan[500005];
int w[500005],t[505][500005],cnt[500005][505],vis[500005];
double aans=1e30+1;
void dfs(int now,int mubiao,double ans){
    if(now==mubiao){
        aans=min(ans+w[mubiao],aans);
        return;
    }
    vis[now]=1;
    int flag=0;
    for(int i=1;i<=n;i++){
        if(cnt[i][now]+cnt[i][mubiao]>1){
            dfs(mubiao,mubiao,ans+t[i][now]+t[i][mubiao]);
            flag=1;
        }
    }
    if(flag==0){
        for(int i=0;i<zhan[now].size();i++){
        int x=zhan[now][i];//cishixianlu
        for(int j=0;j<hycc[x].size();j++){//meijudian
            if(zhan[hycc[x][j]].size()>1&&vis[hycc[x][j]]==0){//panduanfenchakou
                vis[hycc[x][j]]=1;
                dfs(hycc[x][j],mubiao,ans+t[x][now]+t[x][hycc[x][j]]);
            }
        }
    }
    } else return;


}
signed main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;i++){
        cin>>w[i];
    }
    for(int i=1;i<=n;i++){
        int k,hyc;
        cin>>k;
        for(int j=1;j<=k;j++){
        cin>>hyc;
        hycc[i].push_back(hyc);
        zhan[hyc].push_back(i);
        cnt[i][hyc]++;
        cin>>t[i][hyc];
        }
    }
    while(q--){
        memset(vis,0,sizeof(vis));
        int u,v;
        cin>>u>>v;
        aans=1e30+1;
        dfs(u,v,w[u]);
        cout<<aans<<'\n';
    }
    return 0;
}
