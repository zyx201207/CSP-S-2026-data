#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 5e5+10,M = 3e3+10;
ll a[N],n,m,ans[N];
int main()
{
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin >> n >> m;
    for (int i = 1;i <= n;i++)
        cin >> a[i];
    ll t = 1,c = n;
    while (t <= n)
    {
        stack <ll> b;
        vector <ll> pos(M);
        vector <bool> flag(M);
        for (int j = t;j <= c;j++)
        {
            if (!flag[a[j]])
            {
                b.push(a[j]);
                flag[a[j]] = 1;
                pos[a[j]] = j;
                continue;
            }
            for (int i = pos[a[j]];i < j;i++)
                b.pop();
            b.push(a[j]);
            pos[a[j]] = (int)b.size()+1;
        }
        while (b.size())
        {
            ans[b.top()]++;
            b.pop();
        }
        t++;
    }
    for (int i = 1;i <= m;i++)
        cout << ans[i] << ' ';
    return 0;
}
