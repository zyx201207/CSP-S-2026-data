#include <bits/stdc++.h>
using namespace std;
int n,m,a[500001],c[300001];
bool b[500001],d;
int main()
{
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    for (int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    for (int i=1;i<=n;i++)
    {
        for (int j=i;j<=n;j++)
        {
            for (int k=i;k<j;k++)
            {
                if (a[j]==a[k] && !b[k])
                {
                    for (int l=k;l<j;l++)
                    {
                        c[a[l]]--;
                        b[l]=true;
                    }
                    break;
                }
            }
            for (int k=i+1;k<=n;k++)
            {
                b[k]=false;
            }
            c[a[j]]++;
        }
    }
    for (int i=1;i<=m;i++)
    {
        cout<<c[i]<<" ";
    }
    fclose();
    fclose();
    return 0;
}
