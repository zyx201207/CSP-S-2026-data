#include <bits/stdc++.h>
using namespace std;

int n, a1[200005], a2[200005];
char c1[200005], c2[200005];
long long ans;

int main()
{
    freopen("string.in", "r", stdin);
    freopen("string.out", "w", stdout);
    cin >> n;
    for(int i = 1; i <= n; i++)
    {
        cin >> a1[i] >> c1[i];
        a2[i] = a1[i];
        c2[i] = c1[i];
    }
    for(int i = 1, j = n; i <= n && j >= 1; )
    {
        if(a1[i] > a2[j])
        {
            ans += (c1[i] != c2[j]) * a2[j];
            a1[i] -= a2[j];
            j--;
        }
        else if(a1[i] < a2[j])
        {
            ans += (c1[i] != c2[j]) * a1[i];
            a2[j] -= a1[i];
            i++;
        }
        else
        {
            ans += (c1[i] != c2[j]) * a2[j];
            i++;
            j--;
        }
    }
    cout << ans / 2;
    return 0;
}

