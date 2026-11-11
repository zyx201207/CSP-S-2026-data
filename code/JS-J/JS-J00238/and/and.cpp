#include <bits/stdc++.h>
using namespace std;

vector<int> cond;
unsigned int n, m, k = 0x7FFFFFFF, maxbit = 31, result = 0;
int cnt[40];
bool keep[40];

void updA(vector<int>& p)
{
    sort(p.begin(), p.end());
    for (int bitE = 0; bitE <= 30; bitE ++)
    {
        int allowed = 0;
        for (int k : p)
            if ((1 << (bitE - 1)) & k) allowed ++;
        cnt[bitE] = allowed;
    }
}

int main()
{
    freopen("and.in", "r", stdin);
    freopen("and.out", "w", stdout);

    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i ++)
    {
        int x;
        scanf("%d", &x);
        cond.push_back(x);
    }

    while (maxbit > 1) {
        updA(cond);
        sort(cond.begin(), cond.end());
        while (cnt[maxbit] < m && maxbit >= 1)
            maxbit --;
        keep[maxbit] = 1;
        for (int &k : cond)
        {
            if (k < (1 << (maxbit - 1)))
                k = 0;
            else
                k = k & ((1 << (maxbit - 1)) - 1);
        }
    }
    for (int i = 31; i >= 1; i --)
    {
        result += (1 << (i - 1)) * keep[i];
    }
    printf("%d", result);
}
