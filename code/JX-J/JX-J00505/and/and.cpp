#include <bits/stdc++.h>
using namespace std;
int n,m;
long long  a[300005];
struct ss
{
    int num,s;
}b[300005];
bool cmp(ss x,ss y)
{

    return x.s>y.s;
}
long long  dp[300005];
int main()
{
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin >>n >>m;
    for (int i = 1;i <= n;i++)
    {
        cin >> a[i];
        int x = a[i];
        b[i].s = i;
        while(x)
        {
            if(x&1)
                b[i].num++;
            x = x<<1;
        }
    }
    sort(a+1,a+n+1);
    sort(b+1,b+300005,cmp);
    int sum =0;
    for (int i = n;i >= 1;i--)
        sum ^=a[i];
    cout << sum  <<"\n";
    return 0;
}
