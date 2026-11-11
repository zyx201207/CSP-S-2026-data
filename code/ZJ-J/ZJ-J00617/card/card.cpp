#include<bits/stdc++.h>
using namespace std;
int n,m,a[500010];
int main()
{
    //文件读写
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    //读入数据
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    int c[300010];
    for(int i=1;i<=n;i++)
    {
        int b[500010],sum=n;
        for(int j=1;j<=sum;j++)
        {
            b[j]=a[j];
        }
        for(int j=i;j<=sum;j++)
        {
            for(int k=1;k<=sum;k++)
            {
                if(b[k]==b[j])
                { 
                    for(int l=k+1;l<=n;l++)
                    {
                        b[l]=0;
                    }
                }
            }
        }
        
    }
    return 0;
}