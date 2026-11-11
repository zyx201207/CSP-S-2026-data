#include<bits/stdc++.h>
#define int long long
using namespace std;
const int maxn = 2e5 + 5;
int a[maxn];
char c[maxn];
int n, sum;

signed main()
{
    freopen("string.in", "r", stdin);
    freopen("string.out", "w", stdout);

    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    cin >> n;
    for(int i = 1; i <= n; i++) cin >> a[i] >> c[i], sum += a[i];

    int pos1 = 1, pos2 = n, cnt1 = a[1], cnt2 = a[n];
    int cnt = sum / 2, ans = 0;


    while(cnt)
    {
        if(cnt1 <= cnt2)
        {
            if(cnt <= cnt1)
            {
                cnt1 -= cnt;
                cnt2 -= cnt;
                ans += (c[pos1] != c[pos2]) * cnt;
                cnt = 0;
                break;
            }else
            {
                //cnt > cnt1
                cnt -= cnt1;
                cnt2 -= cnt1;
                ans += (c[pos1] != c[pos2]) * cnt1;
                if(cnt2 == 0) pos2--, cnt2 = a[pos2];
                pos1++, cnt1 = a[pos1];
            }
        }else
        {
            //cnt1 > cnt2
            if(cnt <= cnt2)
            {
                cnt1 -= cnt;
                cnt2 -= cnt;
                ans += (c[pos1] != c[pos2]) * cnt;
                cnt = 0;
                break;
            }else
            {
                //cnt > cnt2
                cnt -= cnt2;
                cnt1 -= cnt2;
                ans += (c[pos1] != c[pos2]) * cnt2;
                if(cnt1 == 0) pos1++, cnt1 = a[pos1];
                pos2--, cnt2 = a[pos2];
            }
        }
    }
    cout << ans;

    return 0;
}
