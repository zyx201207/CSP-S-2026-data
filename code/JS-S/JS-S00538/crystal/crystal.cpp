#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=5e5+5;
int a[N],s[N];
signed main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    int n,k;cin>>n>>k;
    for (int i=1;i<=n;i++) cin>>a[i];
    sort(a+1,a+n+1);
    for (int i=1;i<=n;i++) s[i]=s[i-1]+a[i];
    int p=0,ans=0;
    for (int i=1;i<=n;i++){
        while (p<i&&(i-p)*a[i]-(s[i]-s[p])>k) p++;
        ans=max(ans,i-p);
    }
    cout<<ans;
    return 0;
}

// 14:33 100pts