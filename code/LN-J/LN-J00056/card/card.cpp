#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n,m,a[50005],sum=0;
    int p=0;
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    for(int i=1;i<=m;i++)
    {
        p=0;
        sum=0;
        for(int j=1;j<=n;j++)
        {
            if(a[j]==i)
                p=1-p;
            if(p)
            {
                sum++;
            }
        }
        cout<<sum<<endl;
    }
}
