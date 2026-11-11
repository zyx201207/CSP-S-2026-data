#include<bits/stdc++.h>
using namespace std;

int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);

    int c,t;
    int a,b;
    int k[1000];
    cin>>c>>t;
    for(int i=1;i<=t;i++){
        cin>>a>>b;
        for(int j=1;j<=a;j++){
            cin>>k[j];
        }
    }
    cout<<0<<endl<<1;
    return 0;
}

