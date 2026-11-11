#include<bits/stdc++.h>
using namespace std;
int c,t,n,d,cha;
long long x[2000001];
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    cin>>c>>t;
    while(t--){
        cin>>n>>d;
        for(int i=1;i<=n;i++) cin>>x[i];
        cha=x[2]-x[1];
        if(d<cha*2) cout<<0<<"\n";
        else{
            d/=cha;
            if(n-d-d+1<=0) cout<<0<<"\n";
            else cout<<n-d-d+1<<"\n";
        }
    }
    return 0;
}
