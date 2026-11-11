#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,m,a[500010],cnt[500010],p[500010],p2[500010],ans;
vector<ll>c;
signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(ll i=1;i<=n;i++){
        cin>>a[i];
        c.push_back(a[i]);
    }
    sort(a+1,a+n+1);
    sort(c.begin(),c.end());
    c.erase(unique(c.begin(),c.end()),c.end());
    for(ll i=1;i<=n;i++){
        a[i]=lower_bound(c.begin(),c.end(),a[i])-c.begin();
        cnt[a[i]]++;
    }
    for(ll i=0;i<c.size();i++){
        p[i]=(i==0?0:p[i-1])+cnt[i];
        p2[i]=(i==0?0:p2[i-1])+cnt[i]*c[i];
    }
    for(ll i=0;i<c.size();i++){
        ll L=-1,R=i,z=0;
        for(;L+1<R;){
            ll mid=(L+R)/2,x=0;
            x+=(p[i-1]-p[mid-1])*c[i];
            x-=p2[i-1]-p2[mid-1];
            if(x>m){
                L=mid;
            }
            else{
                R=mid;
                z=x;
            }
        }
        ll x=p[i]-(R==0?0:p[L]);
        if(R!=0)x+=(m-z)/(c[i]-c[L]);
        ans=max(ans,x);
    }
    cout<<ans;
    return 0;
}
