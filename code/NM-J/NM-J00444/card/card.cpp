#include<iostream>
using namespace std;
int main()
{
    freopen("card.in","r",instd);
    freopen("card.out","w",outstd);
    int m,n,i,j,k,true;
    int a[99999],b[99999],c[99999];
    cin>>n>>m;
    for(i=1;i<=n;i++)
        cin>>a[i];
    for(i=1;i<=n;i++)
    {
        for(j=i;j<=n;j++)
        {
            true=0;
            for(k=i;k<=j,k++)
                if(a[j]==b[k])
                    true=k;
            if(true!=0)
            {
                for(k=true;k<=j;k++)
                    b[k]=0;
                b[true]=a[j];
            }
            else
                b[j]=a[j];
        }
        for(j=1;j<=m;j++)
            c[j]=0;
            for(k=i;k<=n;k++)
                if(b[k]==j)
                    c[j]++;
        for(j=1;j<=n;j++)
            b[j]=0;
    }
    for(i=1;i<=m;i++)
        cou<<c[i]<<" ";
}
