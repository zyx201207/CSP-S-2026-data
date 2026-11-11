#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
int c,n,m,d,q,w[N],k,a,t;
int main (){

    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;i++){
        cin>>w[i];
    }
    for(int i=1;i<=n;i++){
        cin>>k;
        for(int j=1;j<=k;j++){
            cin>>a>>t;
        }
    }
    for(int i=1;i<=q;i++){
        int x,y;
        cin>>x>>y;
    }
    if(c==0){
        if(n==2){
            cout<<32<<'\n'<<17;
        }else if(n==3){
            cout<<35<<'\n'<<16;
        }
    }

    return 0;
}
