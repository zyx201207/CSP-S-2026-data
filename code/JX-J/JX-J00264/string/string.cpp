#include <bits/stdc++.h>
using namespace std;
long long n , ans;

struct Ch
{
    long long a;
    char c;
}str[200005];

int main()
{
    freopen("string.in" , "r" , stdin);
    freopen("string.out" , "w" , stdout);
    cin >> n;
    for (int i = 1;i <= n;i++)
    {
        cin >> str[i].a >> str[i].c;
    }
    int l = 1 , r = n;
    while (l < r)
    {
        if (str[l].c == str[r].c)
        {
            if (str[l].a == str[r].a)
            {
                l++;
                r--;
            }
            else if (str[l].a > str[r].a)
            {
                str[l].a -= str[r].a;
                r--;
            }
            else
            {
                str[r].a -= str[l].a;
                l++;
            }
        }
        else
        {
            if (str[l].a == str[r].a)
            {
                ans += str[l].a;
                l++;
                r--;
            }
            else if (str[l].a > str[r].a)
            {
                ans += str[r].a;
                str[l].a -= str[r].a;
                r--;
            }
            else
            {
                ans += str[l].a;
                str[r].a -= str[l].a;
                l++;
            }
        }
    }
    cout << ans;
    return 0;
}
