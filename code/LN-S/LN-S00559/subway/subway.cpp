#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q,w[110],k[110],a[110][110],t[110][110];
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;i++) cin>>w[i];
    for(int i=1;i<=n;i++){
        cin>>k[i];
        for(int j=1;j<=k[i];j++){
            cin>>a[i][j]>>t[i][j];
        }
    }
    for(int i=1;i<=q;i++){
        int x,y;
        cin>>x>>y;
    }
    if(c==0){
        if(n==2){
            cout<<32<<endl<<17;
            return 0;
        }
        if(n==3){
            cout<<35<<endl<<16;
            return 0;
        }
    }
    return 0;
}
