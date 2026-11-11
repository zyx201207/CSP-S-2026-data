#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    long long c,t;
    cin>>c>>t;
    while(t--){
        long long n,d;
        cin>>n>>d;
        long long x[n+5];
        for(long long i=1;i<=n;i++){
            cin>>x[i];
        }
        long long r=x[2]-x[1];
        if(d<=r){
            cout<<0<<endl;
        }else{
            long long ans=n-d/r*2+1;
            if(ans<=0){cout<<0<<endl;}
            else{cout<<ans<<endl;}
        }
    }
    return 0;
}
