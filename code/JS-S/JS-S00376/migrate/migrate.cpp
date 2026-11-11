#include<bits/stdc++.h>
using namespace std;
long long n, d;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("migrate.in", "r", stdin);
    freopen("migrate.out", "w", stdout);
    int c, t;
    cin >> c >> t;
    while(t--)
    {
        cin >> n >> d;
        if(n == 1)
        {
            cout << 0 << endl;
            continue;
        }
        vector <int> u(n + 5), n1(n + 5), n2(n + 5);
        for(int i = 1;i <= n;i++)
        {
            cin >> u[i];
        }

        if(10 < c && 12 >= c)
        {
            long long a1 = u[1], a2 = u[2];
            long long p = d / (a2 - a1);
            if(p <= 1)
            {
                cout << 0 << endl;
                continue;
            }
            cout << max(0LL, n - 1 - p) << endl;
            continue;
        }
        int l = 1, r = 1;
        while(l < n)
        {
            while(r < n)
            {
                if(u[r + 1] - u[l] > d) break;
                r++;
            }
            n1[l] = r - l;
            l++;
        }
        l = n, r = n;
        while(r > 1)
        {
            while(l > 1)
            {
                if(u[r] - u[l - 1] > d) break;
                l--;
            }
            n2[r] = r - l;
            r--;
        }
        n2[1] = 0;
        n1[n] = 0;
        if(12 < c && 14 >= c)
        {
            int cnt2 = 0;
            for(int i = 1;i <= n;i++)
            {
                for(int j = n;j >= i;j--)
                {
                    if(n1[i] + i - (j - n2[j]) == 1) {
                        cnt2++;
                    }
                    else if(n1[i] + i - (j - n2[j]) > 1) break;
                }
            }
            cout << cnt2 << endl;
        }
    }
    return 0;
}
