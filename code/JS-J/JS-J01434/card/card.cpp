#include <bits/stdc++.h>
using namespace std;

int a[500005];
int cnt[300005];
int main()
{
    freopen("card.in", "r", stdin);
    freopen("card.out", "w", stdout);

    int n;
    cin >> n;
    int m;
    cin >> m;
    string s = "";
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        s += char(a[i] + '0');
    }

    s = ' ' + s;

    for (int i = 1; i <= n; i++)
    {
        string temp = s;

        for (int j = i; j < temp.size(); j++)
        {
            if (temp.find(s[j]) != j && temp.find(s[j]) >= i && temp.find(s[j]) < j)
            {
                char c = temp[j];
                int t = j;
                temp.erase(temp.find(s[t]), t - 1);
                j = temp.find(c);
            }
        }

        for (int j = i; j < temp.size(); j++)
        {
            cnt[temp[j] - '0']++;
        }
    }

    for (int i = 1; i <= m; i++)
    {
        cout << cnt[i] << ' ';
    }
    return 0;
}
