#include<bits/stdc++.h>
using namespace std;
int a[500006];
int mm[300005];
int main()
{
    freopen("card.in","r",stdin);
    freopen("card,out","w",stdout);
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    for(int k=1;k<=n;k++)
    {
        int t=a[k];
        int b;
        while(b!=n)
        {
            for(int i=n;i>=1;i--)
            {
                if(t==a[i])
                {
                    b=i;
                    mm[a[i]]++;
                    if(b!=n)
                    {
                        t=a[b+1];
                    }
                    else break;
                }
            }
        }
    }
    for(int i=1;i<=m;i++)
    {
        cout<<mm[i]<<" ";
    }
    return 0;
}
