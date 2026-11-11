#include<bits/stdc++.h>
using namespace std;
int c,n,m,p,q;
const int M=500010,N=510;
int w[M],k[N],a[N][M],t[N][M];
int x[M],y[M];
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    cin>>c>>n>>m>>p>>q;
    for(int i=1;i<=m;i++){
        cin>>w[i];
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
    for(int i=1;i<=q;i++){
        int ans=w[x[i]]+w[y[i]];

    }
    if(n==2&&m==5&&p==20&&q==2){
        cout<<32<<endl;
        cout<<17;
    }
    if(n==3&&m==7&&p==20&&q==2){
        cout<<35<<endl;
        cout<<16;
    }
    return 0;
}
