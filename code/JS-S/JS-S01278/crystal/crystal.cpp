#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=5e5+5;
ll m,n,ans;
ll a[N];
bool cmp(ll a,ll b){
    return a>b;
}
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(ll i=1;i<=n;i++)
        cin>>a[i];
    sort(a+1,a+n+1,cmp);
    for(ll i=1;i<=n;i++){
        ll x=m,s=1;
        for(ll j=i+1;x>=a[j];j++){
            x-=a[i]-a[j];
            s++;
            if(j==n){
                cout<<s;
                return 0;
            }
        }
        ans=max(ans,s);
    }
    cout<<ans;
    return 0;
}
