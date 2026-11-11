#include<bits/stdc++.h>
using namespace std;
#define int long long
const int F=0x3f3f3f3f3f3f3f3f;
/*struct node{
    int x,sum,xl;
};
*/
int c,n,m,d,q;
//vector<pair<int,int>> l[500006];
vector<int> dt[506];
int tk[500006];
int tt[500006][506];
bool vis[500006];
int ans=1e18;
void dfs(int x,int sum,int ed){
    if(x==ed){
        ans=min(ans,sum);
        return;
    }
    //sum+=tt[x][xl];
    /*for(int e:dt[xl]){
        if(tt[e][xl]!=F){
            if(vis[e]==0){
                vis[e]=1;
                dfs(e,sum+tt[x][xl])
            }
        }
    }
    */
    for(int i=1;i<=n;i++){
        if(tt[x][i]!=F){
            for(int e:dt[i]){
                if(vis[e]==0){
                    vis[e]=1;
                    dfs(e,sum+tt[x][i]+tt[e][i],ed);
                }
            }
        }
    }
}
int qdfs(int bg,int ed){
    /*queue<node> q;
    q.push({bg,tk[bg]+tk[ed],0});
    vis[bg]=1;
    while(!q.empty()){
        node u=q.front();
        q.pop();
        for(int e:dt[u.xl]){
            if(tt[e][u.xl]!=F){
                if(vis[e]==0){
                    vis[e]=1;
                }
            }
        }
    }
    */
    ans=1e18;
    vis[bg]=1;
    dfs(bg,tk[bg]+tk[ed],ed);
    return ans;
}

signed main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>c>>n>>m>>d>>q;
    memset(tt,0x3f,sizeof(tt));
    for(int i=1;i<=m;i++){
        cin>>tk[i];
    }
    //cout<<1;
    for(int i=1;i<=n;i++){
        int lk,la,lt;
        cin>>lk;
        for(int j=1;j<=lk;j++){
            cin>>la>>lt;
            tt[la][i]=lt;
            dt[i].push_back(la);
        }
    }
    //cout<<2;
    for(int i=1;i<=q;i++){
        int linx,liny;
        cin>>linx>>liny;
        memset(vis,0,sizeof(vis));
        qdfs(linx,liny);
        cout<<ans<<'\n';
    }
    //cout<<3;
    return 0;
}
