#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;

const int N=2e6+10;

ll a[N],f[N],g[N],jp[N],n,d;

inline void Solve()
{
    cin >> n >> d;
    for(int i=1;i<=n;i++) cin >> a[i];
    for(int i=1;i<=n;i++) f[i]=g[i]=jp[i]=0;
    int now=1;
    for(int i=1;i<=n;i++)
    {
        while(now<n&&a[now+1]-a[i]<=d) now++;
        jp[i]=now;
    }
    for(int i=1;i<=n;i++)
    {
        if(jp[jp[i]]>jp[i]&&a[jp[jp[i]]]-a[jp[i]-1]>d) f[jp[i]]+=f[i]+1;
    }
    for(int i=n;i>=1;i--)
    {
        int t=jp[i-1]+1;
        if(jp[i]>i&&jp[i]>=t) g[i]+=g[jp[i]]+1+jp[i]-t;
    }
    ll ans=0;
    for(int i=1;i<=n;i++)
    {
        if(jp[jp[i]]==jp[i]) continue;
        if(a[jp[jp[i]]]-a[jp[i]-1]>d) continue;
        if(a[jp[jp[i]]]-a[jp[i]-2]<=d) continue;
        ans+=(f[i]*(a[jp[i]-1]-a[i-1]>d)+1)*g[jp[jp[i]]];
    }
    for(int i=1;i<=n;i++)
    {
        if(jp[jp[i]]==jp[i]) continue;
        if(jp[i]==i+1) continue;
        int l=jp[jp[i]-2]+1,r=jp[jp[i]-1];
        if(l<=r) ans+=(f[i]*(a[jp[i]-1]-a[i-1]>d)+1)*(r-l+1);
    }
    cout << ans << '\n';
}

int main()
{
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int Type,T;
    cin >> Type >> T;
    while(T--)
    Solve();
    return 0;
}