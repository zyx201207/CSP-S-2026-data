#include<bits/stdc++.h>
using namespace std;
const long long inf=1e18;
long long ans[2005][2005];
int w[500005],t[500005],a[500005];
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    ios::sync_with_stdio(0);cin.tie(0);
    int c,n,m,d,q,k,x,y;
    long long tta,ttb;
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;i++){
        for(int j=1;j<=m;j++) ans[i][j]=inf;
    }
    for(int i=1;i<=m;i++) cin>>w[i];
    for(int i=1;i<=n;i++){
        cin>>k;
        for(int j=1;j<=k;j++) cin>>a[j]>>t[j];
        for(int j=1;j<=k;j++){
            for(int jj=j+1;jj<=k;jj++){
                x=a[j];y=a[jj];
                if(x>y) swap(x,y);
                ans[x][y]=min(ans[x][y],1ll*t[j]+1ll*t[jj]);
            }
        }
    }
    for(int i=1;i<=m;i++){
        for(int j=i+1;j<=m;j++){
            if(i==j){
                ans[i][i]=0;
                continue;
            }
            for(k=1;k<=m;k++){
                if(k==i||k==j) continue;
                tta=ans[min(i,k)][max(i,k)];
                ttb=ans[min(j,k)][max(j,k)];
                if(tta==inf||ttb==inf) continue;
                ans[i][j]=min(ans[i][j],tta+ttb);
            }
        }
    }
    while(q--){
        cin>>x>>y;
        if(x>y) swap(x,y);
        cout<<ans[x][y]+w[x]+w[y]<<'\n';
    }
    return 0;
}
//subway
