#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using pii=pair<int,int>;
const int N=2e6+5;
int c,T;
ll a[N];
vector<pii> v;
bool vis[N];
bool check(ll x,ll y,ll d){
    if(abs(x-y)<=d)return true;
    return false;
}
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    cin>>c>>T;
    while(T--){
        v.clear();
        int n;ll d;cin>>n>>d;
        for(int i=1;i<=n;i++){
            cin>>a[i];
        }
        for(int i=1;i<=n-3;i++){
            int l=i,r=i+3;
            if(check(a[l],a[r],d)||(r<n&&check(a[l],a[r+1],d))||(l>1&&check(a[l-1],a[r],d)))continue;
            ll x=a[i],y=a[i+3];
            ll t1=a[i+1],t2=a[i+2];
            if(check(x,t1,d)&&check(x,t2,d)&&check(y,t1,d)&&check(y,t2,d)){
                v.push_back({i,i+3});
                vis[i]=true;vis[i+3]=true;
            }
        }
        if(v.size()==0){cout<<0<<"\n";continue;}
        ll ans=0;
        for(auto [l,r]:v){
            int cnt1=1,cnt2=1;
            while(l>1&&check(a[l-1],a[l],d)&&!check(a[l-1],a[l+1],d)&&!vis[l-1]){
                l--;
                cnt1++;
            }
            while(r<n&&check(a[r+1],a[r],d)&&!check(a[r-1],a[r+1],d)&&!vis[r+1]){
                r++;
                cnt2++;
            }
            ans+=cnt1*cnt2;
        }
        cout<<ans<<"\n";
    }
    return 0;
}
