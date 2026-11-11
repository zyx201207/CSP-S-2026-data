#include<bits/stdc++.h>
using namespace std;
const int N=5e5+10;
const int Q=1e5+10;
int w[N],k[550],a[N][550],t[N][550],x[Q],y[Q];
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int c,n,m,d,q;
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;i++) cin>>w[i];
    for(int i=1;i<=n;i++){
        cin>>k[i];
        for(int j=1;j<=k[i];j++){
            cin>>a[i][j]>>t[i][j];
        }
    }
    for(int r=1;r<=q;r++){
        cin>>x[r]>>y[r];
    }
    return 0;
}
