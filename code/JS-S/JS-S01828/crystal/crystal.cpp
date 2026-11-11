#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=5e5+5;
int n,m;
int a[N],q[N];
inline bool check(int num)
{
    for(int i=1,j=num; j<=n; i++,j++)
        if(a[j]*num-(q[j]-q[i-1])<=m)
            return true;
    return false;
}
signed main()
{
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n>>m;
    for(int i=1; i<=n; i++)
        cin>>a[i];
    sort(a+1,a+1+n);
    for(int i=1; i<=n; i++)
        q[i]=q[i-1]+a[i];
    int l=1,r=n;
    while(r>=l)
    {
        int mid=(l+r)>>1;
        if(check(mid))
            l=mid+1;
        else
            r=mid-1;
    }
    cout<<r;
    return 0;
}
