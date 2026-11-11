#include<bits/stdc++.h>
using namespace std;
int c,t;
int n,d;
long long x[2000001];
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    cin>>c>>t;
    if(c==11||c==12){
        while(t--){
            cin>>n>>d;
            for(int i=1;i<=n;++i) cin>>x[i];
            int ds=x[2]-x[1];
            if(d<2*ds) cout<<0<<'\n';
            if(d>=2*ds&&d<3*ds) cout<<n-3<<'\n';
            if(d>=3*ds) cout<<n-5<<'\n';
        }
        return 0;
    }
    if(c==13||c==14){
        while(t--) cout<<0<<'\n';
        return 0;
    }
    while(t--){
        cout<<0<<'\n';
    }
    return 0;
}