#include<bits/stdc++.h>
#define ll long long
using namespace std;
int c,t;
ll n,d,x[2000010];
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin>>c>>t;
    while(t--){
        cin>>n>>d;
        for(ll i=1;i<=n;i++) cin>>x[i];
        if(n<=3){
            cout<<"0"<<endl;
            continue;
        }
        ll ans=0,s=0x3f3f3f3f;
        for(ll i=2;i<=n;i++){
            s=min(s,x[i]-x[i-1]);
        }
        if(s>=d){
            cout<<"0"<<endl;
            continue;
        }
        ll f=0,ch=x[2]-x[1];
        for(ll i=3;i<=n;i++){
            if(x[i]-x[i-1]!=ch){
                f=1;
                break;
            }
        }
        if(f==0){
            if(d>=ch&&d<2*ch){
                cout<<"0"<<endl;
                continue;
            }
            int d1=0;
            for(int i=2;;i++){
                if(i*ch>d){
                    d1=i-1;
                    break;
                }
            }
            for(int i=d1*2;i<=n;i++) ans++;
            cout<<ans<<endl;
            continue;
        }
    }
    return 0;
}
