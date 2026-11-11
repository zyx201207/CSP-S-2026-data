#include <bits/stdc++.h>
#define int long long
#define uint __int128
using namespace std;
const int maxn = 5e5 + 10;
int n,m,a[maxn],ans[maxn],mx;
unordered_map<int,int> mp;
queue<int> q;
signed main()
{
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    cin >> n >> m;
    for(int i = 1;i <= n;i++)
    {
        cin >> a[i];
        mp[a[i]] ++;
    }
    sort(a + 1,a + n + 1);
    int len = unique(a + 1,a + n + 1) - a - 1;
    ans[1] = mp[a[1]];
    mx = mp[a[1]];
    q.push(1);
    int sum = 0;
    for(int i = 2;i <= len;i++)
    {
        ans[i] = ans[i - 1] + mp[a[i]];
        sum += ans[i - 1] * (a[i] - a[i - 1]);
        while(sum > m && !q.empty())
        {
            sum -= a[i] - a[q.front()];
            mp[a[q.front()]] --;
            ans[i]--;
            if(!mp[a[q.front()]])
                q.pop();
        }
        q.push(i);
        //cout << ans[i] << " ";
        mx = max(mx,ans[i]);
    }
    //cout << "\n";
    cout << mx << "\n";
    return 0;
}