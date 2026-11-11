#include<bits/stdc++.h>
#define ll long long
#define ull unsigned long long
using namespace std;
const int MAXN = 5e5 + 20;
int n;
ull m;
int a[MAXN];
int b[MAXN];
int main()
{
    freopen("crystal.in", "r", stdin);
    freopen("crystal.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    // code here NO PRINTF OR SCANF
    cin >> n >> m;
    if(n == 1)
    {
        cout << 1 << endl;
        return 0;
    }
    for(int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    sort(a + 1, a + n + 1);
    if(m == 0)
    {
        int ans = -1;
        int res = 1;
        for(int i = 2; i <= n; i++)
        {
            if(a[i - 1] == a[i]) res++;
            else res = 0;
            ans = max(ans, res);
        }
        cout << ans << endl;
        return 0;
    }
    for(int i = 1; i <= n; i++)
    {
        b[i] = b[i - 1] + a[i];
    }
    //for(int i = 1; i < n; i++)
        //cout << b[i] << ' ';
    int res = -1;
    for(int i = 1; i <= n; i++)
    {
        for(int j = n; j >= i; j--)
        {
            if(b[j] - b[i - 1] + m >= a[j] * (j - i + 1))
            {
                res = max(res, j - i + 1);
                break;
            }
        }
    }
    cout << res << endl;
    return 0;
}
