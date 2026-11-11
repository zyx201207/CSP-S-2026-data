#include <bits/stdc++.h>
#define int long long
#define pb push_back
using namespace std;
const int N=2e6+20;
const int INF=INT_MAX;
int a[N],dp[N];
int n,d,ans=0,s;
void solve()
{
    ans = 0;
    cin >> n >> d;
    for (int i=1;i<=n;i++)
        cin >> a[i];
    for (s=1;s<n;s++)
    {
        dp[s] = 0;
        for (int i=s+1;i<=n;i++)
        {
            int j=i-1;
            while (a[i] - a[j] <= d && j >= s)
                j--;
            j++;
            vector<int> tmp;
            for (int k=j;k<i;k++)
                tmp.push_back(dp[k]+1);
            if (!tmp.size())
                break;
            sort(tmp.begin(),tmp.end());
            if ((tmp.size() == 2 && tmp[0] == tmp[1]) || (tmp.size() >= 3 && (tmp[0] == tmp[1] && tmp[1] != tmp[2])))
                ans++;
            dp[i] = tmp[0];
        }
    }
    cout << ans << endl;
    return;
}
signed main()
{
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    int c,T;
    cin >> c >> T;
    while (T--)
        solve();
    return 0;
}