#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll a[2000005];
bool check(int i,int j,ll d){
    ll x=i;
    while(x<j){
        ll y=x;
        while(a[y]-a[x]<=d)y++;
        y--;
        x=y;
        if(y>=j){
            return x-2>=1&&a[j]-a[x-1]<=d&&a[j]-a[x-2]>d;
        }
    }
}
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll c,t;
    cin>>c>>t;
    while(t--){
        ll n,d;
        cin>>n>>d;
        for(int i=1;i<=n;i++)cin>>a[i];
        ll ans=0;
        for(int i=1;i<=n;i++){
            for(int j=1;j<i;j++){
                if(i-j<=2)continue;
                if(check(i,j,d))ans++;
            }
        }
        cout<<ans<<'\n';
    }
    return 0;
}
