#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll c,t;
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    cin>>c>>t;
    for(int i=1;i<=t;i++){
        bool f=0;
        bool flag=0;
        ll n,d;
        cin>>n>>d;
        vector<ll> a(n+5);
        for(int i=1;i<=n;i++){
            cin>>a[i];
        }
        if(n<=3){
            cout<<0<<endl;
        }
        for(int i=1;i<=n-2;i++){
            if(a[i+1]-a[i]!=a[i+2]-a[i+1]){
                f=1;
            }
        }
        if(f==0){
            ll tmp=a[2]-a[1];
            if(d<tmp*2){
                cout<<0<<endl;
            }else{
                if(a[n]-a[1]<=d){
                    cout<<0<<endl;
                }else if(d>=3*tmp){
                    cout<<0<<endl;
                }else{
                    cout<<n-3<<endl;
                }
            }
        }else{
            for(int i=2;i<=n;i++){
                if(a[n]-a[i]<=d&&a[i]-a[1]<=d){
                    flag=1;
                    break;
                }else{
                    continue;
                }
            }
            if(flag==1){
                cout<<1<<endl;
            }else{
                cout<<n-5<<endl;
            }
        }
    }
    return 0;
}
