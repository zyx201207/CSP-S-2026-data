#include <bits/stdc++.h>
using namespace std;

int m, n;
int a[200005];

struct binary
{
    int b[31];
    int num;
} bin[200005];

int cnt[31];

bool cmp(const binary &b1, const binary &b2)
{
    for (int i = 30; i >= 0; i--)
    {
        if (b1.b[i] != b2.b[i])
        {
            return b1.b[i] > b2.b[i];
        }
    }
    return 1;
}

int main()
{
    freopen("and.in", "r", stdin);
    freopen("and.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        binary tmp;
        for (int j = 30; j >= 0; j--)
        {
            tmp.b[j] = (a[i] >> j) & 1;
            cnt[j] += tmp.b[j];
        }
        tmp.num = a[i];
        bin[i] = tmp;
    }
    int p = 30;
    while (cnt[p] < m)
        p--;
    vector<binary> bin2;
    for (int i = 1; i <= n; i++)
    {
        if (bin[i].b[p])
        {
            bin2.push_back(bin[i]);
        }
    }
    sort(bin2.begin(), bin2.end(), cmp);
    int res = bin2[0].num;
    for (int i = 0; i < m; i++)
    {
        res &= bin2[i].num;
    }
    cout << res << endl;
}

/*
累死我了 现在是10:50 
预估目前200pts ac T1+T3
歇一会儿
//feropen
//Genshin Impact
//freopen("and1.in","w",stdin)
//€€£ please let me ac!

Luogu: Juicy233
Bilibili: Juicy233
*/