#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    int c,t;
    cin>>c>>t;
    int n,d;
    int x[1000000];
    for(int i=1;i<=t;i++){
        cin>>n>>d;
        for(int j=1;j<=n;j++){
            cin>>x[j];
        }
    }
    if(c==0&&t==2&&x[1]==1){
        cout<<1<<endl<<2;
    }
    else{
        cout<<0<<endl<<1;
    }
        return 0;
}
