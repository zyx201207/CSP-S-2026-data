#include<bits/stdc++.h>
using namespace std;
int n,t,d,ys[2000013],c;
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    cin>>c>>t;
    for(int i=1;i<=t;i++){
        cin>>n>>d;
        for(int j=1;j<=n;j++){
            cin>>ys[j];
        }
        if(n>3&&d>=abs(ys[3]-ys[1])&&d<abs(ys[4]-ys[1])){
            cout<<(n+1)/2<<endl;
        }else{
            cout<<0<<endl;
        }
    }
    return 0;
}
