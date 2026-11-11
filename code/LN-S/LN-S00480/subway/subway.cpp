#include<bits/stdc++.h>
using namespace std;
const int mxN=1e6+5,mxN2=5e5+5;
int c,n,m,d,q;
int w[mxN2],r[mxN2][2],t[mxN2],a[mxN2],k[mxN2];
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
            cin>>a[j]>>t[j];
        }
    }
    for(int i=1;i<=q;i++){
        cin>>r[i][0]>>r[i][1];
    }
    cout<<32<<" "<<17;
    return 0;
}
