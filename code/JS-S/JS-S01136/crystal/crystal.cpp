#include <bits/stdc++.h>
using namespace std;

typedef  long long LL;

const int MAXN = 5e5 + 10;

LL n =0;
LL m = 0;

LL nums[MAXN];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);

    cin >> n >> m;
    for(int i = 1;i <= n;i++)
    {
        cin >> nums[i];
    }

    sort(nums + 1,nums + n + 1);

    LL tou = 1;
    LL has = 0;
    LL ans = 0;
    LL each = 0;
    for(LL i = 2;i <= n;i++)
    {
        each = (i - tou) * (nums[i] - nums[i - 1]);
        while (has + each > m)
        {
            has -= (nums[i - 1] - nums[tou]);
            tou++;
            each -= (nums[i] - nums[i - 1]);
        }
        has += each;
        ans = max(ans,i - tou + 1);
    }

    cout << ans << endl;

    fclose(stdin);
    fclose(stdout);
    return 0;
}
