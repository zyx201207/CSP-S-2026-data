#include<bits/stdc++.h>
using namespace std;
const int maxn = 5e5 + 5;
int n, m;
int cnt[maxn], a[maxn];
int st[maxn], top = 0;
int pos[maxn];

signed main()
{
    freopen("card.in", "r", stdin);
    freopen("card.out", "w", stdout);

    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    cin >> n >> m;
    for(int i = 1; i <= n; i++) cin >> a[i];

    for(int k = 1; k <= n; k++)
    {
        for(int i = 1; i <= m; i++) pos[i] = 0;
        top = 0;

        for(int i = k; i <= n; i++)
        {
            if(pos[a[i]] <= top && st[pos[a[i]]] == a[i]) top = pos[a[i]];
            else st[++top] = a[i], pos[a[i]] = top;
        }
        for(int i = 1; i <= top; i++)
            cnt[st[i]]++;

        /*
        cout << "game " << k << " : ";
        for(int i = 1; i <= top; i++)
            cout << st[i] << " ";
        cout << "\n";
        */
    }

    for(int i = 1; i <= m; i++)
        cout << cnt[i] << " ";
    cout << "\n";

    return 0;
}
