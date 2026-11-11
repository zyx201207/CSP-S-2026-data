#include<bits/stdc++.h>
using namespace std;
int c,t,n;
long long d,x[2000001];
int main(){
    freopen(migrate.in,"r",stdin);
    freopen(migrate.out,"w",stdout);
    std::ios::sync_with_stdio(0);
    std::cin.tie(nullptr);
    cin>>c>>t;
    while(t--){
        cin>>n>>d;
        for(int i=1;i<=n;i++){
            cin>>x[i];
        }
        long long cha=x[2]-x[1];
        if(c==11||c==12){
            if(d<2*cha)cout<<0<<'\n';
            else{
                cout<<1ll*n-2*(d/cha)+1<<'\n';
            }
        }
    }
    return 0;
}
