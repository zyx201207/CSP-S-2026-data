#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll a[500005],f[500005][2];
ll n,m;
bool ch(ll x){
    ll res=0;
    for(int i=1;i<=x;i++){
        res+=a[x]-a[i];
        if(res>m){
            return false;
        }
    }
    if(res>m){
        return false;
    }
    return true;
}
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>m;
    bool ok=1;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+1+n);
    ll y=a[2]-a[1];
    for(int i=1;i<n;i++){
        if(a[i+1]-a[i]!=y){
            ok=0;
            break;
        }
    }
    if(ok){
        ll l=1,r=n,ans=0;
        while(l<=r){
            ll mid=(l+r)/2;
            if(ch(mid)){
                l=mid+1;
                ans=mid;
            }
            else{
                r=mid-1;
            }
        }
        cout<<ans;
        return 0;
    }
    if(ch(n)){
        cout<<n;
        return 0;
    }
    ll cnt=1;
    f[1][0]=a[1];
    f[1][1]=1;
    for(int i=2;i<=n;i++){
        if(a[i]==a[i-1]){
            f[cnt][1]++;
        }
        else{
            cnt++;
            f[cnt][0]=a[i];
            f[cnt][1]=1;
        }
    }
    ll ans=0;
    for(int i=1;i<=cnt;i++){
        ll ovo=m;
        ll res=f[i][1];
        ll p=i-1;
        while(ovo>0){
            if(p<1){
                break;
            }
            ll cnt1=f[i][0]-f[p][0];
            ll g;
            if(cnt1!=0){
                g=ovo/cnt1;
            }
            if(g>=f[p][1]){
                ovo-=cnt1*f[p][1];
                res+=f[p][1];
                p--;
            }
            else{
                res+=g;
                break;
            }
        }
        ans=max(ans,res);
    }
    cout<<ans;
    return 0;
}
