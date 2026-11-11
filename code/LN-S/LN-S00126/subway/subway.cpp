#include<bits/stdc++.h>
using namespace std;
const int mxN=5e5+5;
int c,n,m,d,q,w[mxN],a[505][mxN],t[505][mxN];
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;i++) printf("%d",&w[i]);
    for(int i=1;i<=n;i++){
        int k;
        cin>>k;
        for(int j=1;j<=k;j++){
            cin>>a[i][j]>>t[i][j];
        }
    }
    for(int i=1;i<=q;i++){
        int x,y;
        cin>>x>>y;
        cout<<w[x]+t[1][1]+t[1][2]+w[y]<<endl;
    }
    return 0;
}
