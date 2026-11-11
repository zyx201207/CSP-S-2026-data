#include <bits/stdc++.h>
using namespace std;
const int N = 5e5+10;
typedef long long ll;
ll a[N], d[N];
ll sum[N];
ll m;
void slove()
{
    int n;
    cin>>n>>m;
    for(int i = 1; i<=n; i++)
    {
        cin>>a[i];
    }
    sort(a+1,a+1+n);
    for(int i = 1; i<=n; i++)
    {
        sum[i]=sum[i-1]+a[i];
    }
    int res = 1;
    for(int i = n,j=n; i>=1; i--)
    {
        while((j-i)*a[j]-(sum[j-1]-sum[i-1])>m) j--;
        res=max(res,j-i+1);
    }
    cout<<res<<endl;
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    if(true)
    {
        freopen("crystal.in",  "r", stdin);
        freopen("crystal.out", "w", stdout);
    }
    int t = 1;
//    cin>>t;
    while(t--)
    {
        slove();
    }
    return 0;
}
