#include<bits/stdc++.h>
using namespace std;
const int N=501;
long long c,m,n,d,q,w[N],k[N],a[N][20004],t[N][20004],x[100004],y[100004],cnt;
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
            cnt+=t[i][j];
        }

    }
    for(int p=1;p<=q;p++){
            cin>>x[p]>>y[p];
            cout<<cnt<<'\n';
        }

    return 0;
}
