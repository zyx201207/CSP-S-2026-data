#include <bits/stdc++.h>
using namespace std;
int main()
{
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    long long n,m,a[200005],b[5000],ans=0;
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            if(a[j]==0) continue;
            b[a[i+j-1]]++;
            if(b[a[i+j-1]]==2)
            {
                int l=1;
                while(1)
                {
                    b[a[i+j-1-l]]--;
                    if(b[a[i+j-1-l]]==b[a[i+j-1]]) break;
                }
            }
        }
        int c=0;
        for(int j=1;j<=m;j++)
        {
            if(b[j]==1) c++;
        }
        cout<<c;
    }
    return 0;
}
