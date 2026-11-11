#include <bits/stdc++.h>
using namespace std;
long long c,n,m,d,q,x,y,w[500010],k[500010],b[501][500001],t;
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>c>>n>>m>>d>>q;
    for(long long i=1;i<=m;i++){
        cin>>w[i];
    }
    for(long long i=1;i<=n;i++){
        cin>>k[i];
        for(long long j=1;j<=2*k[i];j++){
            cin>>b[i][k[i]];
        }
    }
    for(long long i=1;i<=q;i++){
        cin>>x>>y;
        long long mmin=1e9;
        for(long long j=1;j<=k[x];j++){
            mmin=min(mmin,b[j][x]+b[j][y]);
        }
        cout<<w[x]+w[y]+mmin<<"\n";
    }
    return 0;
}
