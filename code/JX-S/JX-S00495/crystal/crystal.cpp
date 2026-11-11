#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 500005;
ll n,m,a[N],ans;
int main()
{
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin >> n >> m;
    for (int i = 1; i <= n ; i ++)
    {
        cin >> a[i];
    }
    if(n == 1)
    {
        cout << 1 << "\n";
        return 0;
    }
    sort(a+1,a+n+1);
    for(int i = 2; i <= n; i ++)
    {
        ll ansr = 0;
        ll ms = m;
        if(a[i] == a[i - 1])
        {
            continue;
        }
        int lan = a[i];

        for(int j = i - 1; j > 0;j --)
        {
            ll mss = lan - a[j];
            while(ms >= mss && a[j] != lan)
            {
                ms -= mss;
                a[j] = lan;
            }
        }
        for (int j = 1; j <= n; j ++)
        {
            if(a[j] == lan)
            {
                ansr ++;
            }
        }
        ans = max(ans,ansr);
    }
    cout << ans;
    return 0;
}
