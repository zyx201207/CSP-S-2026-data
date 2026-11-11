#include<bits/stdc++.h>
using namespace std;
long long a[500010], c[300010], b[500010];
int main()
{
    freopen("card.in", "r", stdin);
    freopen("card.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, m, flag = 1;
    cin >> n >> m;
    for(int i = 1; i <= n; i++)
    {
        cin >> a[i];
        if(a[i] < a[i-1]) flag = 0;
    }
    if(flag)
    {
        for(int i = 1; i <= n; i++) c[a[i]]++;
        for(int i = 1; i <= n; i++)
        {
            c[i] += c[i-1];
        }
        for(int i = 1; i<= m; i++) cout << c[i] <<" ";
        return 0;
    }
    for(int i = 1; i <= n; i++)
    {
        int cnt = 0;
        for(int j = i; j <= n; j++)
        {
            int f = 0;
            for(int k = 1; k <= cnt; k++)
            {
                if(b[k] == a[j])
                {
                    f = k;
                    break;
                }
            }
            if(f == 0) b[++cnt] = a[j];
            else cnt = f;
        }
        for(int j = 1; j <= cnt; j++) c[b[j]]++;
    }
    for(int i = 1; i <= m; i++) cout << c[i] << " ";
    cout << "\n";
    return 0;
}
