#include<bits/stdc++.h>
using namespace std;
int cnt[1000005];
struct Node
{
    long long zhi;
    bool bl;
}ans[10000005];
int a[1000005];
int main()
{
    freopen("card.in", "r", stdin);
    freopen("card.out", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    bool bst = true;
    int n, m;
    cin >> n >> m;
    for(int i = 1; i <= n; i++)
    {
        cin >> a[i];
        if(a[i] < a[i - 1])
            bst = false;
    }
    if(bst == true)
    {
        for(int i = 1; i <= m; i++)
            cout << n << " ";
    }
    else
    {
        long long len = 0;
        for(int i = 1; i <= n; i++)
        {
            len = 0;
            for(int j = i; j <= n; j++)
            {
                bool st = false;
                for(int k = 1; k <= len; k++)
                {
                    if(a[j] == cnt[k])
                    {
                        len -= len - k;
                        cnt[len] = a[j];
                        st = true;
                        break;
                    }
                }
                if(st == false)
                {
                    len++;
                    cnt[len] = a[j];
                }
            }
            for(int j = 1; j <= len; j++)
            {
                if(ans[cnt[j]].bl != true)
                {
                    ans[cnt[j]].zhi++;
                    ans[cnt[j]].bl = true;
                }
            }
            for(int j = 1; j <= len; j++)
                cnt[j] = 0;
            for(int j = 1; j <= m; j++)
                ans[j].bl = false;
        }
        for(int i = 1; i <= m; i++)
            cout << ans[i].zhi << " ";
    }
    return 0;
}
