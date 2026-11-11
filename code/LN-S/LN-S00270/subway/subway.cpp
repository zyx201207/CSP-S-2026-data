#include<bits/stdc++.h>
using namespace std;
int w[500005],k[505],a[505][500005],t[505][500005],b[505][505];
long long c,n,m,d,q,x,y;
int main(){
    freopen("subway1.in","r",stdin);
    //freopen("subway.out","w",stdout);
    for(int i=0;i<505;i++){
    for(int j=0;j<505;j++){
        b[i][j]=21000000;
    }
    }
    cin>>c>>n>>m>>d>>q;
    for(int i=0;i<m;i++){
     cin>>w[i];

    }
    for(int i=0;i<n;i++){
        cin>>k[i];
        for(int j=0;j<k[i];j++){
            cin>>a[i][j]>>t[i][j];
        }
    }
    for(int i=0;i<n;i++){
    for(int j=i;j<k[i];j++){
    for(int o=0;o<k[i];o++){
    b[a[i][j]-1][a[i][o]-1]=min(b[a[i][j]-1][a[i][o]-1],t[i][j]+t[i][o]);
    b[a[i][o]-1][a[i][j]-1]=b[a[i][j]-1][a[i][o]-1];
    }
    }
    }
    for(int i=0;i<n;i++){
    for(int j=0;j<n;j++){
    for(int o=0;o<n;o++){
        b[i][j]=min(b[i][j],b[i][o]+b[o][j]);
    }
    }
    }
    for(int i=0;i<q;i++){
        cin>>x>>y;
        cout<<b[x-1][y-1]+w[x-1]+w[y-1]<<endl;
    }
    return 0;
}
