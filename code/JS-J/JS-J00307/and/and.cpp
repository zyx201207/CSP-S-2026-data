#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N=200005;
int n,m;
int a[N];
int maxn=0;
void solve1()
{
    int maxn=0;
    for (int i=1;i<=n;i++) maxn=max(maxn,a[i]);
    cout<<maxn;
}

void solve2()
{
    int x=a[1];
    for (int i=2;i<=n;i++) x&=a[i];
    cout<<x;
}

void solve3()
{
    int maxn=0;
    for (int i=1;i<n;i++) for (int j=i+1;j<=n;j++) maxn=max(maxn,a[i]&a[j]);
    cout<<maxn;
}

signed main()
{
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin>>n>>m;
    for (int i=1;i<=n;i++) cin>>a[i];
    if (m==1) solve1();
    else if (m==n) solve2();
    else if (m==2) solve3();
    return 0;
}
