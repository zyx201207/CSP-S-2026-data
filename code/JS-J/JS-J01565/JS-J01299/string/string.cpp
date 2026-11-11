#include <bits/stdc++.h>
using namespace std;

int main()
{
    freopen("string.in", "r", stdin);
    freopen("string.out", "w", stdout);
    int n;
    LL a, ans = 0;
    cin >> n;
    char c[n + 1];
    LL sum1[n + 1], sum2[n + 1];
    sum1[0] = sum2[0] = 0;
    for(int i = 1; i <= n; i++)
    {
        cin >> a >> c[i];
        sum1[i] = sum1[i - 1] + a;
    }
    for(int i = 1; i <= n; i++)
        sum2[i] = sum1[n] - sum1[n - i];
    LL l = 1;
    int r1 = 1, r2 = 1;
    while(r1 <= n && r2 <= n)
    {
        if(sum1[r1] < sum2[r2])
        {
            if(c[r1] != c[n - r2 + 1])
                ans += sum1[r1] - l + 1;
            l=sum1[r1]+1;
            r1++;
        }
        else if(sum2[r2] < sum1[r1])
        {
            if(c[r1] != c[n - r2 + 1])
                ans += sum2[r2] - l + 1;
            l=sum2[r2]+1;
            r2++;
        }
        else
        {
            if(c[r1] != c[n - r2 + 1])
                ans += sum1[r1] - l + 1;
            l=sum1[r1]+1;
            r1++,r2++;
        }
    }
    cout<< ans / 2;
    return 0;
}
