#include <bits/stdc++.h>//t3 : migrate
#define ll long long
using namespace std;

int c,t,n;
ll d,x[2000007];
int b[2000007];

/*
0 2
4 2
1 2 3 4
5 2
1 2 3 4 5

0 2
5 3
-2 -1 0 1 2
6 2
-4 -3 -2 -1 3 6

0 1
9 4
1 3 5 9 11 13 15 17 21

0 1
6 1200
-1000 -600 -200 200 600 1000
*/

int main()
{
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    cin >> c >> t;
    while (t--)
    {
        memset(b,0,sizeof b);
        cin >> n >> d;
        for (int i = 1;i <= n;i++)
        {
            cin >> x[i];
        }
        int tot = 0;
        ll ans = 0;
        map<int,pair<int,int> >mp;
        int pos = 1;
        for (int i = 1;i <= n - 3;i++)
        {
            for (int j = i + 3;j <= n;j++)
            {
                if (x[j] - x[i] <= d)continue;
                int cnt = 0;
                for (int k = i + 1;k <= j - 1;k++)
                {
                    if (x[k] - x[i] <= d && x[j] - x[k] <= d)
                    {
                        cnt++;
                    }
                    if (cnt >= 3)break;
                }
                if (cnt == 2)
                {
                    mp[++tot] = {i,j};
                    b[i] = b[j] = tot;
                }
            }
        }

        for (int k = 1;k <= tot;k++)
        {
            pair<int,int>p = mp[k];
            int i = p.first;
            int j = p.second;
            int l = 1,r = 1;
            while (i - l >= 1 && !b[i - l] && x[i - l + 1] - x[i - l] <= d)
            {
                l++;
            }
            while (j + r <= n && !b[j + r] && x[j + r] - x[j - 1 + r] <= d)
            {
                r++;
            }
            ans += l * r;
        }
        cout << ans << endl;
    }
    return 0;
}
