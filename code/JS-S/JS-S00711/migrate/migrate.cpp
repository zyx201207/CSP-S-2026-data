#include<bits/stdc++.h>
using namespace std;

int n,l_get[200005],r_get[200005],l_cnt[200005],r_cnt[200005];
long long d,x[2000005];

void solve(){
    cin>>n>>d;
    for(int i=1;i<=n;++i){
        cin>>x[i];
    }
    for(int i=1;i<=n;++i){
        l_get[i]=lower_bound(x+1,x+n+1,x[i]-d)-x;
        r_get[i]=upper_bound(x+1,x+n+1,x[i]+d)-1-x;
    }
    for(int i=1;i<=n;++i){
        if(r_get[l_get[i]]==i){
            l_cnt[i]=l_cnt[l_get[i]]+1;
        }
        else{
            l_cnt[i]=1;
        }
    }
    for(int i=n;i>=1;--i){
        if(l_get[r_get[i]]==i){
            r_cnt[i]=r_cnt[r_get[i]]+1;
        }
        else{
            r_cnt[i]=1;
        }
    }
    long long ans=0;
    for(int l=1,r=1,r_mx=1;l<n;++l){
        while(r<=n && l_get[r]<r_get[l]-1){
            ++r;
        }
        if(r>n || l_get[r]>=r_get[l]){
            continue;
        }
        while(r_mx<n && l_get[r_mx+1]<=r_get[l]-1){
            ++r_mx;
        }
        ans+=r_mx-r+1LL*l_cnt[l]*r_cnt[r_mx];
    }
    cout<<ans<<'\n';
}

int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int c,t;
    cin>>c>>t;
    while(t--){
        solve();
    }
    return 0;
}
