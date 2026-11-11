#include <bits/stdc++.h>
using namespace std;

unordered_map<int, bool> used;
int cards[500005];
int n, m;
stack<int> current;
int cnt[500005];

int main()
{
    freopen("card.in", "r", stdin);
    freopen("card.out", "w", stdout);

    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i ++)
        scanf("%d", &cards[i]);
    for (int i = 1; i <= n; i ++)
    {
        used.clear();
        for (int j = i; j <= n; j ++)
        {
            while (used[cards[j]])
            {
                used[current.top()] = 0;
                current.pop();
            }
            current.push(cards[j]);
            used[cards[j]] = 1;
         }
         while (!current.empty())
         {
             cnt[current.top()] ++;
             current.pop();
         }
    }
    for (int i = 1; i <= m; i ++)
        printf("%d ", cnt[i]);
}
