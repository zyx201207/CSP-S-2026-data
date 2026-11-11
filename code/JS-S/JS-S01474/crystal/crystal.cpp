#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=5e5+10;
int n,m;
int a[N];
int s[N];
int q[N];
signed main()
{
    freopen( "crystal.in" , "r" , stdin);
    freopen( "crystal.out" , "w" , stdout);

    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
         cin>>a[i];
         s[i-1]=a[i]-a[i-1];
    }
    sort(a+1,a+n+1);
    for(int i=1;i<=n;i++)
        q[i]=s[i-1]*2+s[i];
    for(int i=n;i>=1;i--)
        if(q[i]<=m)
        {
            cout<<i;
            return 0;
        }
    puts("1");
    return 0;
}
