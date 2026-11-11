#include <bits/stdc++.h>
using namespace std;
long long n,k,ans;
struct node
{
    long long cnt;
    char ch;
}a[2000005],s[2000005];
int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin >> n;
    for(int i = 1 ; i <= n ; i++) cin >> a[i].cnt >> a[i].ch;
    for(int i = 1 ; i <= n ; i++)
    {
        if(a[i].ch != a[i - 1].ch)
        {
            k++;
            s[k].ch = a[i].ch;
        }
        s[k].cnt += a[i].cnt;
    }
    int l = 1,r = n;
    while(l < r)
    {
        if(s[l].cnt == 0) l++;
        if(s[r].cnt == 0) r--;
        if(s[l].ch == s[r].ch)
        {
            if(s[l].cnt >= s[r].cnt)
            {
                s[l].cnt -= s[r].cnt;
                s[r].cnt = 0;
            }
            else
            {
                s[r].cnt -= s[l].cnt;
                s[l].cnt = 0;
            }
        }
        else
        {
            if(s[l].cnt >= s[r].cnt)
            {
                ans += s[r].cnt;
                s[l].cnt -= s[r].cnt;
                s[r].cnt = 0;
            }
            else
            {
                ans += s[l].cnt;
                s[r].cnt -= s[l].cnt;
                s[l].cnt = 0;
            }
        }
    }
    cout << ans;
    return 0;
}
