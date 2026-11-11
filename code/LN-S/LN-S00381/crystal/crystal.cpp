#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,m,a[500001],ma=LLONG_MIN,mi=LLONG_MAX,mac,mas,ch[500001];
int main(){
    freopen("crystal.in","r",stdin);freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    cin>>n>>m;
    if(n==1){
        cout<<1;
        return 0;
    }bool f=1,ok=1;
    for(ll i=1;i<=n;i++){
        cin>>a[i];
        mi=min(mi,a[i]);ma=max(ma,a[i]);
        if(a[i]!=i)ok=0;
        if(i==1)continue;
        if(a[i]!=a[i-1])f=0;
    }if(f){
        cout<<n;
        return 0;
    }if(ok){
        ll la=a[n],id=n,ans=1;
        while(m>=0&&id>=1){
            id--;
            m-=(la-a[id]);
            if(m<0)break;
            ans++;
        }cout<<ans;
        return 0;
    }
    for(ll i=mi;i<=ma;i++){
        ll cnt=0;
        for(ll j=1;j<=n;j++){
            if(a[j]==i)cnt++;
        }if(cnt>mac){
            mac=cnt;
            mas=i;
        }
    }for(ll i=1;i<=n;i++)ch[i]=abs(a[i]-mas);
    sort(ch+1,ch+n+1);
    ll i=1;
    while(i<=n&&m>=0){
        i++;
        m-=ch[i];
    }cout<<i-1;
    return 0;
}
