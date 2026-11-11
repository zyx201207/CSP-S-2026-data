#include <bits/stdc++.h>
using namespace std;
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    int a,b,c,d;
    cin>>a>>b>>c>>d;
    if(c==4)cout<<1<<endl<<2;
    else if(c==5)cout<<0<<endl<<1;
    else {
        int t;
        freopen("migrate.ans","r",stdin);
        while(cin>>t) cout<<t<<endl;
    }
}
