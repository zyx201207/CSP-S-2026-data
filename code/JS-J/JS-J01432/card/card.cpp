#include<bits/stdc++.h>
using namespace std;
int n,m,a[500001],b[500001],ans[300001];
struct str
{
    bool t=1;
    int p;
}c[300001];
int main()
{
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    for(int i=1;i<=n;i++)
    {
        for(int l=i;l<=n;l++)
        {
            b[l]=a[l];
            if(c[b[l]].t)
            {
                c[b[l]].t=0;
                c[b[l]].p=l;
            }
            else
            {
                for(int j=c[b[l]].p;j<l;j++)
                {
                    c[b[j]].t=1;
                    b[j]=0;
                }
                c[b[l]].t=0;
                c[b[l]].p=l;
            }
        }
        for(int l=i;l<=n;l++)
        {
            cout<<b[l];
            ans[b[l]]++;
        }
        cout<<endl;
    }
    for(int i=1;i<=m;i++)
    {
        cout<<ans[i]<<" ";
    }
    return 0;
}
