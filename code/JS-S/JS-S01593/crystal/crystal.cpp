#include<bits/stdc++.h>
using namespace std;
#define int long long
#define itn long long
#define pii pair<int,int>
int fread()
{
    int fh = 1,res = 0;
    char c = getchar();
    while(c == '\n' || c == ' ' || c == '\r' || c == '\t') c = getchar();
    while(c == '-') fh = -fh,c = getchar();
    while(c >= '0' && c <= '9') res = res * 10 + (c - '0'),c = getchar();
    return fh * res;
}
void fwrite(int _a)
{
    char _c[64];
    int cnt = 0;
    if(_a == 0)
    {
        putchar('0');
        return;
    }
    if(_a < 0)
    {
        putchar('-');
        _a = -_a;
    }
    while(_a)
    {
        _c[cnt] = _a % 10 + '0';
        _a /= 10;
        cnt++;
    }
    for(int i = cnt - 1;i >= 0;i--)
    {
        putchar(_c[i]);
    }
}
const int N = 5e5+5;
int n,a[N];
int m,ans = 0;
int sum[N];
bool check(int k,int i)
{
    int nd = (i - k + 1) * a[i] - (sum[i] - sum[k - 1]);
    return nd <= m;
}
signed main()
{
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    n = fread(),m = fread();
    for(int i = 1;i <= n;i++) a[i] = fread();
    sort(a+1,a+n+1);
    int l = a[1],r = a[n];
    for(int i = 1;i <= n;i++) sum[i] =sum[i - 1]+a[i];
    for(int i = 1;i <= n;i++)
    {
        int lft = 1,rgt = i-1;
        int lsans = i;
        while(lft <= rgt)
        {
            int mid = lft + rgt >> 1;
            if(check(mid,i))
            {
                lsans = min(lsans,mid);
                rgt = mid - 1;
            }
            else
            {
                lft = mid + 1;
            }
        }
        ans = max(ans,i - lsans + 1);
    }
    fwrite(ans);
    putchar('\n');
    return 0;
}