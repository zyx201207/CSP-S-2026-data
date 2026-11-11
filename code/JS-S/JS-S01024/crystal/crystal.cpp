#include <iostream>
#include <algorithm>
using namespace std;
long long a[500001],s[500001],n,m,cnt = 0,ans = 1,s_ = 0,s__ = 0;
int main()
{
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin >> n >> m;
    for(int i = 1;i <= n;i++)
        cin >> a[i];
    sort(a + 1,a + n + 1);
    if(n > 5000)
    {
        for(int i = 1;i < n;i++)
            s[i] = a[i+1] - a[i];
        for(int i = 1;i < n;i++)
            s_ = min(s_,s[i]);

        for(int i = 1;i < n;i++)
            if(s_ == s[i])
            {
                s__ = i;
                break;
            }
        for(int i = 1;i < n;i++)
        {
            if(i + s__ - 1 > n || cnt + i * s[i+s__-1] > m)
                break;
            else
            {
                cnt += i * s[i+s_-1];
                ans++;
            }
        }
        cout << ans;
    }
    else
    {
        long long ans[500001],cnt_ = 0,ans_max = 0;
        for(int i = 1;i < n;i++)
        {
            for(int j = n-i+1;j >= 1;j--)
            {
                if(cnt + a[j] - a[i] > m)
                    j = 0;
                else
                {
                    ans[i]++;
                    cnt += (a[i] - a[i]);
                }
            }
            for(int i = 1;i <= n;i++)
                ans_max = max(ans[i],ans_max);
        }
        cout << ans_max;
    }

    return 0;
}
