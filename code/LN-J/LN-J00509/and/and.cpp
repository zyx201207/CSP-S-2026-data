#include <bits/stdc++.h>
using namespace std;
int a[200005];
int main()
{
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    int n,m,maa=0;
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        maa=max(maa,a[i]);
    }
    int y=a[1];
    if(m==1) cout<<maa;
    else if(m==n)
    {
        for(int i=2;i<=n;i++)
        {
            y&=a[i];
        }
        cout<<y;
    }
    else
    {
        int maa2=0;
        for(int i=1;i<n;i++)
        {
            for(int j=i+1;j<=n;j++)
            {
                maa2=max(maa2,a[i]&a[j]);
            }
        }
        cout<<maa2;
    }
}
