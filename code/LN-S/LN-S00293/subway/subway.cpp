#include<bits/stdc++.h>
using namespace std;
const int N=510;
int fs[N],st[N][N],f[N][N];
vector<int> t[N];
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    int c,n,m,d,q;
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;i++) cin>>fs[i];
    for(int i=1;i<=n;i++){
        int k;
        cin>>k;
        for(int j=1;j<=k;j++){
            int u;
            cin>>u>>st[i][u];
            t[u].push_back(i);
        }
    }
    memset(f,0x3f,sizeof(f));
    for(int i=1;i<=n;i++){
        f[i][i]=0;
    }
    for(int i=1;i<=m;i++){
        if(t[i].size()<=1) continue;
        for(int j=0;j<t[i].size();j++){
            int u=t[i][j];
            for(int l=j+1;l<t[i].size();l++){
                int v=t[i][l];
                f[u][v]=f[v][u]=min(f[u][v],st[u][i]+st[v][i]);
            }
        }
    }
    while(q--){
        int u,v,ans=1e9;
        cin>>u>>v;
        for(int i=0;i<t[u].size();i++){
            for(int j=0;j<t[v].size();j++){
                ans=min(ans,f[t[u][i]][t[v][j]]+fs[u]+fs[v]+st[t[u][i]][u]+st[t[v][j]][v]);
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}
