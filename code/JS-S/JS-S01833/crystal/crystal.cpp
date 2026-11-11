#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 5*100000+5;
ll a[N];
int cnt[300];
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ll n,m;
    cin>>n>>m;
    bool flag1 = true,flag2 = true;
    cin>>a[1]>>a[2];
    ll d = a[2] - a[1];
    ll mx = max(a[1],a[2]);
    for (int i=3;i<=n;i++)
    {
        cin>>a[i];
        if (a[i] != i) flag1 = false;
        if (a[i] - a[i-1] != d) flag2 = false;
        mx = max(mx,a[i]);
    }
    if (flag1 || flag2)
    {
        m /= d;
        m = min(m,n*(n-1)/2);
        m *= 2;
        ll ans = ll(sqrt(m))+1;
        cout<<ans<<"\n";
        return 0;
    }
    if (mx <= 100)
    {
        int ans = 0;
        for (int i=1;i<=n;i++)
        {
            cnt[a[i]+100]++;
        }
        for (int i=0;i<=200;i++)
        {
            int sum = 0;
            ll m1 = m;
            for (int j=i;j>=0;j--)
            {
                if (i == j)
                {
                    sum += cnt[j];
                    continue;
                }
                int t = min(int(m1/(i-j)),cnt[j]);
                m1 -= t*(i-j);
                sum += t;
            }
            ans = max(ans,sum);
        }
        cout<<ans<<"\n";
        return 0;
    }
    sort(a+1,a+n+1);
    ll ans = 1;
    for (int i=1;i<=n;i++)
    {
        ll m1 = m,cnt = 1;
        for (int j=i-1;j>=1;j--)
        {
            if (m1 >= abs(a[i]-a[j]))
            {
                m1 -= abs(a[i]-a[j]);
                cnt++;
            }
        }
        ans = max(ans,cnt);
    }
    cout<<ans<<"\n";
    return 0;
}
