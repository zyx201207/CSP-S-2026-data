#include <bits/stdc++.h>
using namespace std;
int n, m;
int a[500001];
bool b[300001];
int c[300001];
vector<int> v;
bool cmp(int x, int y)
{
    return x > y;
}
int main()
{
    freopen("card.in", "r", stdin);
    freopen("card.out", "w", stdout);
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    for (int i = 1; i <= n; i++)
    {
        v.clear();
        for (int j = i; j <= n; j++)
        {
            if (!b[a[j]])
            {
                v.push_back(a[j]);
                b[a[j]] = 1;
            }
            else
            {
                int ans = 0;
                for (int i = 0; i < v.size(); i++)
                {
                    if (v[i] == b[j])
                    {
                        ans = i;
                        break;
                    }
                }
                int num = 0;
                for (int i = ans; i < v.size(); i++)
                {
                    b[v[i]] = 0;
                    v[i] = 0;
                    num++;
                }
                sort(v.begin(), v.end(), cmp);
                while(num--) v.pop_back();
                v.push_back(a[j]);
                b[a[j]] = 1;
            }
        }
        for (int i = 0; i < v.size(); i++) c[v[i]]++;
        memset(b, 0, 300001);
    }
    for (int i = 1; i <= m; i++)
    {
        cout << c[i] << ' ';
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
