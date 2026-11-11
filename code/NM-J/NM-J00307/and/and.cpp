#include <bits/stdc++.h>
using namespace std;

int main()
{
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    int n,m,a[100005],maxx=-1,ans=0;
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    for(int i=1;i<=n;i++)
    {
        ans=a[i];
        for(int j=1;j<m;j++)
        {
            for(int k=i+1;k<=n;k++)
            {
                if(maxx<(ans&a[j+k]))
                {
                    maxx=(ans&a[j+k]);
                }
            }
        }
    }
    cout<<maxx;
    return 0;
}
