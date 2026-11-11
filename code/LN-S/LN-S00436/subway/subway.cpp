#include<bits/stdc++.h>
using namespace std;
int f[509][500009];
int zhan[509][509];
int dep[500009];
int C,n,m,d,q,k,st,ed;
vector<int>go[500009];
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    ios::sync_with_stdio(0),cin.tie(0);
    cin>>C>>n>>m>>d>>q;
    memset(f,0x3f,sizeof(f));
    memset(zhan,0x3f,sizeof(zhan));
    for(int i=1;i<=m;++i)cin>>dep[i];
    for(int i=1;i<=n;++i){
        cin>>k;
        int a,t;
        for(int j=1;j<=k;++j){
            cin>>a>>t;
            f[i][a]=t;
            go[a].push_back(i);
        }
    }
    for(int i=1;i<=n;++i)zhan[i][i]=0;
    for(int i=1;i<=n;++i){
        for(int j=i+1;j<=n;++j){
            for(int l=1;l<=m;++l){
                zhan[i][j]=min(zhan[i][j],f[i][l]+f[j][l]);
            }
        }
    }
    for(int i=1;i<=n;++i){
        for(int j=i+1;j<=n;++j){
            for(int l=1;l<=n;++l){
                if(l<i)
                        zhan[i][j]=min(zhan[i][j],zhan[l][i]+zhan[l][j]);
                    else if(l>j)
                        zhan[i][j]=min(zhan[i][j],zhan[i][l]+zhan[j][l]);
                    else zhan[i][j]=min(zhan[i][j],zhan[i][l]+zhan[l][j]);
            }
        }
    }
    while(q--){
        int ans=214748367;
        cin>>st>>ed;
        for(int i=0;i<go[st].size();++i){
            for(int j=0;j<go[ed].size();++j){
                int u1=max(go[st][i],go[ed][j]),u2=min(go[st][i],go[ed][j]);
                if(dep[st]+dep[ed]+f[go[st][i]][st]+f[go[ed][j]][ed]+zhan[u2][u1]>0)
                ans=min(ans,dep[st]+dep[ed]+f[go[st][i]][st]+f[go[ed][j]][ed]+zhan[u2][u1]);
            }
        }
        cout<<ans<<"\n";
    }
    return 0;
}
