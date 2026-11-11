#include<bits/stdc++.h>
using namespace std;
long long c,t,n,pre,prel,prel2,d,a[2000005],ans;
void sv(long long l,long long r){
    if(l==r||l+1==r||l+2==r)return ;
    prel=l-1;
    prel2=0;
    for(long long i=l+1;i<r-1;i++){
        if(a[i+2]-a[i]<=d&&a[i+1]-a[i-1]<=d){
            if(prel2)ans+=(i-prel2-1ll)*(prel2-prel+1ll);
            prel2=prel;
            prel=i;
        }
    }
    ans+=(r-prel2-1ll)*(prel2-prel+1ll);
    return ;
}
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);cout.tie(nullptr);
    cin>>c>>t;
    while(t--){
        cin>>n>>d;
        for(int i=1;i<=n;i++)cin>>a[i];
        pre=1ll;
        ans=0ll;
        for(long long i=2;i<=n;i++){
            if(a[i]-a[i-1]>d){
                sv(pre,i-1ll);
                pre=i;
            }
        }
        sv(pre,n);
        cout<<ans<<'\n';
    }
    return 0;
}
