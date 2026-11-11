#include <bits/stdc++.h>
using namespace std;

int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int n;
    cin >> n;
    char s[1000005] = {};
    int a[200005] = {};
    int suma = 1;
    for (int i = 1; i <= n; i++)
    {
        char c;
        cin >> a[i] >> c;
        for (int j = suma; j < a[i]+suma; j++)
        {
            s[j] = c;
        }
        suma += a[i];
    }
    int ans = 0;
    for (int i = 1; i <= (suma-1)/2; i++)
    {
        if(s[i] - 'a' != s[suma-i] - 'a')
        {
            ans++;
        }
    }
    cout << ans;
    return 0;
}
