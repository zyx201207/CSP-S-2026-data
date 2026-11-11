#include <bits/stdc++.h>
using namespace std;

vector< pair<long long, char> > str(1);
long long change = 0LL;
int n;

int main()
{
    freopen("string.in", "r", stdin);
    freopen("string.out", "w", stdout);

    scanf("%d", &n);
    for (int i = 1; i <= n; i ++)
    {
        long long cntStr;
        char c[2];
        scanf("%lld%s", &cntStr, c + 1);
        str.push_back(pair<long long, char>(cntStr, c[1]));
    }
    int l = 1, r = n;
    while (l < r)
    {
        if (str[l].second != str[r].second)
        {
            change += min(str[l].first, str[r].first) + 0LL;
        }
        if (str[l].first < str[r].first)
        {
            str[r].first -= str[l].first;
            l ++;
        }
        else if (str[l].first > str[r].first)
        {
            str[l].first -= str[r].first;
            r --;
        }
        else
        {
            l ++;
            r --;
        }
    }
    printf("%lld", change);
}
