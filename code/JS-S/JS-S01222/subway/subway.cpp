#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q,ans;
int w[500005];
int visit[500005];
int line[505][500005];

void dfs(int p,int cost,int g){
    if(cost>ans)return;
    if(p==g){
        ans=min(ans,cost);
        return;
    }
    for(int i=1;i<=n;i++){
        if(line[i][p]!=0){
            for(int j=1;j<=m;j++){
                if(line[i][j]!=0&&cost+line[i][j]+line[i][p]<ans&&visit[j]==0){
                    visit[j]=1;
                    dfs(j,cost+line[i][j]+line[i][p],g);
                    visit[j]=0;
                }
            }
        }
    }
}

void solve(int x,int y){
    memset(visit,0,sizeof(visit));
    visit[x]=1;
    dfs(x,0,y);
    cout<<ans+w[x]+w[y]<<endl;
    return;
}

int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;i++)
        cin>>w[i];
    for(int i=1;i<=n;i++){
        int k,a,t;
        cin>>k;
        for(int j=1;j<=k;j++){
            cin>>a>>t;
            line[i][a]=t;
        }
    }

    while(q--){
        int x,y;
        cin>>x>>y;
        ans=1<<31-1;
        solve(x,y);
    }
    return 0;
}
//12 pts ?
//hyw

//If tomorrow brings something good
//Tonight I'll do it all for love all for love
//If you want it I know I could
//Tonight I'll do it all for love all for love
