#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=1005,M=5e5+5,INF=1e18;
int C,n,m,d,q;
int cf[N][N],wf[N];
int zs1[N],zs2[N];
int nn[M],wn[M],tn[M],hc,hct;
void floyd(){
    for(int i=1;i<=m;i++){
        cin>>wf[i];
    }
    for(int i=1;i<=m;i++){
        for(int j=1;j<=m;j++){
            if(i==j)continue;
            cf[i][j]=INF;
        }
    }
    for(int i=1;i<=n;i++){
        int k;
        cin>>k;
        for(int j=1;j<=k;j++){
            cin>>zs1[j]>>zs2[j];
        }
        for(int j=1;j<=k;j++){
            for(int l=j+1;l<=k;l++){
                cf[zs1[j]][zs1[l]]=min(cf[zs1[j]][zs1[l]],zs2[j]+zs2[l]);
                cf[zs1[l]][zs1[j]]=cf[zs1[j]][zs1[l]];
            }
        }
    }
    for(int k=1;k<=m;k++){
        for(int i=1;i<=m;i++){
            for(int j=1;j<=m;j++){
                cf[i][j]=min(cf[i][j],cf[i][k]+cf[k][j]);
            }
        }
    }
    for(int i=1;i<=q;i++){
        int x,y;
        cin>>x>>y;
        cout<<cf[x][y]+wf[x]+wf[y]<<"\n";
    }
}
void tpn(){
    for(int i=1;i<=m;i++){
        cin>>wn[i];
    }
    int k;
    cin>>k;
    for(int i=1;i<=k;i++){
        int a,t;
        cin>>a>>t;
        nn[a]=1;
        tn[a]=t;
    }
    cin>>k;
    for(int i=1;i<=k;i++){
        int a,t;
        cin>>a>>t;
        if(nn[a]==1){
            hc=a;
            hct=t;
        }else{
            nn[a]=2;
            tn[a]=t;
        }
    }
    for(int i=1;i<=q;i++){
        int x,y;
        cin>>x>>y;
        if(nn[x]==nn[y]||x==hc||y==hc){
            cout<<wn[x]+wn[y]+tn[x]+tn[y]<<"\n";
        }else{
            cout<<wn[x]+wn[y]+tn[x]+tn[y]+hct+tn[hct]<<"\n";
        }
    }
}
signed main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>C>>n>>m>>d>>q; 
    if(C==20||C==21)tpn();
    else floyd();
    return 0;
}

