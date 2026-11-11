#include <bits/stdc++.h>
using namespace std;
int n;
char s[400000000]; //10 ^ 8?
long long cnt = -1, ans = 0;

int main()
{
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
    memset(s, '#', sizeof(s));
    scanf("%d", &n);
    while (n--)
    {
        long long k;
        char x;
        scanf("%lld %c", &k, &x);
        for (int i = 1; i <= k; i++)
        {
            cnt += 2;
            s[cnt] = x;
        }
    }
    int len = cnt, mid = (cnt + 1) / 2;
    for (int i = 1; i <= mid; i+=2)
    {
        if (s[i] != s[len - i + 1]) ans++;
    }
    printf("%d", ans);
    return 0;
}