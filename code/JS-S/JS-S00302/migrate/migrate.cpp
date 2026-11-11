#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=2e6+5;
ll c,t,n,d,ans,x[N];

int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>c>>t;
    if(c==11||c==12){
        while(t--){
            ans=0;
            cin>>n>>d;
            for(int i=1;i<=n;++i) cin>>x[i];
            ll q=x[2]-x[1];
            if(q>=d) cout<<0<<'\n';
            else{
                 for(int bg=1;bg<=n;++bg){
                    for(int ed=bg+d;bg+ed<=n;++ed){
                        ll cnt=0;
                        for(int rt=bg+1;rt<=ed;++rt){
                            if(x[ed]-x[rt]<=d&&x[rt]-x[bg]<=d) cnt++;
                        }
                        if(cnt==2) ans++;
                    }
                }
            }
        }
    }
    while(t--){
        ans=0;
        cin>>n>>d;
        for(int i=1;i<=n;++i) cin>>x[i];
        for(int bg=1;bg<=n;++bg){
            for(int ed=bg+d;bg+ed<=n;++ed){
                ll cnt=0;
                for(int rt=bg+1;rt<=ed;++rt){
                    if(x[ed]-x[rt]<=d&&x[rt]-x[bg]<=d) cnt++;
                }
                if(cnt==2) ans++;
            }
        }
        cout<<ans<<'\n';
    }
    return 0;
}
