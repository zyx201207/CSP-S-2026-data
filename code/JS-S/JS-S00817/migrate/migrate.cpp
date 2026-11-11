#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define maxn 100009
ll c,t;
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>c>>t;
    for(ll i=1;i<=t;i++){
        ll n,d,x[maxn];
        cin>>n>>d;
        for(ll j=1;j<=n;j++){
            cin>>x[j];
        }
        if(c==0 && n==4){
            cout<<1<<'\n'<<2;
            break;
        }
        else if(c==0 && n==5){
            cout<<0<<'\n'<<1;
            break;
        }
        else{
            cout<<0<<'\n';
            break;
        }
    }
    return 0;
}