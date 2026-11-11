#include <bits/stdc++.h>
using namespace std;
int w[500005],k[500005],t[500005][500005],a[500005][500005],x[500005],y[500005];
int main(){
    int c,m,n,d,q;
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;i++){
        cin>>w[i];
    }
    fot(int i=1;i<=n;i++){
    cin>>k[i];
    for(int j=1;j<=k[i];j++){
        cin>>a[i][j]>>t[i][j];
    }
    }
    int r;
    for(r=1;r<=q;r++){
        cin>>x[r]>>y[r];
    }
    return 0;
}
