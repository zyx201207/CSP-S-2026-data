#include <bits/stdc++.h>
using namespace std;
long long n,m,a[500005],an=1;
int main()
{
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for (int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    sort(a+1,a+1+n);
    for (int i=2;i<=n;i++)
    {
        long long cnt=1,sum=m,x;
        for (int j=i-1;j>=1;j--)
        {
            x=a[i]-a[j];
            if (x<=sum)
            {
                sum-=x;
                cnt++;
            }
        }
        an=max(an,cnt);
    }
    cout<<an;
    return 0;
}
