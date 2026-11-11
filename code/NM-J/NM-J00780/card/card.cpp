#include <bits/stdc++.h>
using namespace std;
int main()
{
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    int m,n;
    cin>>n>>m;
    int a[n],cnt[n][2];
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    for(int i=n;i>=1;i--)
    {
        string b;
        for(int j=1;j<=i;j++)
        {
            b[j]=a[j];
            if(b[j]==b[j-1]||b[j]==b[j-2]||b[j]==b[j-3])
            {
                b=b[j];
            }
        }

    }
    return 0;
}
