#include <bits/stdc++.h>

using namespace std;

int n,m;
int a[200005];
int sum;

int main()
{
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    int maxn=0;
    for (int i=1;i<=n;i++)
    {
        cin>>a[i];
        maxn=max(maxn,a[i]);
        if(i==1)
        {
            sum=a[i];
        }
        sum=sum&a[i];
    }
    if(m==n-1)
    {
        int ans=0;
        for (int i=1;i<=n;i++)
        {
            if(sum&(a[i]^((1<<32)-1))>ans)
            {
                sum=sum&~a[i];
            }
        }
        cout<<ans;
    }
    else
        cout<<max(maxn,sum);
    return 0;
}
