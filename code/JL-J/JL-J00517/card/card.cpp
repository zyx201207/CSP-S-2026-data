#include<bits/stdc++.h>
using namespace std;
int m,n;
int a[500010],b[500010],c[500010];
int main()
{
    cin>>n>>m;
    for(int i=1;i<=n;i++)
        cin>>a[i];
    for(int i=1;i<=n;i++)
    {
        for(int j=i;j<=n;j++)
        {
            for(int k=i;k<=j;k++)
            {
                if(b[k]==a[j])
                {
                    for(int p=k;p<=n;p++)
                        b[p]=0;
                }

            }
            b[j]=a[j];
        }
        for(int j=i;j<=n;j++)
            cout<<b[j]<<" ";
        cout<<endl;
        for(int j=1;j<=m;j++)
        {
            for(int k=i;k<=n;k++)
            {
                if(b[k]==j)
                {
                    c[j]++;
                    break;
                }

            }
        }
        for(int p=1;p<=n;p++)
            b[p]=0;
    }
    for(int i=1;i<=m;i++)
        cout<<c[i]<<" ";

    return 0;
}
