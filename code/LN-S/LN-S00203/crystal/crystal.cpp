#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m;
int a[500010];
int s[500010];
int l[500010];
signed main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++)
        cin>>a[i];
    int ans=0;
    sort(a+1,a+1+n);
    for(int i=1;i<=n;i++){
        s[i]=s[i-1]+a[i];
        l[i]=1ll*i*a[i]-s[i];
    }
    for(int i=1;i<=n;i++){
        auto it=lower_bound(l+1,l+1+n,l[i]-m);
        if(it!=l+1+n&&*it<=i){
            ans=max(ans,i-*it);
        }
    }
    cout<<ans;
    return 0;
}
