#include <bits/stdc++.h>
#define int long long
using namespace std;
int n,m,a[500005],ch[500005],ans;
signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++) cin>>a[i];
    sort(a+1,a+n+1);
    for(int i=2;i<=n;i++) ch[i]=a[i]-a[i-1];
    int sum=0,l=1;
    for(int i=1;i<=n;i++){
        sum+=ch[i]*(i-l);
        while(l<=i&&sum>m) sum-=a[i]-a[l],l++;
        ans=max(ans,(i-l+1));
    }
    cout<<ans;
    return 0;
}
