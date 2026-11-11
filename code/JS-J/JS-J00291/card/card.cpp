#include<bits/stdc++.h>
using namespace std;
int m,n,a[500011],b[500011],top,ans[300011];
int main()
{
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    for(int i=1;i<=m;i++)
    {
        ans[i]=0;
    }
    if(n>500)
    {
        for(int i=1;i<=n;i++)
        {
            ans[a[i]]++;
        }
        cout<<ans[1]<<" ";
        for(int i=2;i<=m;i++)
        {
            ans[i]+=ans[i-1];
            cout<<ans[i]<<" ";
        }
        return 0;
    }
    for(int i=1;i<=n;i++)
    {
        top=0;
        for(int j=i;j<=n;j++)
        {
            for(int s=top;s>=1;s--)
            {
                if(b[s]==a[j])
                {
                    top=s-1;
                    break;
                }
            }
            top++;
            b[top]=a[j];
        }
        for(int j=1;j<=top;j++)
        {
            ans[b[j]]++;
        }
    }
    for(int i=1;i<=m;i++)
    {
        cout<<ans[i]<<" ";
    }
    return 0;
}
