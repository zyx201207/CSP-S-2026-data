#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;

const int N=5e5+10;

ll a[N],s[N],n,m;

inline void Solve()
{
    cin >> n >> m;
    for(int i=1;i<=n;i++) cin >> a[i];
    sort(a+1,a+n+1);
    for(int i=1;i<=n;i++) s[i]=s[i-1]+a[i];
    int ans=0;
    for(int i=1;i<=n;i++)
    {
        int l=1,r=i,pos=i+1;
        while(l<=r)
        {
            int mid=(l+r)>>1;
            if(a[i]*(i-mid+1)-(s[i]-s[mid-1])<=m) pos=mid,r=mid-1;
            else l=mid+1;
        }
        ans=max(ans,i-pos+1);
    }
    cout << ans << '\n';
}

int main()
{
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    Solve();
    return 0;
}