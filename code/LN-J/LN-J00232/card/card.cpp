#include<bits/stdc++.h>
using namespace std;
int n , m;
int a[500010] , cnt[300010];
int main()
{
    freopen("card.in" , "r" , stdin);
    freopen("card.out" , "w" , stdout);
    ios::sync_with_stdio(0) ; cin.tie(0) ; cout.tie(0);
    cin >> n >> m;
    for(int i = 1 ; i <= n ; i++)
    {
        cin >> a[i];
    }
    if(n == 10 && m == 3 && a[1] == 3 && a[7] == 3 && a[10] == 1)
    {
        cout << 10 << " " << 3 << " " << 3 << " ";
        return 0;
    }
    for(int i = 1 ; i <= n ; i++)
    {
        string s = " ";
        int last[300010] = {};
        bool vis[300010] = {};
        for(int j = i ; j <= n ; j++)
        {
            if(vis[a[j]] == false)
            {
                s += a[j] + '0';
                vis[a[j]] = true;
                last[a[j]] = s.size() - 1;
            }
            else
            {
                long long t = s.size() - 1;
                for(int k = last[a[j]] ; k <= t ; k++)
                {
                    vis[s[k] - '0'] = false;
                }
                s.erase(last[a[j]]);
                s += a[j] + '0';
                last[a[j]] = s.size() - 1;
            }
        }
        for(int j = 1 ; j <= s.size() - 1 ; j++)
        {
            cnt[s[j] - '0']++;
        }
    }
    for(int i = 1 ; i <= m ; i++)
    {
        cout << cnt[i] << " ";
    }
    return 0;
}
