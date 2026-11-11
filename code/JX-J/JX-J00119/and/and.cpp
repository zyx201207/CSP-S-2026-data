#include<bits/stdc++.h>
using namespace std;
int n,m;
long long a[200005],ans;
int main()
{
    freopen("and.in","r",stdin);
    freopen("ans.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        if(i==1) ans=a[1];
        else ans=ans&a[i];
    }
    sort(a+1,a+1+n);
    if(m==1)
    {
        cout<<a[n];
        return 0;
    }
    if(m==n)
    {
        cout<<ans;
        return 0;
    }
    if(m==2)
    {
        ans=0;
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=n;j++)
            {
                if(i==j)continue;
                ans=max(ans,a[i]&a[j]);
            }
        }
        cout<<ans;
        return 0;
    }
}
