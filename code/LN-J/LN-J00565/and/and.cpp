#include<bits/stdc++.h>
using namespace std;
long long n,l,m[10010][10010],o=INT_MIN,io=INT_MIN,oo;
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>l;
    for(int i=1;i<=n;i++){
        cin>>m[i][0];
        if(i==1){
            oo=m[i][0];
        }
        oo&=m[i][0];
        o=max(o,m[i][0]);
        for(int j=1;j<=i;j++){
            if(i==j)continue;
            m[i][j]=m[i][0]&m[j][0];
            io=max(io,m[i][j]);

         }
    }
    if(l==1){
        cout<<o;
    }else if(l==2){
    cout<<io;
    }else cout<<oo;

    return 0;
}
