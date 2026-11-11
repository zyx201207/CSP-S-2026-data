#include <bits/stdc++.h>
using namespace std;
int n,m;
long long a[200005],maxn;
int main()
{
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin >> n >> m;
    for (int i=1;i<=n;i++)
    {
        cin >> a[i];
    }
    if(m==2){
        for (int i=1;i<=n;i++)
        {
            for (int j=i+1;j<=n;j++)
            {
                maxn=max(maxn,a[i]&a[j]);
            }
        }
    }else if(m==3){
        for (int i=1;i<=n;i++)
        {
            for (int j=i+1;j<=n;j++)
            {
                for (int l=j+1;l<=n;l++)
                {
                    maxn=max(maxn,a[i]&a[j]&a[l]);
                }
            }
        }

    }else if(m==4){
        for (int i=1;i<=n;i++)
        {
            for (int j=i+1;j<=n;j++)
            {
                for (int l=j+1;l<=n;l++)
                {
                    for(int h=l+1;h<=n;h++)
                    {
                        maxn=max(maxn,a[i]&a[j]&a[l]&a[h]);
                    }
                }
            }
        }

    }else if(m==1){
        for (int j=1;j<=n;j++)
            {
                maxn=max(maxn,a[j]);
            }
    }else if(m==n){
        maxn=a[1];
        for (int j=1;j<=n;j++)
            {
                maxn=maxn&a[j];
            }
    }
    cout << maxn;
    return 0;
}
