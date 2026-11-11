#include<bits/stdc++.h>
using namespace std;
int n,m;
int  a[10000005];
void agd(int x)
{
    int cnt=0;
    while(x)
    {
        agd[cnt]+=x/2;
        x/=2;
        cnt++;
    }
}
int main()
{
    freopen("and.in","r",stdin);
    freopen("and .out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    if(n==1)
    {
        for(int i=1;i<=;i++)
        {
            ans=max(ans,a[i]);

        }
        cout<<ans;
    }
    else if(m==n)
    {
        ans=a[i];
        for(int i=1;i<=n;i++)
        {
            ans=a[1];
            for(int i=2;i<=n;i++)
            {

            }
        }
    }
    return 0;
}
