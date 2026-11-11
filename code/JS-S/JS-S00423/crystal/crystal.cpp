#include <bits/stdc++.h>
using namespace std;
#define FIO(filename) freopen(filename".in","r",stdin);freopen(filename".out","w",stdout);
#define getchar() p1 == p2 && (p2 = (p1 = buf) + fread(buf, 1, 1000000, stdin), p1 == p2) ? EOF : *p1++
char buf[1000000], *p1 = buf, *p2 = buf;
template <typename T>
void read(T &x)
{
    x = 0;
    int f = 1;
    char c = getchar();
    for (; c < '0' || c > '9'; c = getchar())
        if (c == '-')
            f = -f;
    for (; c >= '0' && c <= '9'; c = getchar())
        x = x * 10 + (c ^ '0');
    x *= f;
}
template <typename T, typename... Args>
void read(T &x, Args &...y)
{
    read(x);
    read(y...);
}
template <typename T>
void chkmx(T &x,T y){x=max(x,y);}
using ll = long long;
int n;
ll m;
ll a[500020];
ll s[500020];
int ans;
int main()
{
    FIO("crystal");
    read(n,m);
    for(int i=1;i<=n;i++)read(a[i]);
    sort(a+1,a+n+1);
    for(int i=1;i<=n;i++)
        s[i]=s[i-1]+a[i];
    for(int i=1;i<=n;i++)
    {
        /*
        s[i] - s[l] <= m
        s[l] >= s[i] - m
        */
        // int j=lower_bound(s,s+i,s[i]-m)-s;
        // chkmx(ans,i-j);
        int l=1,r=i,j=i;
        while(l<=r)
        {
            int mid=l+r>>1;
            if(a[i]*(i-mid+1)-(s[i]-s[mid-1])<=m)
                r=(j=mid)-1;
            else
                l=mid+1;
        }
        chkmx(ans,i-j+1);
    }
    cout<<ans<<'\n';
    return 0;
}