#include <bits/stdc++.h>
using namespace std;
int a[10008];

int main()
{
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    ios::sync_with_stdio(false);
    long long n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        cin >> a[i];
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=i;j<=n;j++)
        {
            for(int t=j-1;t>=1;t--)
            {
                if(a[j]==a[t])
                {
                    if(a[t]==0) return 0;
                    for(int l=t+1;l<=n;l++)
                    {
                        a[l]=0;
                    }
                }
            }

        }
    }
    return 0;
}
