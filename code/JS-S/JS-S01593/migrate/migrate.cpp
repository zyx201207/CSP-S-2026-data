#include<bits/stdc++.h>
using namespace std;
#define int __int128
#define itn int
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
const int N = 2e6+5;
int n,a[N],d;
bool syz[N];
int tree[N];
void update(int x,int val)
{
    tree[x] += val;
    x += (x &(-x));
    if(x <= n) update(x,val);
}
int find(int x)
{
    int res = tree[x];
    x -= (x & (-x));
    if(x > 0)
    {
        res += find(x);
    }
    return res;
}
void mian()
{
    n = fread(),d = fread();
    for(int i = 1;i <= n;i++)
    {
        a[i] = fread();
    }
    memset(syz,false,sizeof syz);
    memset(tree,0,sizeof tree);
    // memset(a,0,sizeof a);
    for(int i = 1;i <= n - 3;i++)
    {
        if(a[i+3]-a[i] <= d) continue;
        if(a[i+2]-a[i] > d || a[i+3]-a[i+1] > d) continue;
        syz[i] = true;
        update(i,1);
    }
    int ans = 0;
    for(int i = 3;i <= n;i++)
    {
        for( int j = i-3;j > 0;j--)
        {
            if(find(i - 3) - find(j- 1) == 1) ans++;
            if(find(i-3)-find(j-1) > 1) break;
        }
    }
    // for(int i = 1;i <= n;i++) cout << tree[i] << ' ' << find(i) << '\n';
    fwrite(ans);
    putchar('\n');
}
signed main()
{
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    int c =fread(),t = fread();
    while(t--)
    {
        mian();
    }
}