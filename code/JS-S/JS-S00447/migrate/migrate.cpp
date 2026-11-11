#include<bits/stdc++.h>
#define ll long long
using namespace std;

int x[100005], b[100005][5], ans =0, me = 1, n, d;

void g(int k)
{
    for(int i = 1; i <= n; i++)
        if(x[k] + d >= x[i] && x[k] - d <= x[i])
        {
            if(b[x[i]][0] == -1 ||b[x[i]][0] > b[x[k]][0] + 1)
            {
                b[x[i]][0] = b[x[k]][0] + 1;
                b[x[i]][1] = 1;
                g(i);
            }
            else if(b[x[i]][0] == b[x[k]][0] + 1)
            {
                b[x[i]][1]++;
            }
        }
}
int main()
{
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    int c, t;
    cin >> c>> t;
    while(t--)
    {
        cin >> n >> d;
        for(int i = 1; i <= n; i++)
            cin >> x[i];
        for(int i = 1; i <= n; i++)
        {
            for(int j = 1; j <= n; j++)
                b[j][0] = -1;
            for(int j = 1; j <= n; j++)
                b[j][1] = 0;
            b[i][0] = 0;
            b[i][1] = 1;
            g(i);
            for(int j = i; j <= n; j++)
                if(b[j][1] == 2) ans++;
        }
        cout << ans<< "\n";
        ans = 0;
    }
    return 0;
}
