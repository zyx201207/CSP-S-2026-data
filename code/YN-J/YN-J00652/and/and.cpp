#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N=2e5+5;
ll n,m,a[N],ans,cnt[32],f[N];
bool taska=1;

vector<ll> g[32];

pair<ll,ll> tt[N];

int main() {
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin.tie(0);
    cin>>n>>m;
    int lgn=log2(n);
    if(pow(2,lgn)!=n){
        taska=0;
    }
    for(int i=1;i<=n;i++){
        cin>>a[i];
        if(a[i]!=i-1){
            taska=0;
        }
        int tmp=a[i];
        for(int j=0;j<=31;j++){
            if((tmp>>j)&1){
                cnt[j]++;
                g[j].push_back(i);
            }
        }
    }
    if(taska){
        ll ansa=a[n];
        for(int i=n-1;i>=n-m+1;i--){
            ansa&=a[i];
        }
        cout<<ansa<<"\n";
        return 0;
    }
    for(int i=32;i>=0;i--){
        if(cnt[i]>=m){
            for(auto j:g[i]){
                f[j]+=i+1;
            }
        }
    }
    for(int i=1;i<=n;i++){
        tt[i]=make_pair(f[i],i);
    }
    sort(tt+1,tt+1+n,greater<pair<ll,ll> >());
    ans=a[tt[1].second];
    for(int i=2;i<=m;i++){
        ans&=a[tt[i].second];
    }
    cout<<ans<<"\n";
    return 0;
}
