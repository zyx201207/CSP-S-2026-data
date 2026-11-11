#include<bits/stdc++.h>
#define ll long long
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    vector<bool> v;
    vector<ll> a;
    int c,t;
    cin>>c>>t;
    while(t--){
        v.clear();
        a.clear();
        ll ans=0;
        ll n,d;
        cin>>n>>d;
        ll x;
        for(int i=0;i<n;i++){
            cin>>x;
            a.push_back(x);
        }
        for(int i=0;i<n-1;i++){
            if(a[i+1]-a[i]<=d){
                v.push_back(true);
            }
            else{
                v.push_back(false);
            }
        }
        for(int i=0;i<=n-d;i++){
            bool f=1;
            for(int j=0;j<=d;j++){
                f&=v[i+j];
            }
            if(f)ans++;
        }
        cout<<ans<<endl;
    }
    return 0;
}
