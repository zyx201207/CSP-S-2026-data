#include<bits/stdc++.h>
using namespace std;
long long m,n,a[1000010],b[1000010],cnt[1000010];
int main()
{
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    for(int i=0;i<n;i++)
    {
        for(int j=i;j<n;j++)
        {
            b[j]=a[j];
            for(int k=i;k<j;k++)
            {
                if(a[k]==b[j])
                {
                    for(int c=k;c<j;c++)
                    {
                        b[c]=0;
                    }
                }
            }
        }
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;i++)
            {
                if(b[j]==i+1)
                {
                    cnt[i]++;
                }
            }
        }
    }
    for(int i=0;i<m;i++)
    {
        cout<<cnt[i]<<" ";
    }
    return 0;
}
