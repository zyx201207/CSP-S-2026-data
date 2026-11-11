#include <bits/stdc++.h>
#define int long long
using namespace std;
int a[200010];
bool b[200010];
int c[21];
int cnt=0;
int n,m;
void dfs(int num,int dep,int last)
{
    if(dep==m)
    {
        c[++cnt]=num;
        return;
    }
    int ma=INT_MIN;
    int t=1;
    b[last]=1;
    for(int i=1;i<=n;i++)
    {
        if(!b[i]&&(num&a[i])>ma)
        {
            ma=a[i]&num;
            t=i;
        }
    }
    dfs(ma,dep+1,t);
    b[last]=0;
}
bool check(int x)
{
    while(x>0)
    {
        if(x%2==0)
        {
            return 0;
        }
        else
        {
            x/=2;
        }
    }
    return 1;
}
void solve()
{
    cout << a[m];
}
signed main()
{
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin >> n >> m;
    bool p=1;
    for(int i=1;i<=n;i++)
    {
        cin >> a[i];
        if(p==1&&!check(a[i]))
        {
            p=0;
        }
    }
    //cout << p << endl;
    if(p)
    {
        sort(a+1,a+1+n,greater<int>());
        solve();
        return 0;
    }
    sort(a+1,a+1+n,greater<int>());
    for(int i=1;i<=min(n,5LL);i++)//time is money!!!
    {
        dfs(a[i],1,i);
    }
    int ma=INT_MIN;
    for(int i=1;i<=cnt;i++)
    {
        ma=max(ma,c[i]);
    }
    cout << ma;
    return 0;
}