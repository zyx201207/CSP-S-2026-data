#include <bits/stdc++.h>
//#define int long long
using namespace std;
inline int read()
{
    int x=0,f=1;char c=getchar();
    while ((c<'0' && c>'9') && c!='-') c=getchar();
    if (c=='-') f=-1;
    while (c>='0' && c<='9' || c=='-') x=(x<<1)+(x<<3)+c-48,c=getchar();
    return f*x;
}
void put(int x)
{
    if (!x) return;
    put(x/10);
    putchar(x%10+48);
    return;
}
void write(int x)
{
    if (!x) putchar('0');
    else if (x<0) putchar('-'),put(-x);
    else put(x);
    return;
}
signed main()
{
    freopen(".in","r",stdin);
    freopen(".out","w",stdout);
    ios::sync_with_stdio(0);
    return 0;
}
