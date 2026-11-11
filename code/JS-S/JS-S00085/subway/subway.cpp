#include<bits/stdc++.h>
using namespace std;
const int N=510,M=5e5+10;
long long c,m,n,d,q;
long long w[N],k[N],a[N][M],t[N][M],x[N],y[N],ans;
int main(){
    freopen("r",subway.in);
    freopen("w",subway.out);
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;i++){
        cin>>w[i];
    }
    for(int i=1;i<=n;i++){
        cin>>k[i];
        for(int j=1;j<=k[i];j++){
            cin>>a[i][j]>>t[i][j];
            ans+=t[i][j];
        }
    }
    for(int i=1;i<=n;i++){
        cin>>x[i]>>y[i];
        cout<<ans<<endl;
    }

    return 0;
}
