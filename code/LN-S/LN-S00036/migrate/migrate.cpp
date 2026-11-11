#include<bits/stdc++.h>
using namespace std;
int a[2000010];
int main()
{
    freopen("migrate.in", "r", stdin);
    freopen("migrate.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    int c, t;
    cin >> c >> t;
    while(t--)
    {
        int n, d;
        cin >> n >> d;
        for(int i = 1; i <= n; i++)
        {
            cin >> a[i];
        }
        int flag = 0;
        for(int i = 1; i <= n; i++)
        {
            int f = 0;
            for(int j = 1; j <= n; j++)
            {
                if(abs(a[j] - a[i]) > d)
                {
                    f = 1;
                    break;
                }
            }
            if(f == 1)
            {
                flag = 1;
                break;
            }
        }
        if(!flag)
        {
            long long s = 0;
            for(int i = 1; i < n - 1; i++) s += a[i] * 1ll;
            cout << s << "\n";
        }
        else cout << "0\n";
    }
    return 0;
}
