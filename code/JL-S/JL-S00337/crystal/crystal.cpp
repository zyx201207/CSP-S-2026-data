#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const ll inf=1e18,N=5e5+7;

ll n,m;
ll a[N],qzh[N];

bool check(ll x,ll ndi){
    ll k=qzh[ndi-1]-qzh[x-1];
    ll target=((ndi-1)-(x)+1)*a[ndi];
    return ((target-k)<=m);
}

int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+1+n);
    for(int i=1;i<=n;i++){
        qzh[i]=qzh[i-1]+a[i];
    }
    ll ans=1;
    for(int i=2;i<=n;i++){
        ll nd=a[i];
        const ll R=i-1;
        ll l=1,r=R;
        ll res=-1;
        while(l<=r){
            ll mid=(l+r)/2;
            if(check(mid,i)){
                r=mid-1;
                res=mid;
            }else{
                l=mid+1;
            }
        }
        if(res==-1) continue;
        res=R-res+1;
        ans=max(ans,res+1);
    }
    cout<<ans;
    return 0;
}
