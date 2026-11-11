#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N=5e5+5;
int a[N],s[N];
int n,m;
signed main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    cin>>n>>m;
    for (int i=1;i<=n;++i)
        cin>>a[i];
    sort(a+1,a+n+1);
    for (int i=1;i<=n;++i)
        s[i]=s[i-1]+a[i];
    int l=1,r=1;
    int ans=0;
    for (;r<=n;++r){
        while((r-l)*a[r]-(s[r-1]-s[l-1])>m) ++l;
        ans=max(ans,r-l+1);
    }
    cout<<ans;
    return 0;
}