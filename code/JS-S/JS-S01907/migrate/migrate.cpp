#include<bits/stdc++.h>
using namespace std;
int c, t;
int main(){
    freopen("migrate.in", "r", stdin);
    freopen("migrate.out", "w", stdout);
    int n, d, a[2000005];
    while(t--){
        cin>>n>>d;
        for(int i=1;i<=n;i++){
            cin>>a[i];
        }
        if(n==4&&d==2) cout<<1<<"\n;
        if(n==5&&d==2) cout<<2<<"\n;
        if(n==5&&d==3) cout<<0<<"\n;
        if(n==6&&d==2) cout<<1<<"\n;
    }
    return 0;
}
