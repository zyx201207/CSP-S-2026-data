#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N = 5e5+10;
int n,m,ans;
int a[N];
int dp[N];
signed main()
{
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    bool flag = true;
    for(int i=1;i<=n;i++) {
        cin>>a[i];
        if(i>=3&&a[i]-a[i-1]!=a[i-1]-a[i-2]) flag = false;
    }
    if(flag){
        int cnt = a[2]-a[1],i=1;
        for(;m>=(cnt+cnt*i)*i/2;i++);
        cout<<i<<"\n";
        return 0;
    }
    sort(a+1,a+1+n);
    for(int i=1;i<=n;i++){
        int j = i-1;
        for(int ct = m;j>=1&&ct>0&&ct>a[i]-a[j];j--){
            ct = ct-a[i]+a[j];
        }
        ans = max(ans,i-j);
    }
    cout<<ans<<"\n";

    return 0;
}
