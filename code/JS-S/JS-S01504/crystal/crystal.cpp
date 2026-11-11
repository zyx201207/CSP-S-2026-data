#include <iostream>
#include <algorithm>
#include <cstdio>
#define int long long
using namespace std;

int arr[500005];
int qwq[500005];
int m;

bool check(int l,int r)
{
    if((r - l + 1) * arr[r] - (qwq[r] - qwq[l - 1]) <= m)
    {
        return true;
    }
    else
    {
        return false;
    }
}

signed main()
{
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n >> m;
    for(int i = 1;i <= n;i++)
    {
        cin >> arr[i];
    }
    sort(arr + 1,arr + 1 + n);
    for(int i = 1;i <= n;i++)
    {
        qwq[i] = qwq[i - 1] + arr[i];
        // cout << qwq[i] << ' ';
    }
    // cout << '\n';
    int maxn = 0;
    for(int i = 1;i <= n;i++)
    {
        int l = i;
        int r = n;
        int ans;
        while(l <= r)
        {
            int mid = (l + r) >> 1;
            if(check(i,mid))
            {
                ans = mid;
                l = mid + 1;
            }
            else
            {
                r = mid - 1;
            }
        }
        // cout << i << " " << ans << " " << check(i,ans) << '\n';
        maxn = max(maxn,ans - i + 1);
    }
    cout << maxn;
    return 0;
}
