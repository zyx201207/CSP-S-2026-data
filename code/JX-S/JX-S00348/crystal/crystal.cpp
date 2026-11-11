#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N=500005;
ll n,m,sum,T;
ll a[N],cnt[N];
bool o=1;
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+1+n);
    for(int i=1;i<=n;i++){
        cnt[i]=cnt[i]+a[i-1];
        sum+=a[n]-a[i];
    }
    if(m>sum){
        cout<<n;
        return 0;
    }
    ll l=a[1],r=a[n],mid=(l+r)/2,ans=0;
    while(l<=r){
        mid=(l+r)/2;
        ll q=m,cn=0;
        for(int i=1;i<=n;i++){
            if(mid>=a[i]){
                cn++;
                q-=(mid-a[i]);
            }
        }
        if(q<0){
            r=mid-1;
        }
        else if(q<m){
            ans=max(ans,cn);
            l=mid+1;
        }
        else{
            ans=max(ans,cn);
            break;
        }
    }
    cout<<ans;
    return 0;
}
