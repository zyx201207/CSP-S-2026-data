#include<bits/stdc++.h>
using namespace std;
const int N=2*(1e5+7);
int n,m,a[N],sum,ans=-1;
int main()
{
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++)
        cin>>a[i];
    if(m==1)
    {
        sort(a+1,a+1+n);
        cout<<a[n];
        return 0;
    }
    else if(m==2)
    {
        for(int i=1;i<=n;i++)
        {
            for(int j=i+1;j<=n;j++)
            {
                sum=a[i]&a[j];
                ans=max(sum,ans);
            }
        }
        cout<<ans;
        return 0;
    }
    else if(m==n)
    {
        sum=a[1];
        for(int i=2;i<=n;i++)
            sum&=a[i];
        cout<<sum;
        return 0;
    }
    return 0;
}
