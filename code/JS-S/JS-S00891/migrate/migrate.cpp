#include<bits/stdc++.h>
using namespace std;
long long x[2000005];
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    long long c,t;
    cin>>c>>t;
    for(int i=1;i<=t;i++){
        long long n,d;
        long long ans=0;
        cin>>n>>d;
        for(int i=1;i<=n;i++) cin>>x[i];
        if(d<x[2]-x[1]){
            cout<<0<<endl;
        }
        for(int i=1;i<=n;i++){
            if(x[n]-x[i]+1<d) continue;
            ans+=(x[n]-x[i]+1)/d-1;
         //   cout<<ans<<endl;
        }
        cout<<ans<<endl;
    }
    return 0;
}
