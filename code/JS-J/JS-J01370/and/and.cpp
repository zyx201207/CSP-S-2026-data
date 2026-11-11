#include <bits/stdc++.h>
using namespace std;
bool bs[200005][40];
int ans = 0;
bool res[40];
int n, m;
int kmax = -1;
int st[200005];

int main()
{
    freopen ("and.in", "r", stdin);
    freopen ("and.out", "w", stdout);

    cin >> n >> m;

    for (int i=1; i<=n; i++)
    {
        long long tmp;
        cin >> tmp;
        int k = 0;
        while (tmp!=0)
        {
            bs[i][k] = tmp%2;
            tmp/=2;
            k++;
        }
        if (k>kmax) kmax = k;
    }
    //for (int i=1; i<=n; i++)
    //{
    //    for (int j=0; j<kmax; j++)
    //        cout << bs[i][j];
    //    cout << endl;
    //}
    for (int i = kmax -1; i>=0; i--)
    {
        int cnt =0;
        for (int j=1; j<=n; j++)
        {
            if (st[j]==0 && bs[j][i] == 1) cnt ++;
        }

        if (cnt >=m)
        {
            for (int j=1; j<=n; j++)
            {
                if (bs[j][i] == 0) st[j] = 1;
            }
        }
    }

    //for (int i=1; i<=n; i++) cout << st[i] << endl;
    int x = 0;
    memset(res, 1, sizeof(res));
    for (int i=1; i<=n && x<=m; i++)
    {
        if (st[i] == 0)
        {
            x++;
            for (int j=0; j<=31; j++)
            {
                res[j] = (bs[i][j] &res[j]);
            }
        }
    }
    int fac = 1;
    for (int i=0; i<=31; i++)
    {
    //    cout << res[i];
        ans += res[i] * fac;
        fac*= 2;
    }
    //cout << endl;
    cout << ans;

    fclose (stdin);
    fclose (stdout);
    return 0;
}
