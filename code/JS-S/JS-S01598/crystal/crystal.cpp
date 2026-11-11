#include <bits/stdc++.h>
using namespace std;

int sum[500005];
int a[500005];

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    int n,m;
    cin>>n>>m;
    bool f=1;
    int cnt=0;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        if(i==2)
        {
            cnt=a[2]-a[1];
        }
        if(i>=2&&a[i]-a[i-1]!=cnt)
        {
            f=0;
        }
    }
    if(f==1)
    {
        for(int i=1;i<n;i++)
        {
            if(i==1)
            {
                sum[i]=cnt;
            }
            else
            {
                sum[i]=sum[i-1]+cnt*i;
            }
        }
        for(int i=1;i<n;i++)
        {
            if(m<cnt)
            {
                cout<<1;
                return 0;
            }
            else
            {
                if(m<sum[i])
                {
                    cout<<i;
                    return 0;
                }
            }
        }
        cout<<n;
    }
    return 0;
}
