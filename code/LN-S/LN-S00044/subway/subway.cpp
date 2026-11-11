#include <bits/stdc++.h>
using namespace std;
int c,n,m,d,q;
int w[500010],k[500010],a[510][500010],x[500010],y[500010];
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;i++){
        cin>>w[i];
    }
    for(int i=1;i<=n;i++){
        cin>>k[i];
        for(int j=1;j<=k[i];j++){
            cin>>a[i][j]>>t[i][j];
        }
    }
    for(int r=1;r<=q;r++){
        cin>>x[r]>>y[r];
    }
    for(int r=1;r<=q;r++){
        long long ans=0;
        ans = ans + w[x[r]] + w[y[r]];
        cout<<ans<<endl;
    }
    return 0;
}
