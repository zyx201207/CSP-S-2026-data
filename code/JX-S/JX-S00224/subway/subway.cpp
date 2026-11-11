#include<bits/stdc++.h>
using namespace std;
const int N=5e5+15;
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    int c,n,m,d,q,w[N],k,a[515][25],t[515][25];
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;i++) cin>>w[i];
    for(int i=1;i<=n;i++){
        cin>>k;
        for(int j=1;j<=k;j++) cin>>a[i][j]>>t[i][j];
    }
    while(q--){
        int str_,end_;
        cin>>str_>>end_;
        cout<<w[str_]+w[end_]+a[1][str_]+t[1][str_]+t[1][end_]+a[1][end_]<<endl;
    }
    return 0;
}
