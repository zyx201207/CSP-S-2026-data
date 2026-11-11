#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("subway.in","r",std);
    freopen("subway.out","w",std);
    int c,n,m,d,q,w[500001],k[501],a[501][500001],t[501][500001],x[500001],y[500001];
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;i++){
        cin>>w[m];
    }
    for(int i=1;i<=n;i++){
        cin>>k[i];
        for(int j=1;j<=k[i];j++){
            cin>>a[i][j]>>t[i][j];
        }
    }
    for(int i=1;i<=q;i++){
        cin>>x[i]>>y[i];
    }
    int sum=0;
    sum+=w[x[1];
    for(int i=x[1];i<=y[1];i++){
        sum+=t[1][i];
    }
    sum+=w[y[1];
    cout<<sum<<endl;
    int sum=0;
    sum+=w[x[2];
    for(int i=x[2];i<=y[2];i++){
        sum+=t[2][i];
    }
    sum+=w[y[2];
    cout<<sum<<endl;
    return 0;
}
