#include<bits/stdc++.h>;
using namespace std;
long long a[50005];
int main( )
{
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    long long n,m,s=0;
    cin>>n>>m;
    for(long long i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    sort(a+1,a+n+1);
    for(long long i=1;i<=n;i++)
    {
        s=0;
        for(long long j=1;j<=i;j++)
        {
            s=s+a[i]-a[j];
        }
        if(s>m)
        {
            cout<<i-1;
            return 0;
        }
    }
    return 0;
}
