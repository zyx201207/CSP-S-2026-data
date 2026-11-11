#include <bits/stdc++.h>
using namespace std;
int a, s, d[500001], f[500001], sch, A, ans[500002][300001];
bool ntf(int j)
{
    for (int k = 0; k < j; k++)
        if (f[k] == d[j])
        {
            sch += j - k;
            return 0;
        }
    return 1;
}
int main()
{
    freopen("card.in", "r", stdin);
    freopen("cad.out", "w", stdout);
    cin >> a >> s;
    A = a;
    for (int i = 0; i < a; i++)
        cin >> d[i];
    for (int i = 0; i < a; i++)
    {
        sch = 0;
        for (int j = 0; j < a; j++)
            f[j] = 0;
        for (int j = 0; j < A; j++)//
        {
        if (ntf(j))
            f[j] = d[j];
        else
            f[j - sch] = d[j];
        }//play
        for (int j = 0; j < s; j++)//
            ans[i][f[j]] = 1;
        for (int j = 0; j < s; j++)
            ans[500001][j] += ans[i][j];//count
        A--;
        for (int j = 0; j < A; j++)//
            d[j] = d[j + 1];
        d[A] = 0;//reduce
    }
    for (int i = 0; i < s; i++)
        cout << ans[500001][i] << " ";
    cout << "\n";
    return 0;
}