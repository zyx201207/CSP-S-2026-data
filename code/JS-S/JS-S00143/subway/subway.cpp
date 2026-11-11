#include <bits/stdc++.h>
using namespace std;
const int N = 5e5 + 5;
int w[N];
map < int, int > m;
queue  < int > g[N];
string s;
void merge(int x)
{
    int now = g[x].front();
    g[x].pop();
}
int sum(int x, int y)
{
    int ans = 0;

}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    freopen("subway.in", "r", stdin);
    freopen("subway.out", "w", stdout);

    int c, n, m, d, q;
    cin >> c >> n >> m >> d >> q;
    for(int i = 1; i <= m; i++)
        cin >> w[i];
    if(c >= 7 && c <= 11)
    {
        string s = "";
        for(int i = 1; i <= n; i++)
        {
            int k;
            cin >> k;
            int a1, a2, t1, t2;
            cin >> a1 >> t1 >> a2 >> t2;
            g[a1].push(a2);
            g[a1].push(t1);
            g[a2].push(a1);
            g[a2].push(t2);
        }
        merge(1);
        while(q--)
        {
            int x, y;
            cin >> x >> y;
            cout << sum(x, y) << endl;
        }
    }
    return 0;
}
//such a problem, i cant even believe what i am writing
