#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=5e5+9;
ll n,m;
ll a[maxn];
ll d[maxn];
ll pred[maxn];
ll h[maxn];
vector<pair<ll,ll>>v;
bool cmp(ll x,ll y){
    return x<y;
}
ll check(ll x){
    for(int i=0;i<v.size();i++){
        if(v[i].first==x){
            return v[i].second;
        }
    }
    return 0;
}
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(ll i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+n+1,cmp);
    a[0]=a[n+1]=1e12+9;
    if(m==0){
        ll ans=0,g=1;
        for(int i=2;i<=n;i++){
            if(a[i]==a[i-1]){
                g++;
            }else{
                ans=max(ans,g);
                g=1;
            }

        }
        cout<<ans;
        return 0;
    }
    ll cnt=1;
    for(int i=1;i<=n+1;i++){
        if(a[i]==a[i-1]){
            cnt++;
        }else{
            v.push_back({a[i-1],cnt});
            cnt=1;
        }
    }
    for(ll i=2;i<=n;i++){
        d[i]=a[i]-a[i-1];
        pred[i]=d[i]+d[i-1];
    }
    ll ans=0;
    for(ll i=1;i<=n;i++){
        h[i]=0;
        for(ll j=i+1;j<=n;j++){
            h[j]=h[j-1]+(j-i)*d[j];
            if(h[j]>=m){
                ans=max(ans,j-i);
                if(h[j]==m){
                    ans+=check(a[j]);
                }
                //cout<<"i "<<i<<" "<<j<<" "<<check(a[j])<<"\n";
                break;
            }
        }
        //for(ll i=1;i<=n;i++){
        //    cout<<h[i]<<" ";
        //}
        //cout<<"\n";
    }


    cout<<ans;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
