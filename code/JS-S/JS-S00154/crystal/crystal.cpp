#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N = 5e5+10;
int n,m,a[N],p[N],q[N];

signed main()
{
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    cin >> n >> m;
    for(int i=1;i<=n;i++) {cin >> a[i];}
    sort(a+1,a+n+1);
    for(int i=1;i<=n;i++) q[i] = 1;
    int ans = 1;
    for(int i=1;i<n;i++) {
        bool flag = 1;
        if(p[i]+(a[i+1]-a[i])*q[i] > m)
        {
            flag = 0;
            q[i] = 1;
            p[i] = 0;
        }
        if(flag) ans = max(ans,q[i]+1);
        p[i+1] = p[i]+(a[i+1]-a[i])*q[i];
        q[i+1] += q[i];
    }
    cout << ans ;
    return 0;
}
