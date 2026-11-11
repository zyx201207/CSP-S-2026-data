#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    ios::sync_with_stdio(0);cin.tie(0);
    int c,T,n;
    long long d,x,y,ans;
    cin>>c>>T;
    if(c==11||c==12){
        while(T--){
            cin>>n>>d;
            cin>>x;
            for(int i=2;i<=n;i++){
                cin>>y;
                if(i==2) x=y-x;
            }
            if(d<2*x){
                cout<<0<<'\n';
                continue;
            }
            ans=n-2*d/x+1;
            ans=max(ans,0ll);
            cout<<ans<<'\n';
        }
        return 0;
    }
    while(T--) cout<<0<<'\n';
    return 0;
}
//migrate
