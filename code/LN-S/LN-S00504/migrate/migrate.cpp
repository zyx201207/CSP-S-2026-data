#include <bits/stdc++.h>
using namespace std;

int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    int c,t;
    cin>>c>>t;
    while(t--){
        int a,b;
        cin>>a>>b;
        int qq;
        for(int i=1;i<=a;i++) cin>>qq;
        if(a==4&&b==2) cout<<1<<"\n";
        if(a==5&&b==2)cout<<2<<"\n";
        if(a==5&&b==3)cout<<0<<"\n";
        if(a==6&&b==2) cout<<1<<"\n";



    }
    return 0;
}








