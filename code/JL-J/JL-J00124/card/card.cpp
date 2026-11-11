#include <bits/stdc++.h>
using namespace std;

queue<int> q;
int n, m, a[10000005], cnt[10000005];
bool b[10000005];

int main()
{
    freopen("card.in", "r", stdin);
    freopen("card.out", "w", stdout);

    cin >> n >> m;

    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }

    for (int j = 1; j <= n; j++)
    {
        memset(b, false, sizeof(b));

        for (int i = j; i <= n; i++)
        {
            if(b[a[i]] == 0)
            {
                q.push(a[i]);
                b[a[i]] = 1;
            }
            else
            {
                while(q.empty() == false)
                {
                    b[q.front()] = 0;
                    q.pop();
                }
                q.push(a[i]);
                b[a[i]] = 1;
            }

        }
        while (q.empty() == false)
        {
            cnt[q.front()]++;
            q.pop();
        }
    }

    for (int i = 1; i <= m; i++)
    {
        cout << cnt[i] << " ";
    }

    return 0;
}
