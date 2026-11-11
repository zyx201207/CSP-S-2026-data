#include<bits/stdc++.h>
using namespace std;
#define int long long
const int maxn=5e5+5;
int n,m,a[maxn],s[maxn],ans;
signed main()
{
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++) cin>>a[i];
    sort(a+1,a+n+1);
    for(int i=1;i<=n;i++) s[i]=s[i-1]+a[i];
    int l=1;
    for(int r=1;r<=n;r++)
    {
        while(l<=r&&(r-l+1)*a[r]-(s[r]-s[l-1])>m) l++;
        ans=max(ans,r-l+1);
    }
    cout<<ans;
    return 0;
}
