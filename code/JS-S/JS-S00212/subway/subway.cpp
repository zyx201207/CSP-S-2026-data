#include<bits/stdc++.h>
using namespace std;
long long c,n,m,d,q,w[500010],k[510],t[510][1010],xx[1000100],yy[1000100],a[510][1001],ans;
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    cin>>c>>n>>m>>d>>q;
    while(m--){
        for(int i=1;i<=m;i++){
            cin>>w[i];
        }
        for(int i=1;i<=n;i++){
            cin>>k[i];
            for(int j=1;j<=k[i];j++){
                cin>>a[i][j];
                cin>>t[i][j];
            }
        }for(int i=1;i<=q;i++){
            cin>>xx[i]>>yy[i];
            ans=w[xx[i]]+t[1][xx[i]]+t[1][yy[i]]+w[yy[i]];
            cout<<ans<<endl;
        }
    }
}
