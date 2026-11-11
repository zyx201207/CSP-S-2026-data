#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
int c,n,m,d,q;
ll w[500005];
struct Line{
    int len;
    vector<int> u;
    vector<ll> w;
}lines[105];
bool vis[105];
ll ans=1e18;
void dfs(int now,int en,ll cost){
    if(now==en){
        ans=min(ans,cost);
        return;
    }
    for(int i=1;i<=n;i++){
        if(vis[i])continue;
        for(int j=0;j<lines[i].len;j++){
            if(lines[i].u[j]==now){
                vis[i]=true;

                for(int k=0;k<lines[i].len;k++){
                    if(j==k)continue;
                    dfs(lines[i].u[k],en,cost+lines[i].w[k]+lines[i].w[j]);

                }
                break;
            }
        }
    }
}

int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;i++){
        cin>>w[i];
    }

    for(int i=1;i<=n;i++){
        int k;cin>>k;
        lines[i].len=k;
        for(int j=1;j<=k;j++){
            int a;
            ll t;
            cin>>a>>t;
            lines[i].u.push_back(a);
            lines[i].w.push_back(t);
        }
    }
    while(q--){
        memset(vis,false,sizeof(vis));
        int st,en;
        cin>>st>>en;
        ans=1e18;
        dfs(st,en,0);
        ans+=(w[st]+w[en]);
        cout<<ans<<'\n';
    }

    return 0;
}
