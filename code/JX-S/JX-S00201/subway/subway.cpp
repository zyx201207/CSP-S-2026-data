#include<bits/stdc++.h>
using namespace std;
const int M=500010;
long long c,n,m,d,q,w[M],k[M],a[M][M],t[M][M],x,y,ans;
void chuzhan(long long r){
    for(int i=1;i<=k[n];i++){
        if(a[r][i]==y){
            ans+=w[i];
        }
    }
    return ;
}
void huanchen(long long j){
    for(int l=1;l<=k[j];l++){
                for(int z=1;z<=k[j+1];z++){
                        if(a[k[j]][l]==a[k[j+1]][z]){
                                chuzhan(k[j]);
                            for(int i=1;i<=l;i++){
                                ans+=t[k[j]][l];
                            }
                    }
                }
            }
    return ;
}

int main(){
    freopen("subwany.in","r",stdin);
    freopen("subwany.out","w",stdout);
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;i++) cin>>w[i];
    for(int i=1;i<=n;i++){
        cin>>k[i];
        for(int j=1;j<=k[i];j++){
            cin>>a[i][j]>>t[i][j];
        }
    }
    for(int i=1;i<=q;i++){
        cin>>x>>y;
        ans+=w[x]+t[1][x];
        for(int j=1;j<=n;j++){
            if(j==n){
                chuzhan(j);
            }
            huanchen(j);
        }
    }
    cout<<ans;
    return 0;
}
