#include<bits/stdc++.h>
using namespace std;
int n, m;
int a[200005];
bool v[200005];
int ans = 0;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("and.in", "r", stdin);
    freopen("and.out", "w", stdout);
    cin >> n >> m;
    for(int i = 1;i <= n;i++)
    {
        cin >> a[i];
    }
    for(int i = 29;i >= 0;i--)
    {
        int cnt = 0;
        for(int j = 1;j <= n;j++)
        {
            if(v[j]) continue;
            if((a[j] >> i) % 2 == 1) cnt++;
        }
        if(cnt >= m)
        {
            ans |= (1 << i);
            for(int j = 1;j <= n;j++)
            {
                if(v[j]) continue;
                if((a[j] >> i) % 2 == 0) v[j] = 1;
            }
        }

    }
    cout << ans;
    return 0;
}
