#include<bits/stdc++.h>
using namespace std;
int a,b,ans;
vector<int> metro[505];
vector<int> stat[500005];
int t[505][500005],w[500005],k[505],vis[500005][505];
void solve(int now,int p,int sum){
    vis[now][p]=sum;
    sum+=t[p][now];
    if(now==b){
        ans=min(ans,sum);
        return;
    }
    for(int i=0;i<stat[now].size();i++){

        if(stat[now][i]!=p){
            for(int j=0;j<metro[stat[now][i]].size();j++){
                if(metro[stat[now][i]][j]!=now){
                    if(sum+t[stat[now][i]][now]>=vis[metro[stat[now][i]][j]][stat[now][i]]){
                            return;
                    }
                    solve(metro[stat[now][i]][j],stat[now][i],sum+t[stat[now][i]][now]);
                }
            }
        }

    }
}
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    int c,n,m,d,q;
    cin>>c>>n>>m>>d>>q;
    memset(t,-1,sizeof(t));
    for(int i=1;i<=m;i++){
        scanf("%d",&w[i]);
    }
    for(int i=1;i<=n;i++){
        scanf("%d",&k[i]);
        for(int j=1;j<=k[i];j++){
            int x,y;
            scanf("%d%d",&x,&y);
            t[i][x]=y;
            metro[i].push_back(x);
            stat[x].push_back(i);
        }
    }
    while(q--){
        ans=1e9+7;
        memset(vis,0x3f,sizeof(vis));
        cin>>a>>b;
        solve(a,-1,w[a]);
        cout<<ans+w[b]<<endl;
    }
    return 0;
}
