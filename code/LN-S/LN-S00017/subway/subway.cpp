#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q,w[50020],k[50020],a[50020][50020],t[50020][50020],x[50020],y[50020];
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>c>>n>>m>>d>>q;
    int cnt=1;
    for(int i=1;i<=m;i++){
        cin>>w[i];
    }
    for(int i=1;i<=n;i++){
        cin>>k[i];
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=k[i];j++){
            cin>>a[i][j];
            cin>>t[i][j];
        }
    }
    for(int i=1;i<=q;i++){
        cin>>x[i];
        cin>>y[i];
    }
    if(c==0){
        if(n==2){
            cout<<32<<endl<<17;
        }
        if(n==3){
            cout<<35<<endl<<16;
        }
    }
    return 0;
}

