#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll c,t,n,d,a[2001000],fro[2001000],bac[2001000];
struct ele{
    ll dist,to;
};
stack<ele> s;
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    std::ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>c>>t;
    while(t--){
        cin>>n>>d;
        for(ll i=1;i<=n;i++){
            cin>>a[i];
            s.push({a[i],i});
            while(s.top().dist+d<a[i]){
                bac[s.top().to]=i-1;
                s.pop();
            }
            fro[i]=s.top().to;
        }
        while(!s.empty()){
            bac[s.top().to]=n;
            s.pop();
        }
        ll cut=a[2]-a[1];
        ll tran=d/cut;
        cout<<n-tran-tran+1<<endl;
    }
    return 0;
}
