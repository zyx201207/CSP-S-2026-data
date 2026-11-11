#include<bits/stdc++.h>
using namespace std;
long long a[500010];
int main()
{
    freopen("crystal.in", "r", stdin);
    freopen("crystal.out", "w", stdout);
    int n;
    long long m, mx = -1;
    cin >> n >> m;
    for(int i = 1; i <= n; i++) cin >> a[i];
    sort(a+1, a+n+1);
    for(int i = 1; i <= n; i++)
    {
        long long s = 1, cnt = 0;
        for(int j = i - 1; j > 0; j--)
        {
            if(a[i] - a[j] + cnt > m) break;
            s++;
            cnt += a[i] - a[j];
        }
        mx = max(mx, s);
    }
    cout << mx;
    cout << "\n";
    return 0;
}
