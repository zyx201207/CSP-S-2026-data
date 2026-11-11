#ifndef MIGRATE_CPP_INCLUDED
#define MIGRATE_CPP_INCLUDED
#include<bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
    int t;
    cin>>t;
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    while (t--){
        int n,d;
        cin>>n>>d;
        vector<int> a(n+1);
        for (int i=1;i<=n;i++){
            cin>>a[i];
        }
        int x=a[2]-a[1];
        if (d<x) cout<<0;
        else{
            vector<int> f(n+1,1);
            for (int i=1;i<=a[n];i+=x){
                for (int j=1;j<=d;j++){
                    if (i-j==0) break;
                    f[i]=f[i-j]*f[i];
                }
            }
            cout<<f[n]<<endl;
        }
    }
    return 0;
}



#endif // MIGRATE_CPP_INCLUDED
