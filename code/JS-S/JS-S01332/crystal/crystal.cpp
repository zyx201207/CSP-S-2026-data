#include <bits/stdc++.h>
using namespace std;
long long m,s[500005],pre[500005];
int n,ans;
bool check(int l,int r,long long x)
{
    return pre[r] - pre[l - 1] + m >= x * (r - l + 1);
}
int main()
{
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        cin >> s[i];
    sort(s + 1,s + n + 1);
    for (int i = 1; i <= n; i++)
    {
        pre[i] = pre[i - 1] + s[i];
        if (s[i] != s[i + 1] || i == n)
        {
            int l = 1,r = n;
            while(l < r)
            {
                int mid = l + r >> 1;
                if (check(mid,i,s[i]))
                    r = mid;
                else
                    l = mid + 1;
            }
            ans = max(ans,i - l + 1);
        }
    }
    cout << ans;
    return 0;
}
