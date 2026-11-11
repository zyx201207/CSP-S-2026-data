
#include <bits/stdc++.h>
using namespace std;
const int N=1e5+5;
long long ans[505];
int c,n,m,d,q,w[N],k[N],a[505][N],t[505][N],x[505],y[505];
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;i++){
        cin>>w[i];
    }
    for(int i=1;i<=n;i++){
        cin>>k[i];
        for(int j=1;j<=k[i];j++)
            cin>>a[i][j]>>t[i][j];
    }
    cin>>x[c]>>y[c];
    while(c--){
        ans[c]+=w[x[c]];
        ans[c]+=w[y[c]];
        for(int i=1;i<=n;i++){
            for(int j=1;j<=k[i];j++){
                ans[c]+=t[i][j];
            }

        }
    }
    for(int i=c;i>=1;i--){
        cout<<ans[i];
    }
    return 0;
}
