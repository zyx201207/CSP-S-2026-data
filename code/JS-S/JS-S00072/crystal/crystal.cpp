#include<bits/stdc++.h>
#define int long long
using namespace std;

const int N = 5e5 + 5;
int a[N],s[N];

signed main()
{
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n,k;
    cin >> n >> k;
    for(int i = 1;i <= n;i++)
        cin >> a[i];
    sort(a + 1,a + n + 1);
    for(int i = 1;i <= n;i++)
        s[i] = s[i - 1] + a[i];
    int ans = 0;
    for(int i = 1;i <= n;i++)
    {
        int l = 1,r = i;
        while(l < r)
        {
            int m = (l + r) >> 1;
            if(s[i] - s[m - 1] + k >= (i - m + 1) * a[i]) r = m;
            else l = m + 1;
        }
        ans = max(ans,i - l + 1);
    }
    cout << ans << endl;
    return 0;
}
