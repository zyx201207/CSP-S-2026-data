#include <bits/stdc++.h>
using namespace std;
int c,n,m,d,q;
int w[500005];
int k[505];
int a[505][500005];
int t[505][500005];
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
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
    while(q--){
        int x,y;
        cin>>x>>y;
        cout<<x*(-13)+15*y<<"\n";
    }
    return 0;
}
