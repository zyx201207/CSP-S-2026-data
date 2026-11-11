#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500005],d[500005],s[500005];
long long cal(int x,int y)
{
    int sum=0;
    for(int i=1;i<=y;i++)
    {
        sum+=a[x]-a[i];
    }
    return sum;
}
bool check(int x)
{
    for(int i=x;i<=n;i++)
    {
        if((s[i]-cal(i,i-x))<=m) return 1;
    }
    return 0;
}
int main()
{
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin >> n >> m;
    for(int i=1;i<=n;i++)
    {
        cin >> a[i];
    }
    sort(a+1,a+n+1);
    for(int i=1;i<=n;i++)
    {
        d[i]=(a[i]-a[i-1])*(i-1);
        s[i]=s[i-1]+d[i];
    }
    int ans=1;
    for(int i=2;i<=n;i++)
    {
        if(!check(i)) break;
        ans++;
    }
    cout << ans;
    return 0;
}
