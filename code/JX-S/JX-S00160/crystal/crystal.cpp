#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    long long n,m,a[500010];
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    sort(a+1,a+n+1);
    for(int i=n;i>=1;i--)
    {
        long long cnt=0;
        for(int j=1;j<=i-1;j++)
        {
            cnt+=a[i]-a[j];
        }
        if(cnt<=m)
        {
            cout<<i<<endl;
            return 0;
        }
    }
    return 0;
}
