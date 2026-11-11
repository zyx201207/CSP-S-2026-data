#include<bits/stdc++.h>
using namespace std;
int n,m,a[510000],p[510000],c[510000];
int main()
{
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++)
        cin>>a[i];

    for(int i=1;i<=n;i++)
    {
        int zuiyou=0;
        for(int j=i;j<=n;j++)
        {
            int f=0,xb;
            for(int e=zuiyou;e>=1;e--)
                if(a[j]==p[e])
                {
                    f=1;
                    xb=e;
                }
            if(f==0)
            {
                zuiyou++;
                p[zuiyou]=a[j];

            }
            else if(f==1)
            {
                for(int e=xb;e<=zuiyou;e++)
                    p[e]=0;
                zuiyou=xb;
                p[zuiyou]=a[j];
            }
        }

        for(int e=1;e<=zuiyou;e++)
            c[p[e]]++;
    }
    for(int i=1;i<=m;i++)
        cout<<c[i]<<' ';
    return 0;
}
