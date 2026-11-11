#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll a[2*1000005];
ll n,d;
int cnt,mx;
void dfs(int p,int g,int sum)
{
    if (sum > mx) return;
    if (p == g)
    {
        if (sum == mx) cnt++;
        else if (sum < mx)
        {
            cnt = 1;
            mx = sum;
        }
        return;
    }
    for (int i=p+1;a[i]-a[p]<=d && i<=g;i++)
    {
        dfs(i,g,sum+1);
    }
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    int c,t;
    cin>>c>>t;
    while (t--)
    {
        int ans = 0;
        cin>>n>>d;
        bool flag1 = true;
        cin>>a[1]>>a[2];
        ll D = a[2] - a[1];
        for (int i=3;i<=n;i++)
        {
            cin>>a[i];
            if (a[i] - a[i-1] != D) flag1 = false;
        }
        if (flag1)
        {
            if (d < 2*D) cout<<0<<"\n";
            else
            {
                d /= D;
                cout<<max(0ll,n-((d-1)*d-1)+d*(d-1)-d*2)<<"\n";
            }
        }
        else
        {
            for (int i=1;i<=n;i++)
            {
                for (int j=i+1;j<=n;j++)
                {
                    cnt = 0;
                    mx = 1e9;
                    dfs(i,j,0);
                    if (cnt == 2) ans++;
                }
            }
            cout<<ans<<"\n";
        }
    }
    return 0;
}
