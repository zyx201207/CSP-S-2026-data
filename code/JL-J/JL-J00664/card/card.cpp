#include <bits/stdc++.h>
using namespace std;
int a[500005], ans[300005], pos[300005];
vector<int> desk;
int main()
{
    freopen("card.in", "r", stdin);
    freopen("card.out", "w", stdout);

    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    for (int i = 1; i <= n; i++)
    {
        desk.clear();
        for (int k = i; k <= n; k++)
        {
            if (pos[a[k]])
            {
                while(desk.size()>pos[a[k]]-1)
                    pos[desk.back()]=0,ans[desk.back()]--,desk.pop_back();
            }
            desk.push_back(a[k]);
            pos[a[k]] = desk.size();
            ans[a[k]]++;
        }
        for (int i = 0; i <= m; i++)
        pos[i] = 0;
    }
    for (int i = 1; i <= m; i++)
        cout << ans[i] <<' ';
    return 0;
}
